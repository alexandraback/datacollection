#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

main () {
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int n;
        cin >> n;
        string t[n];
        vector <int> p[n];
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            t[i] = s[0];
            p[i].push_back (1);
            for (int j = 1; j < s.length (); ++j) {
                if (s[j] == s[j - 1]) ++p[i][p[i].size () - 1];
                else {
                    t[i] += s[j];
                    p[i].push_back (1);
                }
            }
        }
        string s = t[0];
        bool ok = true;
        for (int i = 0; i < n; ++i) if (t[i] != s) ok = false;
        cout << "Case #" << test << ": ";
        if (ok) {
            int ans = 0;
            for (int i = 0; i < s.length (); ++i) {
                vector <int> v;
                for (int j = 0; j < n; ++j) {
                    v.push_back (p[j][i]);
                }
                sort (v.begin (), v.end ());
                int s1 = 0;
                for (int j = 0; j < n; ++j) s1 += v[j];
                int s2 = 0;
                int res = -1;
                for (int j = 0; j < n; ++j) {
                    if (res == -1 || s1 - (n - j) * v[j] + j * v[j] - s2 < res) res = s1 - (n - j) * v[j] + j * v[j] - s2;
                    s1 -= v[j];
                    s2 += v[j];
                }
                ans += res;
            }
            cout << ans << "\n";
        }
        else cout << "Fegla Won\n";
    }
}
