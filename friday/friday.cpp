/*
ID: rusijos1
PROG: friday
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    int yearCount;
    fin >> yearCount;

    int inicialYear = 1900;
    int weekDay = 0;
    int monthDays;
    vector<int> V(7, 0);

    for (int i = inicialYear; i < inicialYear + yearCount; i++){
        for (int month = 1; month <= 12; month++){
            if (month == 4 || month == 6 || month == 9 || month == 11){
                monthDays = 30;
            } else if (month == 2){
                if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)){
                    monthDays = 29;
                } else {
                    monthDays = 28;
                }
            } else {
                monthDays = 31;
            }
            for (int day = 1; day <= monthDays; day++){
                if (day == 13){
                    V[weekDay]++;
                }
                weekDay++;
                weekDay = weekDay % 7;
            }
        }
    }

    fout << V[5] << " " << V[6] << " ";
    for (int i = 0; i < 5; i++){
        fout << V[i];
        if (i < 4){
            fout << " ";
        }
    }
    fout << "\n";

    return 0;
}