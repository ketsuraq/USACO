/*
ID: rusijos1
PROG: milk2
LANG: C++14
*/
#include <bits/stdc++.h>

struct milking{
    int start;
    int finish;
};

using namespace std;

int main()
{
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    int N, minStart = 100000, maxFinish = 0;
    fin >> N;
    vector<milking> V(N);

    for (int i = 0; i < N; i++){
        fin >> V[i].start >> V[i].finish;
        if (V[i].start < minStart){
            minStart = V[i].start;
        }
        if (V[i].finish > maxFinish){
            maxFinish = V[i].finish;
        }
    }

    vector<int> working;
    vector<int> idle;
    bool W, I;
    int currentWorking = 0, currentIdle = 0;

    for (int i = minStart; i <= maxFinish; i++){
        W = false;
        for (int j = 0; j < V.size(); j++){
            if (V[j].start <= i && V[j].finish > i){
                W = true;
                break;
            }
        }
        if (W){
            currentWorking++;
            if (currentIdle != 0){
                idle.push_back(currentIdle);
            }
            currentIdle = 0;
        }
        if (!W){
            currentIdle++;
            if (currentWorking != 0){
                working.push_back(currentWorking);
            }
            currentWorking = 0;
        }
        if (i == maxFinish){
            working.push_back(currentWorking);
        }
    }

    int maxWorking = 0, maxIdle = 0;
    for (int i = 0; i < working.size(); i++){
        if (working[i] > maxWorking){
            maxWorking = working[i];
        }
    }
    for (int i = 0; i < idle.size(); i++){
        if (idle[i] > maxIdle){
            maxIdle = idle[i];
        }
    }
    fout << maxWorking << " " << maxIdle << "\n";

    return 0;
}
