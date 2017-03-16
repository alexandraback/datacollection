#include "assert.h"
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <vector>

#if LOCAL
	#define DO_NOT_SEND
#endif

typedef long long LL;

int IntMaxVal = (int) 1e20;
int IntMinVal = (int) -1e20;
LL LongMaxVal = (LL) 1e20;
LL LongMinVal = (LL) -1e20;

#define FOR(i, a, b) for(int i = a; i < b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)

template<typename T> inline void minimize(T &a, T b) { a = std::min(a, b); }
template<typename T> inline void maximize(T &a, T b) { a = std::max(a, b); }

#define all(v) v.begin(),v.end()

using namespace std;

#define endl '\n'
template<typename T> struct argument_type;
template<typename T, typename U> struct argument_type<T(U)> { typedef U type; };
// #define next(t, i) argument_type<void(t)>::type i; read(i);
#define next(t, i) argument_type<void(t)>::type i; cin >> i;

void read(int &x) { scanf("%d", &x); }
void read(LL &x) { scanf("%I64d", &x); }
void read(double &x) { scanf("%lf", &x); }
void read(string &s) { static char buf[5000000]; scanf("%s", &buf); s = string(buf); }

template <typename T1, typename T2> istream& operator >>(istream& is, pair<T1, T2>& s) { is >> s.first >> s.second; return is; }
template <typename T> ostream& operator << (ostream& os, const vector<T> &v) { for (int i = 0 ; i < v.size() ; i++) os << v[i] << endl; return os; }
template <typename T1, typename T2> ostream& operator <<(ostream& s, const pair<T1, T2> &t) { s << t.first << ' ' << t.second; return s; }
template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }

struct myCout {
} mycout;

myCout& operator << (myCout &s, const string &str) { printf("%s", str.c_str()); }
myCout& operator << (myCout &s, int x) { printf("%d", x); }
myCout& operator << (myCout &s, long long int x) { printf("%I64d", x); }
myCout& operator << (myCout &s, double x) { printf("%.10lf", x); }
myCout& operator << (myCout &s, char c) { printf("%c", c); }
template <typename T> myCout& operator << (myCout& s, const vector<T> &v) { for (int i = 0 ; i < v.size() ; i++) s << v[i] << endl; return s; }
// #define cout mycout

int triangle_area_2 (int x1, int y1, int x2, int y2, int x3, int y3) {
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

bool pair_comparer2(const pair<int, int> &p1, const pair<int, int> &p2) {
	double a1 = atan2(p1.first, p1.second);
	double a2 = atan2(p2.first, p2.second);
	return a1 < a2 - 1e-15;
	
	if (p1.first == 0 && p2.first == 0) {
		assert(abs(p1.second) == 1);
		assert(abs(p2.second) == 1);
		return p1.second > p2.second;
	}
	if (p1.first == 0) {
		return p1.second > 0 || p2.first < 0;
	}
	if (p2.first == 0) {
		return p1.first > 0 && p2.second < 0;
	}
	
	if ((p1.first > 0) != (p2.first > 0))
		return p1.first > 0;
	
	LL x1 = p1.second;
	LL y1 = p1.first;
	LL x2 = p2.second;
	LL y2 = p2.first;
	
	return x1 * y2 > x2 * y1;
}

bool pair_comparer(const pair<int, int> &p1, const pair<int, int> &p2) {
	auto res = pair_comparer2(p1, p2);
	// cout << p1 << ' ' << ' ' << p2 << '=' << res << endl;
	return res;
}

LL triangle_area (LL x1, LL y1, LL x2, LL y2, LL x3, LL y3) {
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

LL get_rotation_sign(pair<int, int> p1, pair<int, int> p2) {
	auto s = triangle_area(p2.second, p2.first, 0, 0, p1.second, p1.first);
	return s;
}

vector<int> solve() {
	next(int, n);
	auto ps = readVector<pair<int, int>>(n);
	
	
	vector<int> res(n, IntMaxVal);
	if (n == 1) res[0] = 0;
	
	FOR (p1, 0, n) FOR (p2, p1 + 1, n) {
		int n1 = 0;
		int n2 = 0;
		FOR (p3, 0, n) {
			auto s = triangle_area(ps[p1].second, ps[p1].first, ps[p2].second, ps[p2].first, ps[p3].second, ps[p3].first);
			if (s < 0) n1++;
			if (s > 0) n2++;
		}
		minimize(n1, n2);
		minimize(res[p1], n1);
		minimize(res[p2], n1);
	}
	
	return res;
}

int main() {
	srand (time(NULL));
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	// cout << triangle_area(1, 2, 0, 0, 2, 1) << endl;
		
	next(int, t);
	FOR (i, 0, t) cout << "Case #" << i + 1 << ":" << endl << solve();
}