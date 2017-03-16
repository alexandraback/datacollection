#include<cstdio>

int T, _;
int b, n, m[1111];
long long l, r;

int main() {
	scanf("%d", &T);
	for(int _=1; _<=T; _++) {
		printf("Case #%d: ", _);
	
		scanf("%d%d", &b, &n);
		for(int i=1;i<=b;i++) scanf("%d", &m[i]);
		
		if (n <= b) {
			printf("%d\n", n);
			continue;
		}
		
		l = 0LL; r = 1LL * 100000 * 1000000000;
		while (r - l > 1) {
			long long mi = (l+r) / 2;
			
			long long tot = 0;
			for (int i=1;i<=b && tot < n; i ++) {
				tot += mi / m[i] + 1;
			}
			if (tot < n) l = mi;
			else r = mi;
		}
		
		long long tot = 0;
		for (int i=1;i<=b; i ++) {
			tot += l / m[i] + 1;
		}
		long long remain = n - tot;
		for(int i=1;i<=b;i++) {
			if (r % m[i] == 0) remain --;
			if (!remain) {
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}