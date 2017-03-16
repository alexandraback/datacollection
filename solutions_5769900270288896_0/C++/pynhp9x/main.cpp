#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<long long, int> lli;
typedef long long ll;
typedef unsigned long long ull;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, f) for(__typeof(f.begin()) i = f.begin(); i != f.end(); i++)
#define fi first
#define se second
#define pb push_back
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define all(x) x.begin(), x.end()
#define two(x) (1LL << x)
#define bit(x, i) ((x >> (i-1)) & 1LL)
#define onbit(x, i) (x | (1LL << (i-1)))
#define offbit(x, i) (x & ~(1 << (i-1)))
#define N 1001

int ntest, m, n, k;
int f[18][18][1 << 5];

void solve() {
    if (m < n) swap(m, n);
    reset(f, 0x7f);
    f[0][0][0] = 0;
    int T = (1 << n) - 1;
    For(i, 1, m) For(j, 0, k) For(mask, 0, T)
    For(tt, 0, T) {
        int dem = 0, cp = 0;
        For(ii, 1, n) {
            dem += bit(tt, ii);
            if (ii > 1 && bit(tt, ii) && bit(tt, ii-1)) {
                cp++;
            }
            if (bit(tt, ii) && bit(mask, ii)) {
                cp++;
            }
        }
        if (j + dem <= k && f[i][j + dem][tt] > f[i-1][j][mask] + cp) f[i][j + dem][tt] = f[i-1][j][mask] + cp;
    }
    int res = 10000000;
    For(mask, 0, T) res = min(res, f[m][k][mask]);
    cout << res << endl;
 //   cout << f[16][16][1] << endl;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> ntest;
    For(test, 1, ntest) {
        printf("Case #%d: ", test);
        cin >> m >> n >> k;
        solve();
    }
}


