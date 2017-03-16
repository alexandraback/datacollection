#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

int r, c, n;

inline bool read()
{
	if (scanf ("%d%d%d", &r, &c, &n) != 3)
		return false;

	return true;
}

vector<vector<int> > ans;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

inline bool valid (int x, int y)
{
	return x >= 0 && y >= 0 && x < r && y < c;
}

inline int getCnt (int x, int y)
{
	int res = 0;
	forn (k, 4)
	{
		int nx = x + dx[k], ny = y + dy[k];

		if (!valid(nx, ny))
			continue;

		res += ans[nx][ny];
	}

	return res;
}

inline int calc1 ()
{
	ans.resize(r);
	forn (i, r)
		ans[i].resize(c);

	int cnt = 0;

	forn (i, r)
		forn (j, c)
			if (!((i + j) & 1))
			{
				ans[i][j] = 1;
				cnt++;
			}
			else
				ans[i][j] = 0;

	if (cnt >= n)
		return 0;

	fore (it, 1, 4)
	{
		forn (i, r)
		{
			forn (j, c)
				if (ans[i][j] == 0 && getCnt(i, j) == it)
				{
					cnt++;
					ans[i][j] = 1;

					if (cnt == n)
						break;
				}

			if (cnt == n)
				break;
		}

		if (cnt == n)
			break;
	}

	int res = 0;
	forn (i, r)
		forn (j, c)
		{
			if (!ans[i][j])
				continue;

			res += getCnt(i, j);
		}

	return res / 2;
}

inline int calc2 ()
{
	ans.resize(r);
	forn (i, r)
		ans[i].resize(c);

	int cnt = 0;
	forn (i, r)
		forn (j, c)
		{
			ans[i][j] = 1;
			cnt++;
		}

	for (int it = 4; it >= 1; it--)
	{
		fore(x, 0, r - 1)
		{
			fore(y, 0, c - 1)
			{
				if (getCnt(x, y) != it)
					continue;

				ans[x][y] = 0;
				cnt--;

				if (cnt == n)
					break;
			}

			if (cnt == n)
				break;
		}

		if (cnt == n)
			break;
	}

	if (cnt != n)
		return INF;

	int res = 0;
	forn (i, r)
		forn (j, c)
		{
			if (!ans[i][j])
				continue;

			res += getCnt(i, j);
		}

//	forn (i, r)
//	{
//		forn (j, c)
//			cerr << ans[i][j];
//		cerr << endl;
//	}

	return res / 2;
}

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);

	int ans = min(calc1(), calc2());

	printf ("%d\n", ans);
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	int testCnt;
	assert(scanf ("%d", &testCnt) == 1);

	forn (test, testCnt)
	{
		assert(read());
		solve(test);
	}

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}
