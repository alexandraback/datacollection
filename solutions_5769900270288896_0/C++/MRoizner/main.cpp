#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <stack>
#include <assert.h>
// #include <unordered_set>
#include <iomanip>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define mplus(x, y) ((x) == -1 || (y) == -1) ? -1 : ((x) + (y))
#define mmax(x, y) ((x) == -1 || (y) == -1) ? -1 : max((x), (y))
#define mmin(x, y) ((x) == -1) ? (y) : ((y) == -1) ? (x) : min((x), (y))
#define checkbit(n, k) (((1L << (k)) & (n)) != 0)

#define debug(x) cerr << '>' << #x << ':' << x << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;


int best(int r, int c, int n) {
    int N = 1L << (r * c);
    int res = 4 * r * c;
    for (int m = 0; m < N; ++m) {
        int res1 = 0;
        int count = 0;
        for (int k = 0; k < r * c; ++k)
            if (checkbit(m, k)) count++;
        if (count != n) continue;
        for (int i = 0; i < r * c; ++i) {
            if (!checkbit(m, i)) continue;
            if (checkbit(m, i + c)) ++res1;
            if (c != 1 && (i + 1) % c != 0 && checkbit(m, i + 1)) ++res1;
        }
        if (res1 < res) res = res1;
    }
    return res;
}

int main() {
    // for (int N = 1; N <= 100000; ++N) {
    //     if (bfs(N) != bfs2(N)) {
    //         cout << "AAA: " << N << endl;
    //     }
    // }
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        // debug(tt);
        int r, c, n;
        cin >> r >> c >> n;
        int64 res = best(r, c, n);
        cout << "Case #" << tt << ": " << res << endl;
    }
}
