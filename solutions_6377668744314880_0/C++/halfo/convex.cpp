/* in the name of ALLAH, most gracious, most merciful */

//{{{ ************[       Template       ]************
#include <bits/stdtr1c++.h>
using namespace std;
//{{{ ************[  Loops               ]************
#define FORAB(i, a, b)  for (__typeof (b) i = (a), i##_b = (b); i <= i##_b; ++i)
#define REP(i, n)       FORAB (i, 0, (n) - 1)
#define FOR(i, n)       FORAB (i, 1, (n))
#define ROFBA(i, a, b)  for (__typeof (b) i = (b), i##_a = (a); i >= i##_a; --i)
#define PER(i, n)       ROFBA (i, 0, (n) - 1)
#define ROF(i, n)       ROFBA (i, 1, (n))
#define FOREACH(i, s)   for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}}}
//{{{ ************[  Floating points     ]************
#define EPS             DBL_EPSILON
#define ABS(x)          (((x) < 0) ? - (x) : (x))
#define ZERO(x)         (ABS (x) < EPS)
#define EQUAL(x, y)     (ZERO ((x) - (y)))
//}}}
//{{{ ************[  Macros              ]************
#define MS(x, y)        memset ((x), y, sizeof ((x)))
#define CLR(x)          MS ((x), 0)
#define RST(x)          MS ((x), -1)
#define ALL(x)          (x).begin (), (x).end ()
#define SZ(x)           ((int) (x).size ())
#define UNIQUE(x)       (x).resize (unique (ALL (x)) - (x).begin ())
#define PB              push_back
#define MP              make_pair
#define F               first
#define S               second
//}}}
//{{{ ************[  Debugger            ]************
template <class A, class B> ostream &operator << (ostream &o, const pair <A, B> &p) { // for std::pair
	return o << "(" << p.first << ", " << p.second << ")";
}

template <class T> void __print__ (string param, T &x) { cout << param << " :: " << x << endl; }
template <class T> void __print__ (string param, T x [], int n) {
	cout << string (param, 0, param.find (',')) << " :: ";
	REP (i, n) cout << (i ? ", " : "[") << x [i]; cout << "]\n";
}

template <class T> void __stl_print__ (T &x) { // for all STL containers
	cout << "["; FOREACH (i, x) cout << (i != x.begin () ? ", " : "") << *i; cout << "]" << endl;
}

#define NL { cout << endl; }
#define LOG(...) { __print__ (#__VA_ARGS__, __VA_ARGS__); }
#define SLOG(x) { cout << #x << " :: "; __stl_print__ (x); }
//}}}
//{{{ ************[  Functions           ]************
template <class A, class B, class C> inline C power (A p, B e, C m) {
	long long ret = 1;
	for (; e; e >>= B (1)) {
		if (e & 1) ret = (ret * p) % m;
		p = (p * p) % m;
	}
	return (C) (ret >= 0 ? ret : (ret + m));
}

template <class T> inline bool read (T &x) {
	int c, sgn = 1;
	for (c = getchar (); ~c && (c <'0' || c > '9'); c = getchar ()) if (c == '-') sgn = -1;
	for (x = 0; ~c && ('0' <= c && c <= '9'); c = getchar ()) x = x * 10 + c - '0';
	x *= sgn;
	return ~c;
}

template <class A, class B> inline A max (A a, B b) { return a > b ? a : b; }
template <class A, class B> inline A min (A a, B b) { return a < b ? a : b; }
template <class A, class B> inline void swap (A &a, B &b) { A temp = a; a = b; b = temp; }
template <class A, class B> inline B mod (A a, B m) { return (a %= m) >= 0 ? a : (a + m); }
template <class A, class B> inline B mod_inv (A a, B m) { return power (a, m - 2, m); }

// int dx [] = {0, -1, 0, 1}, dy [] = {-1, 0, 1, 0}; // 4 directions, clockwise
// int dx [] = {0, -1, -1, -1, 0, 1, 1, 1}, dy [] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 8 directions, clockwise
// int dx [] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy [] = {-2, -1, 1, 2, 2, 1, -1, -2}; // knight's move, clockwise

// cin.sync_with_stdio (false); cin.tie (false);
// cout << fixed << setprecision (10) << p << endl;
//}}}
//{{{ ************[  Typedefs && Consts  ]************
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <PII> VII;

const int MAX_N = int (1e5) + 7;
const int MAX_E = int (1e6) + 7;
const int MOD   = int (1e9) + 7;
const int INF   = 1 << 30;
const double PI = 2 * acos (0.0);
//}}}
//}}}

typedef pair <LL, LL> PLL;

LL n, ans [50];
vector <PLL> points;
map <PLL, int> m;

bool comp (const PLL &lhs, const PLL &rhs) {
	return lhs.F < rhs.F || (lhs.F == rhs.F && lhs.S < rhs.S);
} 

LL cross (const PLL &O, const PLL &A, const PLL &B) {
	return (A.F - O.F) * (B.S - O.S) - (A.S - O.S) * (B.F - O.F);
}

vector <PLL> H, P;
void convex () {
	int N = SZ (P);
	H.resize (2 * N);

	LL k = 0;
	REP (i, N) {
		while (k >= 2 && cross (H [k - 2], H [k - 1], P [i]) < 0) --k;
		H [k++] = P [i];
	}

	for (int i = N - 2, t = k + 1; i >= 0; --i) {
		while (k >= t && cross (H [k - 2], H [k - 1], P [i]) < 0) --k;
		H [k++] = P [i];
	}

	H.resize (k); H.pop_back ();
}

int main () {
#ifdef Local
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);
#endif
	int t; scanf ("%d", &t);
	FOR (cs, t) {
		scanf ("%lld", &n);
		REP (i, n) {
			LL x, y;
			scanf ("%lld %lld", &x, &y);
			points.PB (MP (x, y));
			m [MP (x, y)] = i;
		}

		sort (ALL (points), comp);
		fill (ans, ans + n, n);

		int LIM = 1 << n;
		FOR (i, LIM - 1) {
			REP (j, n)
				if (i & (1 << j))
					P.PB (points [j]);

			convex ();
			LL cnt = SZ (P);

			FOREACH (j, H) {
				int cur = m [*j];
				ans [cur] = min (ans [cur], n - cnt);
			}

			P.clear ();
			H.clear ();
		}

		printf ("Case #%d:\n", cs);
		REP (i, n) printf ("%lld\n", ans [i]);

		points.clear ();
		m.clear ();
	}

	return 0;
}

