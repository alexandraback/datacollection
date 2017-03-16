#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int T;
char chr[102];
int cn[102][102];

int solve(int ti) {
    int n;
    string s;
    char tch;
    int maxn, chn;

    cin >> n;
    cin >> s;
    chn = 0;
    chr[0] = '1';
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != chr[chn]) {
            chn++;
            chr[chn] = s[i];
            cn[chn][1] = 1;
        } else
            cn[chn][1]++;
    }
    maxn = chn;
    bool flag = true;
    for (int j = 2; j <= n; j++) {
        cin >> s;
        chn = 0;
        tch = '1';
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != tch) {
                chn++;
                if (s[i] != chr[chn]) {
                    flag = false;
                }
                tch = s[i];
                cn[chn][j] = 1;
            } else
                cn[chn][j]++;
        }
        if (chn != maxn) {
            flag = false;
        }
    }
    // for (int i = 1; i <= maxn; i++) {
    //     for (int j = 1; j <= n; j++)
    //         cout << cn[i][j] << " ";
    //     cout << endl;
    // }
        if (!flag) {
            printf("Case #%i: Fegla Won\n", ti);
            return 0;
        }
    int ans = 0;
    for (int i = 1; i <= maxn; i++) {
        int minn = 1000000;
        int mink;
        for (int k = 0; k <= 101; k++) {
            int nn = 0;
            for (int j = 1; j <= n; j++) {
                nn += abs(k - cn[i][j]);
            }
            if (nn < minn) {
                minn = nn;
                mink = k;
            }
        }
        // cout << i << " " << mink << endl;
        ans += minn;
    }
    printf("Case #%i: %i\n", ti, ans);
}

int main() {
    cin >> T;
    for (int ti = 1; ti <= T; ti++) {
        solve(ti);
    }
    return 0;
}
