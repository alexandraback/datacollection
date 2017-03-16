#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int64_t go(vector<int>& a, int64_t t) {
    int64_t n = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        n += 1 + t / a[i];
    }
    return n;
}

int64_t solve(vector<int>& a, int64_t N) {
    if (N == 1) {
        return 1;
    }
    if (a.size() >= N) {
        return N;
    }

    int64_t lo = 0,
            hi =  *min_element(a.begin(), a.end()) * (N + 1) + 1000;

    while (hi - lo > 1) {
        int64_t mid = (lo + hi) / 2;
        auto cnt = go(a, mid);

        if (cnt >= N) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    auto xx = go(a, hi);
    auto yy = N;

    auto ofs = go(a, hi) - N;

    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if (hi % a[i] == 0) {
            if (ofs == 0) {
                return 1 + i;
            }
            --ofs;
        }
    }
    cerr << "logic error" << endl;
    for (int i = 0; i < (int)a.size(); ++i) {
        cerr << a[i] << " ";
    }
    cerr << endl;
    cerr << N << endl;
    cerr << hi << go(a, hi) << endl;
    return 0;
}

int main() {
    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int B; cin >> B;
        int N; cin >> N;
        vector<int> a(B);

        for (int i = 0; i < B; ++i) {
            cin >> a[i];
        }

        auto res = solve(a, N);
        cout << "Case #" << tc << ": " << res << endl; 
    } 
}
