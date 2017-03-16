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
        int N; cin >> N; // N = 2
        string s[2], t[2];
        rep (i,N) {
            cin >> s[i];
            t[i] = s[i];
            s[i].erase(unique(s[i].begin(), s[i].end()), s[i].end());
        }
        if (s[0] != s[1]) {
            cout << "Fegla Won" << endl;
            continue;
        }
        int k = s[0].size();    
        vector<int> c[2];
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

        int sum = 0;
        rep (j,k) sum += abs(c[0][j]-c[1][j]);
        cout << sum << endl;
    }
}
