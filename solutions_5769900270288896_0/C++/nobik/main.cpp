//#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <stack>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <list>
#include <sstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <list>
#include <cassert>
#include <complex>

using namespace std;

/* Constants begin */
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-12;
const double PI = 2*acos(0.0);
const double E = 2.71828;
/* Constants end */

/* Defines begin */
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define double long double
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define forn(i,n) for (int (i)=0; (i)<(n); ++(i))
#define random (rand()<<16|rand())
#define sqr(x) (x)*(x)
#define base complex<double>
#define sz(a) (int)(a).size()
/* Defines end */

int t;
int e[25][25];

ll calc(ll n, ll m, ll w) {
    ll mul = n * m;
    ll res = mod;
    for (int i = 0; i < (1 << mul); ++i) {
        if (__builtin_popcount(i) != w) continue;
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < m; ++y)
                e[x][y] = 0;
        for (int j = 0; j < mul; ++j) {
            if (i & (1 << j)) {
                e[j / m][j % m] = 1;
            }
        }
        ll now = 0;
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < m; ++y) {
                if (e[x][y] && x - 1 >= 0 && e[x - 1][y]) ++now;
                if (e[x][y] && x + 1 < n && e[x + 1][y]) ++now;
                if (e[x][y] && y - 1 >= 0 && e[x][y - 1]) ++now;
                if (e[x][y] && y + 1 < m && e[x][y + 1]) ++now;
            }
        now /= 2;
        res = min(res, now);
    }
    return res;
}

int main(void) {
    #ifdef nobik
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        long long n, m, w; cin >> n >> m >> w;
        cout << "Case #" << i << ": " << calc(n, m, w) << "\n";
    }
    return 0;
}
