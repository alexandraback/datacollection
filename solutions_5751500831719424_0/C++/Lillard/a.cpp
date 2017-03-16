#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 107;
int run;
int n, m;
string s[maxn], ss[maxn];
vector<int> f[maxn];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        ss[i] = "";
        ss[i] += s[i][0];
        for (int j = 1; j < s[i].size(); j++) {
            if (s[i][j] != s[i][j-1]) {
                ss[i] += s[i][j];
            }
        }
    }
    printf("Case #%d: ", run);
    for (int i = 2; i <= n; i++) {
        if (ss[i] != ss[i-1]) {
            puts("Fegla Won");
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        f[i].clear();
        int sum = 1;
        for (int j = 1; j < s[i].size(); j++) {
            if (s[i][j] == s[i][j-1]) {
                sum++;
            } else {
                f[i].push_back(sum);
                sum = 1;
            }
        }
        f[i].push_back(sum);
    }
    m = f[1].size();
    int res = 0;
    for (int j = 0; j < m; j++) {
        int tmp = 100000000;
        int len = 0;
        for (int i = 1; i <= n; i++) {
            len = max(len, f[i][j]);
        }
        for (int k = 1; k <= len; k++) {
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += abs(f[i][j]-k);
            }
            tmp = min(tmp, sum);
        }
        res += tmp;
    }
    printf("%d\n", res);
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (run = 1; run <= test; run++) {
        solve();
    }
    return 0;
}
