#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int bitcnt(int x) {
    int r = 0;
    while (x) {
        if (x&1) ++r;
        x >>= 1;
    }
    return r;
}

bool boundary(vector<int64_t>& x, vector<int64_t>& y, int n, int i, int bm) {
    if (n - bitcnt(bm) <= 3) return true;

    for (int j = 0; j < n; ++j) {
        if (j == i || (bm & (1<<j)) != 0) continue;

        int neg = 0, pos = 0, z = 0;
        for (int k = 0; k < n; ++k) {
            if (k == i || k == j || (bm & (1<<k)) != 0) continue;

            int64_t q = (x[k] - x[i])*(y[j] - y[i]) - (y[k] - y[i])*(x[j] - x[i]);
            if (q < 0) ++neg;
            else if (q > 0) ++pos;
            else ++z;
        }

        if (pos == 0 || neg == 0) {
            return true;
        }
    }
    return false;
}

vector<int> solve(vector<int64_t>& x, vector<int64_t>& y, int n) {
    vector<int> res(n, n-1);
    for (int i = 0; i < n; ++i) {
        for (int bm = 0; bm < (1<<n); ++bm) {
            if (bm & (1<<i)) {
                continue;
            }

            if (boundary(x, y, n, i, bm)) {
                res[i] = min(res[i], bitcnt(bm));
            }
        }
    }
    return res;
}

int main() {
    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N; cin >> N;
        vector<int64_t> x(N), y(N);

        for (int i = 0; i < N; ++i) {
            cin >> x[i] >> y[i];
        }

        auto res = solve(x, y, N);
        cout << "Case #" << tc << ":" << endl;
        for (int i = 0; i < N; ++i) {
            cout << res[i] << endl;
        }
    } 
}
