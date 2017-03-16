#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) cin >> v[i];

        // second
        int s = 0;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1])
                s += v[i] - v[i + 1];
        }

        // second
        int mxs = 0;
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1])
                mxs = max(mxs, v[i] - v[i + 1]);
        }
        int ss = 0;
        for (int i = 0; i < n - 1; i++) {
            ss += min(mxs, v[i]);
        }
        cout << "Case #" << t << ": " << s << " " << ss << endl;
    }
    return 0;
}
