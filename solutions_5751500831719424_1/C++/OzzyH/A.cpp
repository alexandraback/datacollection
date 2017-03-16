#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

int run_once(ifstream &fin) {
    int N; fin >> N;
    vector <string> V;
    vector <vector <int> > C;
    for (int i=0; i<N; i++) {
        string s; fin >> s;
        V.push_back(s);
        vector <int> vv;
        C.push_back(vv);
    }
    string stemp = "";
    char last = '-';
    for (int i=0; i<V[0].length(); i++) {
        if (V[0][i] == last) {
            C[0][C[0].size()-1]++;
            continue;
        }
        stemp.push_back(V[0][i]);
        last = V[0][i];
        C[0].push_back(1);
    }
    for (int i=1; i<N; i++) {
        string st = "";
        last = '-';
        for (int j=0; j<V[i].length(); j++) {
            if (V[i][j] == last) {
                C[i][C[i].size()-1]++;
                continue;
            }
            st.push_back(V[i][j]);
            last = V[i][j];
            C[i].push_back(1);
        }
        if (st.compare(stemp) != 0) return -1;
    }

    int res = 0;
    for (int i=0; i<C[0].size(); i++) {
        int mn = 100000000;
        for (int j=1; j<=100; j++) {
            int mvs = 0;
            for (int k=0; k<N; k++) {
                mvs += abs(C[k][i] - j);
            }
            mn = min(mvs, mn);
        }
        res += mn;
    }
    return res;
}

int main() {
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");
    int N;
    fin >> N;
    for (int i=0; i<N; i++) {
        fout << "Case #" << i+1 << ": ";
        int t = run_once(fin);
        if (t==-1) fout << "Fegla Won";
        else fout << t;
        fout << endl;
    }
    return 0;
}
