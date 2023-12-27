#include <bits/stdc++.h>
using namespace std;

void generateNumber(vector<int>& digits, vector<int>& emptyVector, int current, int maxLength) {
    if (maxLength == 0) {
        emptyVector.push_back(current);
        return;
    }

    for (int i = 0; i < digits.size(); i++) {
        int newNumber = current * 10 + digits[i];
        generateNumber(digits, emptyVector, newNumber, maxLength - 1);
    }
}

bool checkValidity(int a, vector<int>& digits) {
    while (a > 0) {
        int digit = a % 10;
        bool valid = false;
        for (int i = 0; i < digits.size(); i++) {
            if (digit == digits[i]){
                valid = true;
                break;
            }
        }
        if (!valid) {
            return false;
        }
        a /= 10;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

    int digitCount;
    fin >> digitCount;

    vector<int> digits;

    for (int i = 0; i < digitCount; i++){
        int digit;
        fin >> digit;

        digits.push_back(digit);
    }
    sort(digits.begin(), digits.end());

    vector<int> firstNumber, secondNumber;

    generateNumber(digits, firstNumber, 0, 3);
    generateNumber(digits, secondNumber, 0, 2);

    int validSum = 0;

    for (int i = 0; i < firstNumber.size(); i++){
        for (int j = 0; j < secondNumber.size(); j++){
            int product1 = firstNumber[i] * (secondNumber[j] % 10);
            int product2 = firstNumber[i] * (secondNumber[j] / 10);
            int product = firstNumber[i] * secondNumber[j];

            string pr1 = to_string(product1);
            string pr2 = to_string(product2);
            string pr = to_string(product);

            if (pr1.length() != 3 || pr2.length() != 3 || pr.length() != 4) {
                continue;
            } else {
                if (checkValidity(product1, digits) && checkValidity(product2, digits) && checkValidity(product, digits)) {
                    validSum++;
                }
            }
        }
    }

    fout << validSum << endl;
    return 0;
}
