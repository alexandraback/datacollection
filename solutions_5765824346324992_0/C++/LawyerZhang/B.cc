#include <iostream>
#include <vector>

using namespace std;

long long served(const vector<long long> &m, long long t) {
    long long ans = 0;
    for (int i = 0; i < (int) m.size(); ++i)
        ans += (t + m[i] - 1) / m[i];
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        int b;
        long long n;
        cin >> b >> n;
        vector<long long> m(b);
        for (int i = 0; i < b; ++i)
            cin >> m[i];

        long long lo = 0, hi = n * 100010LL;
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            long long s = served(m, mid);
            if (s < n)
                lo = mid + 1;
            else
                hi = mid;
        }
        --lo;
        long long first = served(m, lo);
        int ans;
        for (int i = 0; i < b && first < n; ++i) {
            if (lo % m[i] == 0) {
                ans = i + 1;
                ++first;
            }
        }
        cout << "Case #" << cs << ": " << ans << endl;
    }
}
