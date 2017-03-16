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

int n, m, k;

const int N = 16 + 1;
int z[N][N][N];

inline bool read()
{
	if (scanf("%d%d%d", &n ,&m, &k) != 3)
		return false;

    return true;
}

int RES;

int a[N][N];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

inline int check()
{
	int ans = 0;

	forn(x, n)
		forn(y, m)
		{
			if (a[x][y] == 0)
				continue;

			forn(i, 2)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (correct(nx, ny, n, m) && a[nx][ny] == 1)
				{
					ans++;
					if (ans > RES)
						goto END;
				}
			}
		}

	END:

	return ans;
}

inline void brute(int x, int y, int c)
{
	int rem = (m - y) + (n - x - 1) * m;
	if (c + rem < k)
		return;

	if (x == n)
	{
		RES = min(RES, check());
		return;
	}

	int nx = x, ny = y + 1;
	if (ny == m)
		nx++, ny = 0;

	brute(nx, ny, c);

	if (c < k)
	{
		a[x][y] = 1;
		brute(nx, ny, c + 1);
		a[x][y] = 0;
	}
}

inline int get(int n, int m, int k)
{
	int& ans = z[n][m][k];

	if (ans != -1)
		return ans;

	RES = INF;
	brute(0, 0, 0);

	return ans = RES;
}

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);

	int ans = get(n, m, k);
	cout << ans << endl;

	cerr << test << " " << ans << endl;
}

int main()
{
#ifdef HP
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

	int testCnt;
	assert(scanf("%d", &testCnt) == 1);

	memset(z, -1, sizeof(z));

	forn(test, testCnt)
	{
	    assert(read());
    	solve(test);
	}

    return 0;
}

