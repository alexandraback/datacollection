#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int maxn = 20;
const int maxs = 1 << 17;
int r, c;
int n;
int f[maxn][maxn][maxs];
int cnt[maxs];
int tot[maxs];

void work() {
	memset(f, 0x3f, sizeof(f));
	f[0][0][0] = 0;
	for (int i=0;i<r;i++) {
		for (int j=0;j<=n;j++) {
			for (int s1=0;s1<(1<<c);s1++) {
				if (f[i][j][s1] == 0x3f3f3f3f) continue;
				for (int s2=0;s2<(1<<c);s2++) {
					if (cnt[s2] + j > n) continue;
					f[i + 1][cnt[s2] + j][s2] = min(f[i + 1][cnt[s2]+j][s2], f[i][j][s1] + tot[s2] + cnt[s1 & s2]);
				}
			}
		}
	}
	int ans = 0x3f3f3f3f;
	for (int s=0;s<(1<<c);s++) ans = min(ans, f[r][n][s]);
	printf("%d\n", ans);
}

void pre() {
	cnt[0] = 0;
	for (int i=1;i<maxs;i++) {
		cnt[i] = cnt[i>>1] + (i & 1);
	}
	tot[0] = 0;
	for (int i=1;i<maxs;i++) {
		tot[i] = tot[i>>1] + (i & 1 & (i >> 1));
	}
}

int main() {
	pre();
	int T;
	int cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &r, &c, &n);
		printf("Case #%d: ", ++cas);
		if (r < c) swap(r, c);
		work();
	}
	return 0;
}
