#include <bits/stdc++.h>
using namespace std;

void generateCombinations(vector<int>& emptyVector, vector<int>& parentVector, int current, int maxLength){
    if (maxLength == 0) {
        emptyVector.push_back(current);
        return;
    }
    for (int i = 0; i < parentVector.size(); i++){
        int newNumber = current * 10 + parentVector[i];
        generateCombinations(emptyVector, parentVector, newNumber, maxLength - 1);
    }
}

void filterCombinations(set<int>& emptyVector, vector<int>& parentVector, vector<int>& dials, int maxDial){

    for (int i = 0; i < parentVector.size(); i++){
        int counter = 0;
        int simtai = parentVector[i] / 100;
        int desimtys = parentVector[i] % 100 / 10;
        int vienetai = parentVector[i] % 10;

        if (simtai >= dials[0] - 2 && simtai <= dials[0] + 2) {
            counter++;
        } else if (simtai == 1 && dials[0] == maxDial || simtai == 1 && dials[0] == maxDial - 1) {
            counter++;
        } else if (simtai == 2 && dials[0] == maxDial) {
            counter++;
        } else if (simtai == maxDial && dials[0] == 1 || simtai == maxDial && dials[0] == 2) {
            counter++;
        } else if (simtai == maxDial - 1 && dials[0] == 1) {
            counter++;
        }

        if (desimtys >= dials[1] - 2 && desimtys <= dials[1] + 2) {
            counter++;
        } else if (desimtys == 1 && dials[1] == maxDial || desimtys == 1 && dials[1] == maxDial - 1) {
            counter++;
        } else if (desimtys == 2 && dials[1] == maxDial) {
            counter++;
        } else if (desimtys == maxDial && dials[1] == 1 || desimtys == maxDial && dials[1] == 2) {
            counter++;
        } else if (desimtys == maxDial - 1 && dials[1] == 1) {
            counter++;
        }


        if (vienetai >= dials[2] - 2 && vienetai <= dials[2] + 2) {
            counter++;
        } else if (vienetai == 1 && dials[2] == maxDial || vienetai == 1 && dials[2] == maxDial - 1) {
            counter++;
        } else if (vienetai == 2 && dials[2] == maxDial) {
            counter++;
        } else if (vienetai == maxDial && dials[2] == 1 || vienetai == maxDial && dials[2] == 2) {
            counter++;
        } else if (vienetai == maxDial - 1 && dials[2] == 1) {
            counter++;
        }


        if (counter == 3) {
            emptyVector.insert(parentVector[i]);
        }
    }
}

int main()
{
    ifstream fin("combo.in");
    ofstream fout("combo.out");

    int maxDial;
    int farmer1, farmer2, farmer3;
    int master1, master2, master3;

    cin >> maxDial >> farmer1 >> farmer2 >> farmer3 >> master1 >> master2 >> master3;

    vector<int> farmer = {farmer1, farmer2, farmer3};
    vector<int> master = {master1, master2, master3};

    vector<int> allDials;
    for (int i = 1; i <= maxDial; i++){
        allDials.push_back(i);
    }

    vector<int> allCombinations;
    generateCombinations(allCombinations, allDials, 0, 3);


    set<int> possibleCombinations;
    filterCombinations(possibleCombinations, allCombinations, farmer, maxDial);
    filterCombinations(possibleCombinations, allCombinations, master, maxDial);

    cout << possibleCombinations.size() << endl;
    return 0;
}
