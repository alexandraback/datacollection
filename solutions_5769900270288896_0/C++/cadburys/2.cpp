#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

long long T, R, C, N;

int main() {
	scanf("%lld", &T);
	for(int t= 1; t <= T; ++t) {
		scanf("%lld%lld%lld", &R, &C, &N);
		long long n2 = N;
		long long ans = 0;
		long long v = 0;
		if(R > 1 && C > 1) {
			if(N > (R * C + 1) / 2) {
				N -= (R * C + 1) / 2;
				if(!(R & C & 1)) {
					ans += min(2ll, N) * 2;
					N = max(N - 2, 0ll);
					v = R + C - 4;
				}
				else
					v = 2 * (R / 2 + C / 2);
				ans += min(N, v) * 3;
				N = max(N - v, 0ll);
				ans += N * 4;
				if(R & C & 1) {
					N = n2 - (R * C - 1) / 2;
					long long ans2 = ans = min(N, 4ll) * 2;
					N = max(0ll, N - 4);
					v = 2 * (R / 2 + C / 2) - 4;
					ans2 += min(N, v) * 3;
					N = max(N - v, 0ll);
					ans2 += N * 4;
					ans = min(ans, ans2);
				}
			}
		}
		else {
			R = max(R, C);
			if(N == R) {
				ans = 2;
				N--;
			}
			N = max(0ll, N - 2);
			ans += N;
		}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
