#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn];
int main() {
#ifdef youmu
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.ou", "w", stdout);
#endif
	int T, cases = 0, n, b;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &b, &n);
		for(int i = 1; i <= b; i++) scanf("%d", &a[i]); 
		long long l = 0, r = (long long)n * 100000LL, ret1, ret2;
		while(l <= r) {
			long long mid = (l + r) >> 1;
			long long tmp = 0;
			for(int i = 1; i <= b; i++) {
				tmp += mid / a[i] + 1;
			}
			if(tmp >= n) {
				ret1 = mid;
				ret2 = tmp;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		///printf("ret1 = %lld, ret2 = %lld\n", ret1, ret2);
		int ans = 0;
		long long cnt = ret2 - n;
		for(int i = b; i >= 1; i--) {
			if(ret1 % a[i] == 0) {
				if(cnt == 0) ans = i;
				cnt--;
			}
		}
		printf("Case #%d: %d\n", ++cases, ans);
	}
	return 0;
}
