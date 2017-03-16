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
template <typename T> ostream& operator << (ostream& os, const vector<T> &v) { for (int i = 0 ; i < v.size() ; i++) os << v[i] << ' '; os << endl; return os; }
template <typename T1, typename T2> ostream& operator <<(ostream& s, pair<T1, T2> t) { s << t.first << ' ' << t.second; return s; }
template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }

struct myCout {
} mycout;

myCout& operator << (myCout &s, const string &str) { printf("%s", str.c_str()); }
myCout& operator << (myCout &s, int x) { printf("%d", x); }
myCout& operator << (myCout &s, long long int x) { printf("%I64d", x); }
myCout& operator << (myCout &s, double x) { printf("%.10lf", x); }
myCout& operator << (myCout &s, char c) { printf("%c", c); }
template <typename T> myCout& operator << (myCout& s, const vector<T> &v) { for (int i = 0 ; i < v.size() ; i++) s << v[i] << ' '; s << endl; return s; }
// #define cout mycout

int solve() {
	next(int, n);
	next(int, pos);
	auto v = readVector<LL>(n);
	
	LL l = -1;
	LL r = 1000000LL * 1000000000;

	while (l + 1 < r) {
		LL mid = (l + r) / 2;
		assert(mid >= 0);
		LL served = 0;
		for (auto s : v) {
			served += 1 + mid / s;
		}
		if (served >= pos) r = mid;
		else l = mid;
	}
	if (r) for (auto x : v) pos -=  1 + (r - 1) / x;
	FOR (i, 0, n) if (r % v[i] == 0) {
		if (pos == 1) return i + 1;
		pos--;
	}
	return -1;
}

int main() {
	srand (time(NULL));
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	next(int, t);
	FOR (i, 0, t) cout << "Case #" << i + 1 << ": " << solve() << endl;
}