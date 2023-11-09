/*
ID: rusijos1
PROG: gift1
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("gift1.in");
	ofstream fout("gift1.out");
    cout << "miau";

    int NP;
    fin >> NP;
    unordered_map<string, int> M;
    vector<string> V(NP);
    for (int i = 0; i < NP; i++){
        fin >> V[i];
        M[V[i]] = 0;
    }
    int moneysum, namecount;
    string donator, donatee;

    int mod, div;
    for (int i = 0; i < NP; i++) {
        fin >> donator >> moneysum >> namecount;
        if (namecount == 0 || moneysum == 0) {
            continue;
        }
        mod = moneysum % namecount;
        div = moneysum / namecount;
        M[donator] = M[donator] - moneysum + mod;
        for (int j = 0; j < namecount; j++) {
            fin >> donatee;
            M[donatee] += div;
        }
    }
    for (int i = 0; i < V.size(); i++){
        fout << V[i] << " " << M[V[i]] << endl;
    }
    return 0;
}
