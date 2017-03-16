#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        long long ans1 = 0;
        for (int i = 1; i < n; ++i)
            ans1 += max(0, a[i - 1] - a[i]);
        long long rate = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                rate = max(rate, (long long) ceil((double) max(0, a[i] - a[j]) / (double) (j - i)));
        long long ans2 = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] < rate) {
                ans2 += a[i - 1];
            } else {
                ans2 += rate;
            }
        }
        cout << "Case #" << cs << ": " << ans1 << " " << ans2 << endl;
    }
}
