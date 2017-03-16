#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const int inf = 1E9;
const ll mod = 1E9;

#define SZ 17

int dp[17][(1<<16)+10][17];
int r, c;

int f (int mask) {
    int pre = 0;
    int ans = 0;
    for (int i = 0; i < 20; i++) {
        int now = bool(mask&(1<<i));
        if (pre && now == pre) ans++;
        pre = now;
    }
    return ans;
}

int solve (int nr, int mask, int lft) {
    if (lft < 0) return inf;
    if (nr == 0) {
        if (lft == 0) return 0;
        return inf;
    }
    int &ret = dp[nr][mask][lft];
    if (ret != -1) return ret;
    ret = inf;
    int lim = (1<<c);
    for (int nmask = 0; nmask < lim; nmask++) {
        ret = min(ret, __builtin_popcount(mask&nmask) + f (nmask) + solve(nr - 1, nmask, lft - __builtin_popcount(nmask)));
    }
    return ret;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int m;
        scanf("%d %d %d", &r, &c, &m);
        mem(dp, -1);
        printf("Case #%d: %d\n", cs + 1, solve(r, 0, m));
    }


    return 0;
}







