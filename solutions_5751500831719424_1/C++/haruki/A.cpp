#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define rep(i,n) for (int i = 0; i < int(n); i++)

int main() {
    int T; cin >> T;
    rep (test, T) {
        cout << "Case #" << test+1 << ": ";
        int N; cin >> N;
        string s[100], t[100];
        rep (i,N) {
            cin >> s[i];
            t[i] = s[i];
            s[i].erase(unique(s[i].begin(), s[i].end()), s[i].end());
        }
        bool flag = false;
        rep (i,N) if (s[0] != s[i]) flag = true;
        if (flag) {
            cout << "Fegla Won" << endl;
            continue;
        }

        vector<int> c[100];
        rep (i,N) {
            int d = 1;
            rep (j,t[i].size()) {
                if (j == 0) continue;
                if (t[i][j] != t[i][j-1]) {
                    c[i].push_back(d); d = 1;
                } else d++;
            }
            c[i].push_back(d);
        }
        /*
        rep (i,N) { rep (j,c[0].size()) cout << c[i][j] << " "; cout << endl; }
        //*/

        int k = c[0].size();
        vector<int> v[100];
        rep (j,k) rep (i,N) v[j].push_back(c[i][j]);

        /*
        rep (i,N) { rep (j,k) cout << v[j][i] << " "; cout << endl; }
        //*/

        int sum = 0;
        rep (j,k) {
            sort(v[j].begin(), v[j].end());
            int m = v[j][(v[j].size()+1)/2-1];
            /*
            cout << "m = " << m << ", k = " << k << endl;
            //*/
            rep (i,N) sum += abs(m-v[j][i]);
        }
        
        cout << sum << endl;
    }
}
