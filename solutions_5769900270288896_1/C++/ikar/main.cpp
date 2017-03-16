#include <bits/stdc++.h>

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
//const ld PI = acosl(ld(-1));

int n, m, k;

inline bool read() {
	if (scanf("%d%d%d", &n, &m, &k) != 3)
		return false;
    return true;
}

const int N = 10000;

int a[N][N];

inline void add(int& ans, int i, int j) {
	if (i - 1 >= 0)
		ans += a[i - 1][j];
	if (i + 1 < n)
		ans += a[i + 1][j];
	if (j - 1 >= 0)
		ans += a[i][j - 1];
	if (j + 1 < m)
		ans += a[i][j + 1];
}

int calc(int need) {
	int k = ::k;
	forn(i, n) {
		forn(j, m) {
			if (((i + j) & 1) == need) {
				a[i][j] = 0;
				continue;
			}
			a[i][j] = 1;
			k--;
		}
	}

	int ans = 0;
	forn(i, 2) {
		forn(j, 2) {
			int x = i * (n - 1);
			int y = j * (m - 1);
			if (a[x][y])
				continue;
			if (k <= 0)
				continue;
			k--;
			a[x][y] = 1;
			add(ans, x, y);
		}
	}
	forn(j, m) {
		int i = 0;
		if (k <= 0)
			break;
		if (a[i][j] == 1)
			continue;
		a[i][j] = 1;
		k--;
		add(ans, i, j);
	}
	forn(j, m) {
		int i = n - 1;
		if (k <= 0)
			break;
		if (a[i][j] == 1)
			continue;
		a[i][j] = 1;
		k--;
		add(ans, i, j);
	}
	forn(i, n) {
		int j = 0;
		if (k <= 0)
			break;
		if (a[i][j])
			continue;
		a[i][j] = 1;
		k--;
		add(ans, i, j);
	}
	forn(i, n) {
		int j = m - 1;
		if (k <= 0)
			break;
		if (a[i][j])
			continue;
		a[i][j] = 1;
		k--;
		add(ans, i, j);
	}
	fore(i, 1, n - 2) 
		fore(j, 1, m - 2) {
			if (k <= 0)
				break;
			if (a[i][j])
				continue;
			a[i][j] = 1;
			k--;
			add(ans, i, j);
		}

	assert(k <= 0);
	return ans;
}

inline void solve(int test) {
	int ans = min(calc(0), calc(1));
	printf("Case #%d: %d\n", test, ans);
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
	int n;
	assert(scanf("%d", &n) == 1);
	forn(i, n) {
	    assert(read());
	    solve(i + 1);
	}

#ifdef SU2_PROJ
    cerr << "TIME: " << clock() << endl;
#endif

    return 0;
}