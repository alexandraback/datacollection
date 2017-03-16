#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vi> vvi;

template <class T> T inline sqr(T x) {
        return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

const int N = 19;
int s;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};
int a[N][N];

void put(pii x)
{
    a[x.fi][x.se] = 1;
    forn (t, 4) {
        int i = x.fi + di[t];
        int j = x.se + dj[t];
        s += a[i][j];
    }
}

void solve()
{
    int res  = 1e9;
    int r, c, n;
    cin >> r >> c >> n;
    vpi b;
    for1 (i, r) for1(j, c) b.pb(mp(i, j));
    forn (msk, 1 << b.size()) {
        s = 0;
        forn(i,N)forn(j,N)a[i][j] = 0;
        int q = 0;
        forn (i, b.size()) 
        if ((1 << i) & msk)
        {
            q++;
            put(b[i]);
        }
        if (q == n)
            res = min(res, s);
    }
    cout << res;
}

int main()
{
#ifdef HOME
    freopen("B-small.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for1 (t, T)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}
