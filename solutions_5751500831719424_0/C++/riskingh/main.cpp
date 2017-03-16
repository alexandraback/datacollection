#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, i, j, k;
    scanf("%d", &n);
    string s, u = "", v;
    getline(cin, s);
    getline(cin, s);
    u += s[0];
    for (j = 1; j < s.size(); ++j) {
        if (s[j] != u[u.size() - 1]) {
            u += s[j];
        }
    }
    vector < vector <int> > C(u.size());
    for (i = 0; i < u.size(); ++i)
        C[i].resize(n, 0);
    C[0][0] = 1;
    for (j = 1, k = 0; j < s.size(); ++j) {
        if (s[j] != s[j - 1])
            ++k;
        C[k][0]++;
    }

    for (i = 1; i < n; ++i) {
        getline(cin, s);
        v = "";
        v += s[0];
        for (j = 1; j < s.size(); ++j) {
            if (s[j] != v[v.size() - 1]) {
                v += s[j];
            }
        }
        if (u != v) {
            printf("Fegla Won\n");
            return;
        }
        C[0][i]++;
        for (j = 1, k = 0; j < s.size(); ++j) {
            if (s[j] != s[j - 1])
                ++k;
            C[k][i]++;
        }
    }
    int ans = 0;
    for (j = 0; j < u.size(); ++j) {
        sort(C[j].begin(), C[j].end());
        k = C[j][n / 2];
        for (i = 0; i < n; ++i)
            ans += abs(k - C[j][i]);
    }
    printf("%d\n", ans);
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}