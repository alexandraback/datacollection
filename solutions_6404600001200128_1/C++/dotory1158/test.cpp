#include <stdio.h>
int d[1050];
int MIN(int a, int b) {
	return (a>b)?b:a;
}
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, N, i, MX, SUM, ANS2 = 0;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for(i = 1; i <= N; i++) scanf("%d", &d[i]);
		MX = 0, SUM = 0, ANS2 = 0;
		for(i = 1; i < N; i++) {
			if(d[i] > d[i+1]) {
				SUM += d[i]-d[i+1];
				if(d[i]-d[i+1] > MX) MX = d[i]-d[i+1];
			}
		}
		for(i = 1; i < N; i++) ANS2 += MIN(MX, d[i]);
		printf("Case #%d: %d %d\n", t, SUM, ANS2);
	}
	return 0;
}