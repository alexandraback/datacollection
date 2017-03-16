#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef vector <int> vi;

#define rep(i, n) for(int i = 0; i < (n); ++i)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define mset(a, v) memset(a, v, sizeof(a))
#define sz(a) ((int)a.size())

#define gi(x) scanf("%d", &x)
#define pis(x) printf("%d ", x)
#define pin(x) printf("%d\n", x)
#define pnl printf("\n")
#define dbn cerr << "\n"
#define dbg(x) cerr << #x << " : " << (x) << " "
#define dbs(x) cerr << (x) << " "

const int maxR = 16;

int grid[17][17];

const int INF = (int)1e9;

inline void solve() {
    int r, c, n;
    gi(r), gi(c), gi(n);

    int lim = 1 << (r * c);

    int ans = INF;

    for (int mask = 0; mask < lim; ++mask) if (__builtin_popcount(mask) == n) {
        rep (i, r) {
            rep (j, c) {
                grid[i][j] = (mask >> (i * c + j)) & 1;
            }
        }

        

        int cur = 0;

        rep (i, r) {
            rep (j, c) if (grid[i][j] > 0) {
                if (i + 1 < r) {
                    if (grid[i + 1][j] > 0) ++cur;
                }
                if (j + 1 < c) {
                    if (grid[i][j + 1] > 0) ++cur;
                }
            }
        }
        
        ans = min(ans, cur);

    }

    printf("%d\n", ans);
    fprintf(stderr, "%d\n", ans);
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    gi(T);

    for (int tc = 1; tc <= T; ++tc) {
        printf("Case #%d: ", tc);
        fprintf(stderr, "Case #%d: ", tc);
        solve();
    }
    return 0;
}