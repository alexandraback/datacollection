#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

template < typename T > T next() { T tmp; cin >> tmp; return tmp; }


void solve() {
    int n = next< int >();
    vector< ll > x(n);
    vector< ll > y(n);
    for (int i = 0; i < n; ++i) {
        x[i] = next< ll >();
        y[i] = next< ll >();
    }
    vector< int > ans(n, n);
    if (n == 1) {
        cout << "\n0\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int p = 0;
            int o = 0;
            for (int k = 0; k < n; ++k) {
                ll val = (x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]);
                p += val > 0 ? 1 : 0;
                o += val < 0 ? 1 : 0;
            }
            int nv = min(p, o);
            ans[i] = min(ans[i], nv);
            ans[j] = min(ans[j], nv);
        }
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
}

int main() {
    int t = next< int >();
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
