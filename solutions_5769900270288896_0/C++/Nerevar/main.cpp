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

void solveCase(int tc) {
    cerr << tc << endl;
    printf("Case #%d: ", tc);
    int r, c, n;
    cin >> r >> c >> n;
    int ans = 1000;
    forn(mask, (1 << (r * c))) {
        int ones = 0;
        int cur = 0;
        forn(i, r) forn(j, c) {
            if (mask & (1 << (i * c + j))) {
                ones++;
                if (i < r - 1 && mask & (1 << ((i + 1) * c + j))) cur++;
                if (j < c - 1 && mask & (1 << (i * c + j + 1))) cur++;
            }
        }
        if (ones == n) ans = min(ans, cur);
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
