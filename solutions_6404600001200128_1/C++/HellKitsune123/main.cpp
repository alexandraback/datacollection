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
int a[1000];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> tt;
    for (int test = 1; test <= tt; ++test) {
        cin >> n;
        REP(i, n) cin >> a[i];
        int ans = 0;
        for (int i = 1; i < n; ++i) if (a[i] < a[i - 1])
            ans += a[i - 1] - a[i];
        cout << "Case #" << test << ": " << ans << ' ';
        int rate = 0;
        for (int i = 1; i < n; ++i) if (a[i] < a[i - 1])
            rate = max(rate, a[i - 1] - a[i]);
        ans = 0;
        REP(i, n - 1) ans += min(rate, a[i]);
        cout << ans << endl;
    }
	return 0;
}
