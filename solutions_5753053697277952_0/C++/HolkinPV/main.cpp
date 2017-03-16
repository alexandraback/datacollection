#pragma comment(linker, "/stack:128000000")

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <climits>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define x first
#define y second
#define ft first
#define sc second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = INT_MAX / 2;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int N = 26 + 3;

int a[N], n;

inline bool read()
{
    if (scanf("%d", &n) != 1)
        return false;

    forn(i, n)
        assert(scanf("%d", &a[i]) == 1);

	return true;
}

vector<pair<int, char> > z;

inline void write(int i)
{
    putchar(z[i].sc);
    z[i].ft--;
}

inline bool check()
{
    int maxv = 0;
    int sum = 0;

    forn(i, sz(z))
    {
        maxv = max(maxv, z[i].ft);
        sum += z[i].ft;
    }

    return maxv * 2 <= sum;
}

inline void solve(int test)
{
	printf("Case #%d:", test + 1);

    z.clear();
    forn(i, n)
        z.pb(mp(a[i], ('A' + i)));

    int sum = 0;
    forn(i, sz(z))
        sum += z[i].ft;

    sort(all(z));
    assert(check());

    if (sum % 2 != 0)
    {
        putchar(' ');
        write(sz(z) - 1);
        assert(check());
    }

    sort(all(z));
    while(z[sz(z) - 1].ft > 0)
    {
        sort(all(z));

        putchar(' ');

        assert(sz(z) >= 2);

        write(sz(z) - 1);
        write(sz(z) - 2);

        assert(check());
    }

    forn(i, sz(z))
        assert(z[i].ft == 0);

    puts("");
}

int main()
{
#ifdef HP
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int testCnt;
    assert(cin >> testCnt);

    forn(test, testCnt)
    {
        assert(read());
        solve(test);
    }

    return 0;
}

