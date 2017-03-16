#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <utility>
#include <set>
#include <map>
#include <cctype>

#define FOR(i,n) for(long long int i=0; i<n; i++)
#define MP(a,b) make_pair(a,b)
#define PB(x) push_back(x)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())

#define COND(p,t,f) ((p)?(t):(f))

#define PI 3.14159265

using namespace std;
typedef long long int lint;
typedef unsigned long long int ulint;

string rr(string s) {
    string r = "";
    FOR(i,s.size()) {
        if (i==0) {
            r.PB(s[i]);
            continue;
        }
        if (s[i]!=r[r.size()-1]) r.PB(s[i]);
    }
    return r;
}

vector <int> gg(string s) {
    int g=0;
    vector<int> res;
    string r="";
    FOR(i,s.size()) {
        if (i==0) {
            r.PB(s[i]);
            g++;
            continue;
        }
        if (s[i]!=r[r.size()-1]) {
            res.PB(g);
            g=1;
            r="";
            r.PB(s[i]);
        }
        else g++;
    }
    res.PB(g);
    return res;
}

int main() {
    int T;
    cin >> T;
    FOR(t,T) {
        int N;
        cin >> N;
        vector <string> a(N);
        FOR(i,N) cin >> a[i];

        cout << "Case #" << t+1 << ": ";

        string f = rr(a[0]);
        bool b = false;
        FOR(i,N) {
            if (f!=rr(a[i])) {
                cout << "Fegla Won" << endl;
                b = true;
                break;
            }
        }
        if (b) continue;
        vector <vector <int> > gr;
        FOR(i,N) gr.PB(gg(a[i]));
/*
        FOR(i,N) {
            FOR(j,gr[0].size()) {
                cerr << gr[i][j] << " ";
            }
            cerr << endl;
        }
*/

        ulint res = 0;
        FOR(j,gr[0].size()) {
            int mn=200;
            int mx=0;
            FOR(i,N) {
                mn = min(mn,gr[i][j]);
                mx = max(mn,gr[i][j]);
            }
            int bst = 9999999;
            for(int k=mn; k<=mx; k++) {
                int cnt = 0;
                FOR(i,N) {
                    cnt+= abs(k-gr[i][j]);
                }
                bst = min(bst,cnt);
            }
            res += bst;
        }
        cout << res << endl;



    }

}
