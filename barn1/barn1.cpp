#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");

    int boardCount, stallCount, occupiedStallCount;
    fin >> boardCount >> stallCount >> occupiedStallCount;

    vector<int> occupiedStalls;

    for (int i = 0; i < occupiedStallCount; i++){
        int occupiedStallNumber;
        fin >> occupiedStallNumber;

        occupiedStalls.push_back(occupiedStallNumber);
    }
    sort(occupiedStalls.begin(), occupiedStalls.end());

    vector<int> differences;
    for (int i = 1; i < occupiedStalls.size(); i++) {
        int difference = occupiedStalls[i] - occupiedStalls[i - 1];
        if (difference > 1) {
            differences.push_back(difference - 1);
        }
    }
    sort(differences.begin(), differences.end());

    int sumUnoccupied = 0;

    if (differences.size() < boardCount) {
        fout << occupiedStallCount << endl;
        return 0;
    }

    for (int i = 0; i < differences.size() - boardCount + 1; i++){
        sumUnoccupied += differences[i];
    }

    fout << occupiedStalls.size() + sumUnoccupied << endl;
    return 0;
}
