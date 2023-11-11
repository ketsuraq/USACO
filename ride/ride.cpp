/*
PROG: ride
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string comet, group;
    int sumC = 1, sumG = 1;
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    fin >> comet >> group;
    for (int i = 0; i < comet.length(); i++){
        sumC *= comet[i] - 'A' + 1;
    }
    for (int i = 0; i < group.length(); i++){
        sumG *= group[i] - 'A' + 1;
    }
    if (sumC % 47 == sumG % 47){
        fout << "GO\n";
    } else {
        fout << "STAY\n";
    }
    return 0;
}