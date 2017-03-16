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

int s = 0;
vvi a;
int n, r, c;

const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};
void put(pii x)
{
    int i = x.fi, j = x.se;
    a[i][j] = 1;
    forn (t, 4)
    {
        int ni = i + di[t];
        int nj = j + dj[t];
        s += a[ni][nj];
    }
}

bool isIn(int x, int l, int r)
{
    return x >= l && x <= r;
}
int f(pii a)
{
    int res = 0;
    forn (t, 4)
    {
        int ni = a.fi + di[t];
        int nj = a.se + dj[t];
        if (isIn(ni, 1, r) && isIn(nj, 1, c)) {
            res++;
        }
    }
    return res;
}

bool cmp(pii a, pii b)
{
    int sa = f(a); 
    int sb = f(b); 
    return sa < sb;
}

int solve(int t)
{
    s = 0;
    a = vector<vi>(r + 2, vi(c + 2, 0));
    vpi f[2];
    for1 (i, r)
        for1 (j, c)
            f[(i + j) % 2].pb(mp(i, j));
    if (t) swap(f[0], f[1]);
    sort(all(f[1]), cmp);
    vpi w = f[0];
    
    for (auto x: f[1])
        w.pb(x);

    forn (i, n)
        put(w[i]);
    return s;
}

int main()
{
#ifdef HOME
    freopen("B-large.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for1 (t, T)
    {
        cout << "Case #" << t << ": ";
        cin >> r >> c >> n;
        swap(r, c);
        int x = solve(0);
        int y = solve(1);
        cout << min(x, y) << "\n";
    }
    return 0;
}
