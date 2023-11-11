/*
PROG: beads
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    int beadCount;
    string beads;

    fin >> beadCount >> beads;

    beads = beads + beads;

    int color = 0;
    int maxCount = 0, currentCount = 0;
    char key1, key2;

    for (int i = 0; i < beadCount; i++){
        color = 0;
        currentCount = 0;
        for (int j = i; j < beads.length(); j++){
            if (beads[j] == 'w'){
                currentCount++;
                continue;
            }
            if (beads[j] != 'w' && color == 0){
                key1 = beads[j];
                color++;
            }
            if ((beads[j] != 'w' && beads[j] != key1) && color == 1){
                key2 = beads[j];
                color++;
            }
            if (color == 2 && (beads[j] != key2 && beads[j] != 'w')){
                color++;
                break;
            }
            currentCount++;
        }
        if (currentCount > maxCount){
            maxCount = currentCount;
        }
    }
    if (maxCount > beadCount){
        maxCount = beadCount;
    }
    fout << maxCount << "\n";

    return 0;
}