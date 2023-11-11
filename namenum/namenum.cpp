/*
PROG: namenum
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

string serialNumber;
set<string> dictionary;

map<char, vector<char>> m;
vector<string> names;

void iterate(int i = 0, string s=""){
    if (i == serialNumber.length()){
        if (dictionary.find(s) != dictionary.end()){
            names.push_back(s);
        }
    }
    for (char id : m[serialNumber[i]]){
        iterate(i + 1, s + id);
    }
}

int main()
{
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    ifstream din("dict.txt");

    string word;
    while (din >> word){
        dictionary.insert(word);
    }

    m['2'] = {'A', 'B', 'C'};
    m['3'] = {'D', 'E', 'F'};
    m['4'] = {'G', 'H', 'I'};
    m['5'] = {'J', 'K', 'L'};
    m['6'] = {'M', 'N', 'O'};
    m['7'] = {'P', 'R', 'S'};
    m['8'] = {'T', 'U', 'V'};
    m['9'] = {'W', 'X', 'Y'};

    fin >> serialNumber;

    iterate();

    if (names.empty()){
        fout << "NONE\n";
        return 0;
    }

    for (int i = 0; i < names.size(); i++){
        fout << names[i] << "\n";
    }
    return 0;
}
