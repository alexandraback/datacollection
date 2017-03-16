#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 1e4 + 10;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
int ans;

int r, c, n;
int a[MAXN][MAXN];

void rec(int st, int rem) {
    if (st == r * c || rem == 0) {
        if (rem > 0)
            return;
        int res = 0;
        FOR(i, r) {
            FOR(j, c) {
                FOR(k, 4) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || y < 0 || x >= r || y >= c)
                        continue;
                    if (a[i][j] == 1 && a[x][y] == 1) {
                        res++;
                    }
                }
            }
        }
        res /= 2;
        ans = min(ans, res);
        return;
    }
    int x = st / c;
    int y = st % c;
    if (r * c - st - 1 >= rem) {
        a[x][y] = 0;
        rec(st + 1, rem);
    }
    a[x][y] = 1;
    rec(st + 1, rem - 1);
    a[x][y] = 0;
}

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    //freopen("", "w", stderr);
#endif
    
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d%d%d", &r, &c, &n);
        ans = INF;
        rec(0, n);
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}

