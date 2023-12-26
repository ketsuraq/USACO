#include <bits/stdc++.h>
using namespace std;

string baseConvert(int a, int base) {
    vector<char> letters;

    while (a > 0) {
        int remainder = a % base;
        letters.push_back('0' + remainder);
        a /= base;
    }
    reverse(letters.begin(), letters.end());

    string number = "";
    for (int i = 0; i < letters.size(); i++){
        number += letters[i];
    }
    return number;
}

bool checkValidity(string a) {
    if (a.length() <= 1) {
        return true;
    } else if (a[0] == a[a.length() - 1]) {
        return checkValidity(a.substr(1, a.length() - 2));
    } else {
        return false;
    }
    return true;
}

bool countInstances(int a) {
    int counter = 0;
    for (int i = 2; i <= 10; i++){
        string number = baseConvert(a, i);
        if (checkValidity(number)) {
            counter++;
            if (counter >= 2) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

    int quantity, biggerThan;
    fin >> quantity >> biggerThan;

    int current = biggerThan + 1;
    while (quantity > 0){
        if (countInstances(current)) {
            fout << current << endl;
            quantity--;
        }
        current++;
    }
    return 0;
}
