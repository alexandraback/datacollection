#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

template < typename T > T next() { T tmp; cin >> tmp; return tmp; }

void solve() {
    int n = next< int >();
    vector< int > m(n, 0);
    generate(m.begin(), m.end(), next< int >);
    int ans1 = 0;
    int ans2 = 0;
    int rate = 0;
    for (size_t i = 0; i < m.size() - 1; ++i) {
        ans1 += max(0, m[i] - m[i + 1]);
        rate = max(rate, m[i] - m[i + 1]);
    }
    for (size_t i = 0; i < m.size() - 1; ++i) {
        ans2 += min(rate, m[i]);
    }
    cout << ans1 << " " << ans2 << endl;

}

int main() {
    int t = next< int >();
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
