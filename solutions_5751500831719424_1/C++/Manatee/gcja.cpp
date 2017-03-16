#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

#define LL long long
#define LD long double
#define SIZE 2000
#define DEBUG 1

using namespace std;

LL T, n, id[SIZE], oldid[SIZE];
string s[SIZE];
LL failed, ans;
LL a[SIZE];

LL f(LL *arr, LL n, LL av) {
    LL ans = 0;
    for (int i = 0; i < n; i++) ans += abs(arr[i] - av);
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("ex.in", "r", stdin);
    freopen("ex.out", "w", stdout);
#endif // DEBUG
    cin >> T;
    for (int iter = 0; iter < T; iter++) {
//        cerr << iter << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            id[i] = 0;
            oldid[i] = -1;
        }
        failed = 0;
        ans = 0;
        for (int i = 0; i < n; i++) cin >> s[i];
        while (1) {
            for (int i = 0; i < n; i++)
                while ((id[i] + 1 < s[i].length()) && (s[i][id[i]] == s[i][id[i] + 1])) id[i]++;
//            for (int i = 0; i < n; i++) cerr << id[i];
//            cerr << endl;

            for (int i = 1; i < n; i++) {
                if (s[i][id[i]] != s[i - 1][id[i - 1]]) {
                    failed = 1;
                    break;
                }
                if ((s[i].length() == id[i] + 1) && (s[i - 1].length() != id[i - 1] + 1)) {
                    failed = 1;
                    break;
                }
                if ((s[i].length() != id[i] + 1) && (s[i - 1].length() == id[i - 1] + 1)) {
                    failed = 1;
                    break;
                }
            }
            if (failed) break;
            for (int i = 0; i < n; i++) {
                a[i] = id[i] - oldid[i];
            }

            LL l = 0;
            LL r = 100;
            LL m1, m2;
            while (l + 2 < r) {
                m1 = (2 * l + r) / 3;
                m2 = (l + 2 * r) / 3;
                if (f(a, n, m1) < f(a, n, m2)) r = m2;
                else l = m1;
            }
                m1 = (2 * l + r) / 3;
                m2 = (l + 2 * r) / 3;

            ans += min(f(a, n, l), min(f(a, n, m1), min(f(a, n, m2), f(a, n, r))));
            for (int i = 0; i < n; i++) {
                oldid[i] = id[i];
                if (id[i] + 1 < s[i].length()) id[i]++;
            }
            if (oldid[0] == id[0]) break;
        }
        cout << "Case #" << iter + 1 << ": ";
        if (failed) cout << "Fegla Won" << endl;
        else cout << ans << endl;
    }
    return 0;
}

