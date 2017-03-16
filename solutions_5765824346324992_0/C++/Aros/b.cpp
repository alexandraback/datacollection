#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000+5;
int T, B;
long long N, M[MAXN];
long long count(long long t) {
	long long res = 0;
	for (int i = 1; i <= B; i++) {
		res += t/M[i]+1;
	}
	return res;
}
int main() {
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d%lld", &B, &N);
		for (int i = 1; i <= B; i++)
			scanf("%lld", &M[i]);
		long long l = 0, r = (long long)1e15, x = l;
		while (l < r) {
			long long mid = (l+r)>>1;
			// printf("%lld, %lld\n", mid, count(mid));
			if (count(mid) >= N) {
				x = mid;
				r = mid;
			} else {
				l = mid+1;
			}
		}
		// cout<<x<<endl;
		int ans = 0;
		long long n = N;
		if (x)
			n -= count(x-1);
		for (int i = 1; i <= B; i++) if (!(x%M[i])) {
			n--;
			ans = i;
			if (!n)
				break;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}