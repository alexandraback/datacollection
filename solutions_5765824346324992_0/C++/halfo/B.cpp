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

LL b, n, m [MAX_N];
VI can;

int main () {
#ifdef Local
	freopen ("B.in", "r", stdin);
	freopen ("B.out", "w", stdout);
#endif
	int t; scanf ("%d", &t);
	FOR (cs, t) {
		scanf ("%lld %lld", &b, &n);
		REP (i, b) scanf ("%lld", m + i);

		LL L = 0;
		LL H = n * (*max_element (m, m + b));
		while (L <= H) {
			LL M = (L + H) >> 1;

			LL tot = 0;
			REP (i, b) tot += 1 + M / m [i];

			if (tot >= n) H = M - 1;
			else L = M + 1;
		}

		can.clear ();
		REP (i, b)
			if (L % m [i] == 0)
				can.PB (i + 1);

		LL done = 0;
		LL T = L - 1;
		if (T >= 0) REP (i, b) done += 1 + T / m [i];

		n -= done;
		printf ("Case #%d: %d\n", cs, can [n - 1]);
	}

	return 0;
}

