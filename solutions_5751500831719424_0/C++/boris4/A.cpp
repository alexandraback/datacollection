#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 105;

int n;
int p[MAX_N];
int am[MAX_N];
int nam[MAX_N];
string a[MAX_N];

int mycount(int i, int j, char ch) {
    int sz = a[i].size();
    int res = 0;
    while (j < sz && a[i][j] == ch) {
        res++;
        j++;
    }
    return res;
}

int myabs(int x) { if (x < 0) return -x; return x; }

int main() {
    int tests; cin >> tests;
    for (int test_id = 1; test_id <= tests; ++test_id) {
        cout << "Case #" << test_id << ": ";
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        memset(p, 0, sizeof(p));
        bool ok = true;
        int res = 0;
        while (1) {
            bool end = true;
            for (int i = 0; i < n; ++i)
                if (p[i] != a[i].size())
                    end = false;
            if (end) break;
            if (p[0] == a[0].size()) {
                ok = false;
                break;
            }
            char ch = a[0][p[0]];
            for (int i = 0; i < n; ++i) {
                am[i] = mycount(i, p[i], ch);
                nam[i] = am[i];
                if (am[i] == 0) {
                    ok = false;
                }
            }
            if (!ok) break;
            sort(nam, nam + n);
            for (int i = 0; i < n; ++i) {
                p[i] += am[i];
                res += myabs(am[i] - nam[n / 2]);
            }
        }
        if (ok) cout << res << endl;
        else cout << "Fegla Won" << endl;
    }
    return 0;
}