#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    int T;
    cin >> T;
    for (int tst = 1; tst <= T; tst++) {
        int b, n;
        cin >> b >> n;
        vector<int> v(b, 0);
        for (int i = 0; i < b; i++) cin >> v[i];
        vector<int> t(v.begin(), v.end());
        vector<int> pattern;
        for (int i = 1; i <= b; i++) pattern.pb(i);
        while (true) {
            int mn = *min_element(t.begin(), t.end());
            for (int &i : t) i -= mn;
            if (count(t.begin(), t.end(), 0) == t.size()) break;
            for (int i = 0; i < t.size(); i++) {
                if (t[i] == 0) {
                    pattern.pb(i + 1);
                    t[i] = v[i];
                }
            }
        }
        int m = pattern.size();
        cout << "Case #" << tst << ": " <<  pattern[(n % m + m - 1) % m] << endl; 
    }
    return 0;
}
