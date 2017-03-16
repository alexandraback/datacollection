#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(A) (int) A.size()

using namespace std;

int T, n;
char str[1000];

bool valid(vector < vector < pair <char, int> > > v) {
    int m = sz(v[0]);
    for (int i = 0; i < n; i++)
        if (sz(v[i]) != m)
            return false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j].fi != v[0][j].fi)
                return false;
    return true;
}

void solve(int t) {
    vector < vector < pair <char, int> > > v;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        int m = strlen(str);
        vector < pair <char, int> > t;
        for (int j = 0; j < m;) {
            int cnt = 0;
            char cc = str[j];
            for (int k = j; k < m && str[k] == cc; k++)
                cnt++;
            t.pb(mp(cc, cnt));
            j += cnt;
        }
        v.pb(t);
    }
    printf("Case #%d: ", t);
    if (valid(v)) {
        int m = sz(v[0]);
        int res = 0;
        for (int i = 0; i < m; i++) {
            int minv = 1234567;
            for (int len = 1; len <= 100; len++) {
                int tot = 0;
                for (int j = 0; j < n; j++) {
                    int w = v[j][i].se;
                    if (len >= w) {
                        tot += len - w;
                    } else {
                        tot += w - len;
                    }
                }
                minv = min(minv, tot);
            }
            res += minv;
        }
        printf("%d\n", res);
    } else {
        printf("Fegla Won\n");
    }
}

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        solve(t);
    }

    return 0;

}
