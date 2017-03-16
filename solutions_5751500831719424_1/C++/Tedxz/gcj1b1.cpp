#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

long long ans = 0;
int T;
string s[110];
char us[1000];
int sn[1000][110];
int p, n;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        memset(sn, 0, sizeof sn);
        p = -1;
        us[0] = s[0][0];
        for (int i = 0; i < s[0].length(); ++i) {
            if (i != 0 && s[0][i] == s[0][i - 1])
                ++sn[p][0];
            else
                us[++p] = s[0][i], ++sn[p][0];
        }
        int pp = -1;
        for (int x = 1; x < n; ++x) {
            pp = -1;
            for (int i = 0; i < s[x].length(); ++i) {
                if (i == 0 || s[x][i] != s[x][i - 1]) {
                    ++pp;
                    if (pp > p || s[x][i] != us[pp]) {
                        goto xxx;
                    }
                }
                ++sn[pp][x];
            }
            if (pp != p)
                goto xxx;
        }
        ans = 0;
        for (int i = 0; i <= p; ++i)
            sort(sn[i], sn[i] + n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= p; ++j)
                ans += (long long)abs(sn[j][i] - sn[j][n / 2]);
        printf("Case #%d: %lld\n", cs, ans);
        continue;
    xxx:printf("Case #%d: Fegla Won\n", cs);
        
    }
    return 0;
}
