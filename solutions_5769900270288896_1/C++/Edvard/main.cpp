#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

int n, m, k;

inline bool read() {
	return cin >> n >> m >> k;
}

const int N = 10 * 1000 + 3;

vector<int> z[N];

inline void solve() {
	int ans = INF; 
	forn(t, 2) {
		forn(i, n) z[i].assign(m, 0);

		set<pair<int, pt> > heap;
		forn(i, n) forn(j, m) heap.insert(mp(0, mp(i, j)));

		int cur = 0;
		forn(i, k) {
			int x = heap.begin()->sc.x;
			int y = heap.begin()->sc.y;
			if (t == 1 && i == 0 && n * m > 1) {
				x = (++heap.begin())->sc.x;
				y = (++heap.begin())->sc.y;
			}
			cur += z[x][y];
			heap.erase(mp(z[x][y], mp(x, y)));

			static int dx[] = { -1, 0, 1, 0 };
			static int dy[] = { 0, -1, 0, 1 };

			forn(p, 4) {
				int xx = x + dx[p];
				int yy = y + dy[p];
				if (!correct(xx, yy, n, m)) continue;
				pt pp(xx, yy);
				if (heap.count(mp(z[xx][yy], pp))) {
					heap.erase(mp(z[xx][yy], pp));
					z[xx][yy]++;
					heap.insert(mp(z[xx][yy], pp));
				}
			}
		}
		ans = min(ans, cur);
	}

	cout << ' ' << ans << endl;
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "rt", stdin));
	assert(freopen("output.txt", "wt", stdout));
#endif
	
	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
	
	int tc;
	cin >> tc;
	forn(tt, tc) {
		assert(read());
		printf("Case #%d:", tt + 1);
		solve();
		cerr << tt + 1 << endl;
	}
	
	return 0;
}
