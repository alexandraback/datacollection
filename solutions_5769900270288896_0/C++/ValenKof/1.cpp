#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl

template<typename T> inline int sz(const T& x) { return (int) x.size(); }
template<typename T> inline void mn(T& x, const T& y) { if (y < x) x = y; }
template<typename T> inline void mx(T& x, const T& y) { if (x < y) x = y; }

int calcMaxZero(int n, int m) {
    return ((m + 1) / 2) * ((n + 1) / 2) + (m / 2) * (n / 2);
}

int calcMinOpt(int n, int m) {
    return n * m - ((n <= 2 || m <= 2) ? 0 : calcMaxZero(n - 2, m - 2));
}

int score(int n, int m, vector<vector<bool>>& used, int i, int j) {
    int ret = 0;
    if (i > 0 && used[i - 1][j]) ret++;
    if (i + 1 < n && used[i + 1][j]) ret++;
    if (j > 0 && used[i][j - 1]) ret++;
    if (j + 1 < m && used[i][j + 1]) ret++;
    return ret;
}

int bit_count(int x) {
    int ret = 0;
    while (x) {
        ret += x & 1;
        x >>= 1;
    }
    return ret;
}

int solve() {
    int n, m, r;
    cin >> n >> m >> r;
    int ans = 999999999;
    forn (mask, 1 << (n * m)) {
        if (bit_count(mask) == r) {
            int curr = 0;
            vector<vector<bool>> used(n, vector<bool>(m, false));
            forn (i, n) {
                forn (j, m) {
                    int index = i * m + j;
                    if (mask & (1 << index)) {
                        curr += score(n, m, used, i, j);
                        used[i][j] = true;
                    }
                }
            }
            mn(ans, curr);
        }
    }
    return ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    freopen("B-small-attempt1.in.txt", "r", stdin);
    freopen("B.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        cout << solve();
        cout << endl;
    }
    return 0;
}