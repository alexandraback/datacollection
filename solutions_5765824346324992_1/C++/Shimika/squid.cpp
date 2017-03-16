#include <stdio.h>
#include <algorithm>
using namespace std;
#define min2(x, y) ((x) < (y) ? (x) : (y))
long long x, n, a[1005], k;
long long p[1005];

long long pro(long long v) {
	long long s = 0;
	for (int i = 1; i <= x; i++) {
		s += v / a[i];
		//printf("%lld %lld -> %lld\n", v, a[i], v / a[i]);
		if (v % a[i] > 0) { s++; }
	}

	return s;
}

long long first(long long t) {
	for (long long i = 1; i <= x; i++) {
		if (t % a[i] == 0) {
			return i;
		}
	}
	return 0;
}

long long last(long long t, long long idx) {
	k = 0;
	for (long long i = 1; i <= x; i++) {
		if (t % a[i] == 0) {
			p[++k] = i;
		}
	}
	sort(p + 1, p + k + 1);
	return p[idx];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tt;
	scanf("%d", &tt);
	for (int t = 1; t <= tt; t++) {
		scanf("%lld %lld", &x, &n);
		for (int i = 1; i <= x; i++) {
			scanf("%lld", &a[i]);
		}

		long long l = 1, m;
		long long r = n * 100000;

		long long mn = r, idx = 0, mx = 0;

		for (; l <= r;) {
			m = (l + r) / 2;

			long long v = pro(m);
			
			if (v >= n) {
				if (mn > m) {
					mn = m;
					idx = v;
				}
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		/*
		
		l = 1;
		r = mx;

		for (; l <= r;) {
			m = (l + r) / 2;
			if (pro(m) == idx) {
				if (mn > m) {
					mn = m;
				}
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		*/ 

		//printf("%lld %lld\n", mn, idx);
		idx = pro(mn - 1);
		//printf("%lld %lld %lld\n", mn - 1, idx, n - idx);


		long long ans = 1;
		ans = last(mn - 1, n - idx);
		printf("Case #%d: %lld\n", t, ans);
	}
}