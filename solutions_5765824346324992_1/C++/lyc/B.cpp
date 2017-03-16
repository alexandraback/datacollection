#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long t, b, n, a[1010];
long long x;

long long calc(long long k) {
	long long ret = 0;
	if (k == 0) return 0;
	for (long long i = 1; i <= b; ++i)
		ret += (k - 1) / a[i] + 1;
	return ret;
}

long long find(long long x, long long y) {
	if (x == y)
		return x;
	long long mid = (x + y + 1) / 2;
	if (calc(mid) >= n) return find(x, mid - 1);
	return find(mid, y);

}

int main()
{
	scanf("%lld", &t);
	for (long long ca = 1; ca <= t; ++ca) {
		scanf("%lld%lld", &b, &n);
		for (long long i = 1; i <= b; ++i)
			scanf("%lld", &a[i]);
		long long maxa = a[1];
		for (long long i = 1; i <= b; ++i)
			maxa = max(maxa, a[i]);
		x = find(0, maxa * n);
		long long idx = n - calc(x);
		for (long long i = 1; i <= b; ++i)
			if (x % a[i] == 0) {
				--idx;
				if (idx == 0) {
					printf("Case #%lld: %lld\n", ca, i);
					break;
				}
			}
	}
	return 0;
}
