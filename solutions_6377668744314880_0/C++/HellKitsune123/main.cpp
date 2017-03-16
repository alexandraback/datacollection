#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int tt, n;
LL x[3000], y[3000];
int ord[3000], cnt;
vector<int> p;
int ans[3000];

bool cmp(const int &lhs, const int &rhs) {
    if (x[lhs] != x[rhs]) return x[lhs] < x[rhs];
    return y[lhs] < y[rhs];
}

bool cw(const int &a, const int &b, const int &c) {
    return (x[b] - x[a]) * (y[c] - y[a]) - (y[b] - y[a]) * (x[c] - x[a]) <= 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> tt;
    for (int test = 1; test <= tt; ++test) {
        cin >> n;
        REP(i, n) cin >> x[i] >> y[i];
        REP(i, n) ans[i] = 10000;
        REP(mask, 1 << n) if (mask) {
            p.assign(n * 2, -1);
            int k = 0;
            cnt = 0;
            REP(i, n) if (mask & (1 << i))
                ord[cnt++] = i;
            sort(ord, ord + cnt, cmp);
            for (int i = 0; i < cnt; p[k++] = ord[i++])
                for (; k > 1 && !cw(p[k - 2], p[k - 1], ord[i]); --k);
            for (int i = cnt - 2, prev = k; i >= 0; p[k++] = ord[i--])
                for (; k > prev && !cw(p[k - 2], p[k - 1], ord[i]); --k);
            if (k > 1) --k;
            if (k == 2 && p[0] == p[1]) k = 1;
            REP(i, k) ans[p[i]] = min(ans[p[i]], n - cnt);
        }
        cout << "Case #" << test << ":\n";
        REP(i, n) cout << ans[i] << '\n';
    }
	return 0;
}
