//Template
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <ios>
#include <iomanip>
#include <ctime>
#include <numeric>
#include <functional>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <cstdarg>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
#define pair(x, y) make_pair(x, y)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)

inline int read() {
	static int r, sign;
	static char c;
	r = 0, sign = 1;
	do c = getchar(); while (c != '-' && (c < '0' || c > '9'));
	if (c == '-') sign = -1, c = getchar();
	while (c >= '0' && c <= '9') r = r * 10 + (int)(c - '0'), c = getchar();
	return sign * r;
}

template <typename T>
inline void print(T *a, int n) {
	for (int i = 1; i < n; ++i) cout << a[i] << " ";
	cout << a[n] << endl;
}
#define PRINT(_l, _r, _s, _t) { cout << #_l #_s "~" #_t #_r ": "; for (int _i = _s; _i != _t; ++_i) cout << _l _i _r << " "; cout << endl; }

#define N 1000
int T, n, m, a[N + 1];

inline ll check(ll x) {
	ll ret = 0LL;
	for (int i = 1; i <= m; ++i)
		ret += x / a[i] + 1;
	return ret;
}

int main(int argc, char *argv[]) {
#ifdef KANARI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int Case = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= m; ++i)
			scanf("%d", a + i);
		ll l = 0LL, r = (ll)n * 100000 / m;
		while (l < r) {
			ll mid = (l + r) >> 1;
			if (check(mid) >= n) r = mid;
			else l = mid + 1;
		}
		cerr << l << endl;
		int ans = 0, cnt = check(l - 1);
		for (int i = 1; !ans && i <= n; ++i)
			if (l % a[i] == 0 && ++cnt == n) ans = i;
		printf("Case #%d: %d\n", ++Case, ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
