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

const int N = 20;

int a[N][N];

inline void solve(int test) {
	int ans = INF;
	forn(mask, (1 << (n * m))) {
		int cnt = 0;
		forn(i, n * m) {
			if (mask & (1 << i))
				cnt++;
		}
		if (cnt != k)
			continue;
		forn(i, n * m) {
			int x = i / m;
			int y = i % m;
			a[x][y] = (mask >> i) & 1;
		}
		
		int cur = 0;
		forn(i, n) {
			forn(j, m) {
				if (i + 1 < n)
					cur += (a[i][j] & a[i + 1][j]);
				if (j + 1 < m)
					cur += (a[i][j] & a[i][j + 1]);
			}
		}
		ans = min(ans, cur);
	}
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