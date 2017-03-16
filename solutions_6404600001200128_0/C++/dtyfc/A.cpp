#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn];
int main() {
#ifdef youmu
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.ou", "w", stdout);
#endif
	int T, cases = 0, n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int ans1 = 0;
		for(int i = 2; i <= n; i++) {
			if(a[i - 1] > a[i]) ans1 += a[i - 1] - a[i];
		}
		int l = 0, r = 10000, v;
		while(l <= r) {
			int mid = (l + r) >> 1;
			bool flag = 0;
			int tmp = a[1];
			for(int i = 2; i <= n && flag == 0; i++) {
				if(tmp - mid > a[i]) {
					flag = 1;
				} 
				tmp = a[i];
			}
			if(flag == 0) {
				v = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		int ans2 = 0;
		int tmp = a[1];
		for(int i = 2; i <= n; i++) {
			if(v <= tmp) {
				ans2 += v;
			} else {
				ans2 += tmp;
				tmp = 0;
			}
			tmp = a[i];
		}
		printf("Case #%d: %d %d\n", ++cases, ans1, ans2);
	}
	return 0;
}
