#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

template < typename T > T next() { T tmp; cin >> tmp; return tmp; }

ll cust(ll mid, const vector< ll > & b) {
    ll f = 0;
    for (size_t i = 0; i < b.size(); ++i) {
        f += (mid + b[i] - 1) / b[i];
    }
    return f;
}

void solve() {
    int bar = next< int >();
    ll n = next< ll >() - 1;
    vector< ll > b(bar);
    generate(b.begin(), b.end(), next< ll >);

    ll left = 0;
    ll right = b[0] * n + 1;
    while (left + 1 < right) {
        ll mid = left + ((right - left) >> 1);
        if (cust(mid, b) > n) {
            right = mid;
        } else {
            left = mid;
        }
    }

    n -= cust(left, b);
    // cerr << n << endl;
    for (size_t i = 0; i < b.size(); ++i) {
        if (left % b[i] == 0) {
            n--;
        }
        if (n == -1) {
            cout << (i + 1) << endl;
            return;
        }
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
