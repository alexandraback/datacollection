#include <stdio.h>
#include <map>
#include <set>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
//#include <math.h>

using namespace std;

vector<string > s;
string ts;
bool fail;
int i, n, T, j, last;
long long cnt, mx, mn, t, res;
vector<int> a[10000];
int main(){
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> T;
    for (int test = 0; test < T; test++) {
        cin >> n;
        s.clear();
        ts.clear();
        for (i = 0; i < n; i++) {
            cin >> ts;
            s.push_back(ts);
        }
        ts.clear();
        for (i = 0; i < s[0].length(); i++) {
            if (ts.length() == 0 || ts[ts.length() - 1] != s[0][i]) {
                ts.push_back(s[0][i]);
            }
        }
        fail = 0;
        for (i = 1; i < n && !fail; i++) {
            last = 0;
            for (j = 0; j < ts.length() && !fail; j++) {
                if (s[i][last] != ts[j]) {
                    fail = 1;
                }
                while (s[i][last] == ts[j]) {
                    last++;
                }
            }
            if (last != s[i].length()) {
                fail = 1;
            }
            //cout << last << " " << " " << s[i] << " " << ts << endl;
        }
        if (fail) {
            cout << "Case #" << test + 1 << ": Fegla Won\n";
            continue;
        }

        for (i = 0; i < n; i++) {
            a[i].clear();
            last = 0;
            for (j = 0; j < ts.length(); j++) {
                t = 0;
                while (last < s[i].length() && ts[j] == s[i][last]) {
                    t++;
                    last++;
                }
                a[i].push_back(t);
            }
        }

        /*for (i = 0; i < n; i++) {
            for (j = 0; j < a[i].size(); j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }*/
        res = 0;
        for (i = 0; i < a[0].size(); i++) {
            mx = 0;
            for (j = 0; j < n; j++) {
                mx = max(mx, (long long)a[j][i]);
            }
            mn = 1000000000000000000LL;
            for (cnt = 1; cnt <= 101; cnt++) {
                t = 0;
                for (j = 0; j < n; j++) {
                    t += abs(cnt - a[j][i]);
                }
                mn = min(mn, t);
            }
            res += mn;
        }

        cout << "Case #" << test + 1 << ": " << res << endl;






        //cout << ts << endl;
        //cout << "Case #" << test << ": " <<
    }


    return 0;
}
