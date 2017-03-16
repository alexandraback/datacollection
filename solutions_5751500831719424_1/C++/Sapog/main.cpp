#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int64, int64>;
using pdd = pair<double, double>;
using vi = vector<int64>;
using vpii = vector<pii>;
using vd = vector<double>;
using vvi = vector<vi>;

constexpr double eps = 1e-11;
const double pi = acos(-1.0);
constexpr int64 p = 1000000007;
constexpr int64 countbit(int64 n) { return n == 0 ? 0 : countbit(n / 2) + n % 2; }
constexpr int64 lowbit(int64 n) { return (n ^ (n-1) ) & n; }
constexpr int64 gcd(int64 a, int64 b) { return b == 0? a : gcd(b, a % b); }
constexpr int64 lcm(int64 a, int64 b) { return a * b / gcd(a, b); }
template<typename T> constexpr auto sqr(const T& n) -> decltype(n * n) { return n * n; }

#define all(a) (a).begin(), (a).end()
#define pb push_back

void solve() {
    int n;
    cin >> n;
    vector<string> vs(n);
    for (int i = 0; i < n; ++i) cin >> vs[i];
    vector<vector<pair<char, int>>> vp(n);
    for (int i = 0; i < n; ++i) {
        char prev = '?';
        for (char c: vs[i]) {
            if (c == prev) {
                vp[i].back().second++;
            } else {
                vp[i].pb(make_pair(c, 1));
                prev = c;
            }
        }
    }
    int q = vp.front().size();
    for (auto s: vp) {
        if (s.size() != q) {
            cout << "Fegla Won" << endl;
            return;
        }
        for (int i = 0; i < q; ++i) {
            if (s[i].first != vp.front()[i].first) {
                cout << "Fegla Won" << endl;
                return;
            }
        }
    }
    int result = 0;
    for (int c = 0; c < q; ++c) {
        int res = INT_MAX;
        for (int z = 1; z <= 100; ++z) {
            int rs = 0;
            for (int i = 0; i < n; ++i) rs += abs(vp[i][c].second - z);
            res = min(res, rs);
        }
        result += res;
    }
    cout << result << endl;
}

int main() {
    int nTests;
    cin >> nTests;

    for(unsigned int testNumber = 0; testNumber < nTests; ++testNumber) {
        printf("Case #%d: ", testNumber + 1);
        solve();
    }
    return 0;
}
