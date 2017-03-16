#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string.h>
#include <queue>
#include <cstdio>
#include <cassert>
#include <deque>
#include <stack>
#include <utility>
#include <numeric>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, l, r) for (int i = (int)(l); i < (int)(r); i++)
#define forv(i, v) forn(i, v.size())

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void solveCase(int tc) {
    cerr << tc << endl;
    printf("Case #%d: ", tc);
    int r, c, n;
    cin >> r >> c >> n;
    if (n <= (r * c + 1) / 2) {
        cout << 0 << endl;
        return;
    }
    vector< vector<int> > a(r, vector<int>(c, 0));
    forn(i, r) forn(j, c) a[i][j] = (i + j) % 2;
    int ans = 100000;
    forn(col, 2) {
        int m = n;
        vector<int> nb;
        forn(i, r) {
            forn(j, c) {
                if (a[i][j] == col) {
                    m--;
                } else {
                    int cnt = 0;
                    forn(k, 4) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && y >= 0 && x < r && y < c) cnt++;
                    }
                    nb.push_back(cnt);
                }
            }
        }
        sort(all(nb));
        int cur = 0;
        forn(i, m) cur += nb[i];
        ans = min(ans, cur);
    }
    cout << ans << endl;
}

int main() {
#ifdef NEREVAR_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc; cin >> tc;
    forn(it, tc) solveCase(it + 1);
    return 0;
}
