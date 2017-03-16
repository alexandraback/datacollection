#include <stdio.h>
#include <complex>
#include <algorithm>
#include <math.h>
#define X(x) real(x)
#define Y(x) imag(x)
using namespace std;

typedef long long LL;
typedef complex<LL> P;

int n;
P inp[3010];
int srt[3010];

LL cross(P a, P b) {
	return X(a) * Y(b) - Y(a) * X(b);
}
LL cross(int a, int b) {
	return cross(inp[srt[a]] - inp[srt[0]], inp[srt[b]] - inp[srt[0]]);
}

bool cmp(int a, int b) {
	P p1 = inp[a] - inp[srt[0]];
	P p2 = inp[b] - inp[srt[0]];
	if (Y(p1) == 0 && Y(p2) == 0) {
		return X(p1) > X(p2);
	}
	if (Y(p1) * Y(p2) < 0) {
		return Y(p1) > Y(p2);
	}
	return cross(p1, p2) > 0;
}

int main() {
	int cas;
	scanf("%d", &cas);
	for (int ii=0; ii<cas; ii++) {
		scanf("%d", &n);
		for (int i=0; i<n; i++) {
			scanf("%lld%lld", &X(inp[i]), &Y(inp[i]));
		}
		printf("Case #%d:\n", ii+1);
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) srt[j] = j;
			swap(srt[i], srt[0]);
			sort(srt+1, srt+n, cmp);
			//for (int j=0; j<n; j++) printf("%d ", srt[j]);puts("");
			int ans = 0;
			int cur = 1;
			while (cross(1, cur) >= 0 && cur < n) cur++;
			for (int j=1; j<n; j++) {
				if (j > 1) {
					while(cur < j+n-1 && cross(j, (cur-1)%(n-1)+1) >= 0) {
						cur++;
					}
				}
				ans = max(ans, cur - j);
			}
			printf("%d\n", n-1-ans);
		}
	}
	return 0;
}