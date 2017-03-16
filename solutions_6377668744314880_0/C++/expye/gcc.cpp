#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int inf = ~0u>>1;
int T, n;
int X[3001], Y[3001];
ll x[3001], y[3001];
int r[3001];
double at[3001];
int q[6001];
inline bool cmp(const int &a, const int &b) {
	return (at[a] < at[b]);
}
inline ll det(ll x1, ll y1, ll x2, ll y2) {
	return x1 * y2 - x2 * y1;
}
int main() {
	freopen("small.in", "r", stdin);
	freopen("small.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d%d", &X[j], &Y[j]);
			x[j] = (ll)X[j];
			y[j] = (ll)Y[j];
		}
		printf("Case #%d:\n", i);
		for (int j = 1; j <= n; j++) {
			int cnt = 0;
			for (int k = 1; k <= n; k++) at[k] = 0.0;
			for (int k = 1; k <= n; k++) {
				if (k == j) continue;
				r[cnt++] = k;
				at[k] = atan2(1.0 * (y[k] - y[j]), 1.0 * (x[k] - x[j]));	
			}
			sort(r, r + cnt, cmp);
			int ans = inf;
			int head = 0, tail = -1;/*
			for (int k = 0; k < cnt; k++) printf("%d ", r[k]);
			printf("\n");
			for (int k = 0; k < cnt; k++) printf("%lf ", at[r[k]]);
			printf("\n");*/
			for (int t = 0; t < 2 * cnt; t++) {
				int k = t % cnt;
				q[++tail] = r[k];
				while (det(x[q[tail]] - x[j], y[q[tail]] - y[j], x[q[head]] - x[j], y[q[head]] - y[j]) < 0 || tail - head >= cnt) head++;
			//	printf("r= %d %d\n", q[head], q[tail]);
				if (cnt - (tail - head + 1) < ans) ans = cnt - (tail - head + 1);	 
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}                                          
