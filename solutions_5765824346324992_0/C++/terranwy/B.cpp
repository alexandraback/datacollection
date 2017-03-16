#include <cstdio>

int casei, cases, b;
long long n;
long long m[1010];

long long calc(long long theTime) {
	long long cnt = 0;
	for (int i = 0; i < b; ++i) {
		cnt += theTime / m[i] + 1;
		//if (theTime % m[i] == 0LL) ++cnt;
	}
	return cnt;
}

int main() {
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d%lld", &b, &n);
		for (int i = 0; i < b; ++i) scanf("%lld", m + i);
		
		if (n <= b) {
			printf("Case #%d: %lld\n", casei, n);
			continue;
		}
		
		long long left = 0, right = 100000LL * (n - 1);
		while (left <= right) {
			long long mid = (left + right) >> 1LL;
			long long tmp = calc(mid);
			if (tmp >= n) right = mid - 1;
			else left = mid + 1;
		}
		//printf("Time: %lld\n", right);
		
		long long cnt = n - calc(right);
		long long tmpcnt = cnt;
		int ans = 0;
		long long wt = 100001LL;
		for (int i = 0; i < b; ++i) {
			long long w = m[i] - right % m[i];
			if (w < wt) {
				wt = w;
				tmpcnt = cnt;
				if (tmpcnt == 1) ans = i;
			}
			else if (w == wt) {
				if (--tmpcnt == 1) ans = i;
			}
		}
		
		printf("Case #%d: %d\n", casei, ans + 1);
	}
	
	return 0;
}