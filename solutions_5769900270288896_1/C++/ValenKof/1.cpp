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

int score(int n, int m, const vector<vector<bool>>& used, int i, int j) {
    int ret = 0;
    if (i > 0 && used[i - 1][j]) ret++;
    if (i + 1 < n && used[i + 1][j]) ret++;
    if (j > 0 && used[i][j - 1]) ret++;
    if (j + 1 < m && used[i][j + 1]) ret++;
    return ret;
}

int solve() {
    int n, m, r;
    cin >> n >> m >> r;
    int maxZero = calcMaxZero(n, m);
    // if (r <= maxZero) return 0;
    // debug(maxZero);
    int minOpt = calcMinOpt(n, m);
    // debug(minOpt);
    // if (r >= minOpt) return (n - 1) * m + (m - 1) * n - (n * m - r) * 4;

    // debug(ans);
    // cout << "asn=" << ans;
    int ans;
    if (r < (maxZero + minOpt) / 2) {
        vector<vector<bool>> used(n, vector<bool>(m, false));
        ans = 0;
        forn (iter, r) {
            int min_i = -1;
            int min_j = -1;
            int min_score = 999;
            forn (i, n) forn (j, m) if (!used[i][j]) {
                if (score(n, m, used, i, j) < min_score) {
                    min_score = score(n, m, used, i, j);
                    min_i = i;
                    min_j = j;
                }
            }
            // cout << "score=" << min_score;
            ans += min_score;
            used[min_i][min_j] = true;
        }
    } else {
        vector<vector<bool>> used(n, vector<bool>(m, true));
        ans = (n - 1) * m + (m - 1) * n;
        forn (iter, n * m - r) {
            int min_i = -1;
            int min_j = -1;
            int min_score = -1;
            forn (i, n) forn (j, m) if (used[i][j]) {
                if (score(n, m, used, i, j) > min_score) {
                    min_score = score(n, m, used, i, j);
                    min_i = i;
                    min_j = j;
                }
            }
            // cout << "score=" << min_score;
            ans -= min_score;
            used[min_i][min_j] = false;
        }
    }
    return ans;
}

int main() {
    // freopen("in.txt", "r", stdin);
    freopen("B-large.in.txt", "r", stdin);
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