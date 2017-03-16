#include<cstdio>
#include<algorithm>
using namespace std;

int T, _;
int n, x[3333], y[3333];

long long mul(int a, int b, int c) {
	return 1LL * x[a] * y[b] + 1LL * x[b] * y[c] + 1LL * x[c] * y[a] - 1LL * y[a] * x[b] - 1LL * y[b] * x[c] - 1LL * y[c] * x[a];
}

int main() {
	scanf("%d", &T);
	for(int _=1; _<=T; _++) {
		printf("Case #%d:\n", _);
		
		scanf("%d", &n);
		for(int i=0;i<n;i++) scanf("%d%d", &x[i], &y[i]);
		for(int i=0;i<n;i++) {
			int res = n-1;
			for(int j=0;j<n;j++) {
				if (i==j) continue;
				int l = 0, r = 0;
				for(int k = 0; k < n; k ++) {
					if (i== k || j == k) continue;
					long long ans = mul(i, j, k);
					if (ans < 0) l ++;
					if (ans > 0) r ++;
				}
				res = min(res, min(l, r));
			}
			printf("%d\n", res);
		}
	}

	return 0;
}