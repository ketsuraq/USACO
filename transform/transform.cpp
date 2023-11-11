/*
PROG: transform
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

bool checkEquality(vector<string> a, vector<string> b){
    for (int i = 0; i < a.size(); i++){
        if (a[i] != b[i]){
            return false;
        }
    }
    return true;
}

vector<string> rotate90(vector<string> a, vector<string> b){
    string line;
    for (int i = 0; i < a.size(); i++){
        line = "";
        for (int j = a.size() - 1; j >= 0; j--){
            line += a[j][i];
        }
        b.push_back(line);
    }
    return b;
}

vector<string> reflectVertical(vector<string> a, vector<string> b){
    string line;
    for (int i = 0; i < a.size(); i++){
        line = "";
        for (int j = a.size() - 1; j >= 0; j--){
            line += a[i][j];
        }
        b.push_back(line);
    }
    return b;
}

vector<string> reflectHorizontal(vector<string> a, vector<string> b){
    for (int i = a.size() - 1; i >= 0; i--){
        b.push_back(a[i]);
    }
    return b;
}

int main()
{
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    int N;

    fin >> N;

    vector<string> original;
    vector<string> transformed;

    string line;
    for (int i = 0; i < N; i++){
        fin >> line;
        original.push_back(line);
    }
    for (int i = 0; i < N; i++){
        fin >> line;
        transformed.push_back(line);
    }

    vector<string> changed;
    bool equaled;

    //operation 90 degree rotation
    changed = rotate90(original, changed);
    equaled = checkEquality(changed, transformed);

    if (equaled) {
        fout << 1 << "\n";
        return 0;
    }

    //operation 180 rotation
    vector<string> changed2;
    changed2 = rotate90(changed, changed2);
    equaled = checkEquality(changed2, transformed);

    if (equaled) {
        fout << 2 << "\n";
        return 0;
    }

    //operation 270 rotation
    changed.clear();
    changed = rotate90(changed2, changed);
    equaled = checkEquality(changed2, transformed);

    if (equaled) {
        fout << 3 << "\n";
        return 0;
    }

    //operation reflection
    changed.clear();
    changed2.clear();
    changed = reflectVertical(original, changed);
    equaled = checkEquality(changed, transformed);

    if (equaled) {
        fout << 4 << "\n";
        return 0;
    }

    //operation combination
    changed.clear();
    changed2.clear();
    changed = reflectHorizontal(original, changed);
    equaled = checkEquality(changed, transformed);

    if (equaled) {
        fout << 5 << "\n";
        return 0;
    }

    changed2 = rotate90(changed, changed2);
    equaled = checkEquality(changed2, transformed);

    if (equaled) {
        fout << 5 << "\n";
        return 0;
    }

    changed.clear();
    changed = rotate90(changed2, changed);
    equaled = checkEquality(changed, transformed);

    if (equaled) {
        fout << 5 << "\n";
        return 0;
    }

    changed2.clear();
    changed2 = rotate90(changed, changed2);
    equaled = checkEquality(changed2, transformed);

    if (equaled) {
        fout << 5 << "\n";
        return 0;
    }

    //operation nothing
    if (original == transformed){
        fout << 6 << "\n";
        return 0;
    }

    //operation irrelevant
    fout << 7 << "\n";
    return 0;
}
