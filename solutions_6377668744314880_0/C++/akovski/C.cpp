#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second

int x[10000], y[10000], n;
const long double pi = acos(-1);

void solve() {
    cout << endl;
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> x[i] >> y[i];
    for (int i = 0; i < n; i ++) {
        vector<long double> v;
        int res = n - 1;
        if (res <= 2) {
            cout << 0 << endl; continue;
        }
        for (int j = 0; j < n; j ++) if (j != i) v.pb(atan2(y[j] - y[i], x[j] - x[i]));
        for (int j = 0; j < n - 1; j ++) v.pb(v[j] + 2 * pi);
        sort(v.begin(), v.end());
        for (int j = 0; j < n - 1; j ++) {
            int t = upper_bound(v.begin(), v.end(), v[j] + pi + 1e-14) - v.begin();
            res = min(res, min(t - j, n - 1 - t + j));
            res = min(res, min(t - j - 1, n - t + j));
        }
        if (res < 0) cerr << "FUCK";
        cout << res << endl;
    }
}
int main() {
    #ifdef _TEST_
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int Q; cin >> Q;
    for (int i = 0; i < Q; i ++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    
    return 0;
}



