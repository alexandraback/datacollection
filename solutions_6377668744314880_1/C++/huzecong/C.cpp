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

#define N 3000
struct point {
	int x, y, n;
	double a;
} p[N * 2 + 1];
int T, n, hull[N + 1], top = 0;
bool onHull[N + 1];

inline ll cross(const point &o, const point &a, const point &b) {
	return (ll)(a.x - o.x) * (b.y - o.y) - (ll)(a.y - o.y) * (b.x - o.x);
}

int main(int argc, char *argv[]) {
#ifdef KANARI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int Case = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].n = i;
		}
		/*
		auto cmp1 = [](const point &a, const point &b) {
				return a.x == b.x ? a.y < b.y : a.x < b.x;
			};
		sort(p + 1, p + n + 1, cmp1);
		hull[++top] = 1;
		for (int i = 2; i <= n; ++i) {
			while (top > 1 && cross(p[hull[top - 1]], p[hull[top]], p[i]) > 0)
				--top;
			hull[++top] = i;
		}
		for (int i = n - 1; i >= 1; --i) {
			while (top > 1 && cross(p[hull[top - 1]], p[hull[top]], p[i]) > 0)
				--top;
			hull[++top] = i;
		}
		memset(onHull, 0, sizeof onHull);
		for (int i = 1; i <= top; ++i)
			onHull[p[hull[i]].n] = true;
		*/
		printf("Case #%d:\n", ++Case);
		for (int x = 1; x <= n; ++x) {
			int ans = max(0, n - 3);
			point cp;
			for (int i = 1; i <= n; ++i)
				if (p[i].n == x) p[i].a = -1000, cp = p[i];
			for (int i = 1; i <= n; ++i) {
				if (p[i].n != x) p[i].a = atan2(p[i].y - cp.y, p[i].x - cp.x);
			}
			auto cmp2 = [](const point &a, const point &b) {
					return a.a < b.a;
				};
			sort(p + 1, p + n  + 1, cmp2);
			for (int i = 2; i <= n; ++i)
				p[n + i - 1] = p[i];
			int l = 2, r = 3;
			for (; l <= n; ++l) {
		//		if (!onHull[p[l].n]) continue;
				r = max(r, l + 1);
//				while ((!onHull[p[r].n] || cross(p[l], cp, p[r]) < 0))
				while (cross(p[l], cp, p[r]) < 0)
					++r;
				ans = min(ans, r - l - 1);
			}
			printf("%d\n", ans);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
