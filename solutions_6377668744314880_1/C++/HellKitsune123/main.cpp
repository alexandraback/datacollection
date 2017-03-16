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
int ans[3000];
double ang[6005];

const double PI = atan2(0, -1);
const double EPS = 1e-10;

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
        REP(i, n) {
            int pos = 0;
            REP(j, n) if (j != i)
                ang[pos++] = atan2(y[j] - y[i], x[j] - x[i]);
            sort(ang, ang + pos);
            REP(j, pos) ang[pos + j] = ang[j];
            ans[pos + pos] = ans[pos];
            int &best = ans[i];
            best = 0;
            int hi = 0;
            REP(lo, pos) {
                if (hi <= lo) hi = lo + 1;
                while (true) {
                    if (hi == lo + pos) break;
                    double dif = ang[hi] - ang[lo];
                    while (dif < 0) dif += 2 * PI;
                    while (dif > 2 * PI) dif -= 2 * PI;
                    if (dif > PI + EPS) break;
                    ++hi;
                }
                best = max(best, hi - lo);
            }
            best = n - 1 - best;
        }
        cout << "Case #" << test << ":\n";
        REP(i, n) cout << ans[i] << '\n';
    }
	return 0;
}
