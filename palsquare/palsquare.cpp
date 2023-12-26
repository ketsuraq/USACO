#include <bits/stdc++.h>
using namespace std;

string generateNumber(int a, int base) {
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    vector<char> number;
    while (a > 0){
        int remainder =  a % base;
        if (remainder > 9){
            number.push_back(letters[remainder - 10]);
        } else {
            number.push_back('0' + remainder);
        }
        a /= base;
    }
    reverse(number.begin(), number.end());
    string num = "";
    for (int i = 0; i < number.size(); i++){
        num += number[i];
    }
    return num;
}

bool checkValidity(string a){
    if (a.length() <= 1) {
        return true;
    } else if (a[0] == a[a.length() - 1]){
        return checkValidity(a.substr(1, a.length() - 2));
    } else {
        return false;
    }
    return true;
}

int main()
{
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    int base;
    fin >> base;

    for (int i = 1; i <= 300; i++){
        int square = i * i;
        string iBase = to_string(i);
        string squareBase = to_string(square);
        if (base != 10){
            iBase = generateNumber(i, base);
            squareBase = generateNumber(square, base);
        }
        if (checkValidity(squareBase)) {
            fout << iBase << " " << squareBase << endl;
        }
    }
    return 0;
}
