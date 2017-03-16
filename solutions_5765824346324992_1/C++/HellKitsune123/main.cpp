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

int tt, n, pos;
int a[1000];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &tt);
    for (int test = 1; test <= tt; ++test) {
        scanf("%d%d", &n, &pos);
        REP(i, n) scanf("%d", a + i);
        LL lo = 0, hi = 1e14 + 1e13, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            LL cnt = 0;
            REP(i, n) cnt += mid / a[i] + 1;
            if (cnt >= pos)
                hi = mid;
            else
                lo = mid + 1;
        }
        LL cnt = 0;
        REP(i, n) cnt += (lo + a[i] - 1) / a[i];
        int ans = -1;
        REP(i, n) if (lo % a[i] == 0) {
            if (++cnt == pos) {
                ans = i + 1;
                break;
            }
        }
        assert(ans > 0);
        printf("Case #%d: %d\n", test, ans);
    }
	return 0;
}
