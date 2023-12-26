#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("milk.in");
    ofstream fout("milk.out");

    int milkNeeded, farmerCount;
    fin >> milkNeeded >> farmerCount;

    map<int, int> farmerMarket;

    for (int i = 0; i < farmerCount; i++){
        int cost, amount;
        fin >> cost >> amount;
        farmerMarket[cost] += amount;
    }
    if (milkNeeded == 0){
        fout << 0 << endl;
        return 0;
    }

    int i = 0;
    int money = 0;
    while (milkNeeded > 0) {
        int amount = farmerMarket[i];
        if (amount < milkNeeded) {
            milkNeeded -= amount;
            money += amount * i;
        } else {
            money+= milkNeeded * i;
            fout << money << endl;
            break;
        }
        i++;
    }
    return 0;
}
