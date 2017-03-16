//============================================================================
// Author    : LAM PHAN VIET - lamphanviet@gmail.com
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI  3.1415926535897932385
#define EPS 1e-7
#define MOD 1000000007
#define INF 1500111222
#define MAX 100111

int n, a[MAX];

int solve1() {
    int res = 0;
    rep(i, n - 1) if (a[i] > a[i + 1])
        res += a[i] - a[i + 1];
    return res;
}

int solve2() {
    int rate = 0;
    rep(i, n - 1) if (a[i] > a[i + 1]) {
        rate = max(rate, a[i] - a[i + 1]);
    }
    if (rate == 0) return 0;
    int res = 0;
    rep(i, n - 1) {
        res += min(rate, a[i]);
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int cases, caseNo = 0;
    for (scanf("%d", &cases); cases--; ) {
        scanf("%d", &n);
        rep(i, n) scanf("%d", &a[i]);
        printf("Case #%d: %d %d\n", ++caseNo, solve1(), solve2());
    }
    return 0;
}