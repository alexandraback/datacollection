#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct str {
	int c, n;
};

char ss[111], c[111][111];
int len[111], n[111][111], nn[111];

int main() {
	int T, N, l, i, j, ans;
	char ch, *p;
	bool able;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(len, 0, sizeof(len));
		memset(c, 0, sizeof(c));
		memset(n, 0, sizeof(n));
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			scanf("%s", ss);
			for (p = ss; *p; p++) {
				if (len[i] == 0) {
					c[i][0] = *p;
					n[i][0]++;
					len[i]++;
				} else if (*p == c[i][len[i] - 1]) {
					n[i][len[i] - 1]++;
				} else {
					c[i][len[i]] = *p;
					n[i][len[i]]++;
					len[i]++;
				}
			}
		}
		printf("Case #%d: ", t);
		l = len[0];
		able = true;
		for (i = 1; i < N; i++) {
			if (len[i] != l) {
				able = false;
				break;
			}
		}
		if (!able) {
			puts("Fegla Won");
			continue;
		}
		for (i = 0; i < l && able; i++) {
			ch = c[0][i];
			for (j = 1; j < N; j++) {
				if (c[j][i] != ch) {
					able = false;
					break;
				}
			}
		}
		if (!able) {
			puts("Fegla Won");
			continue;
		}
		ans = 0;
		for (i = 0; i < l; i++) {
			for (j = 0; j < N; j++) {
				nn[j] = n[j][i];
			}
			sort(nn, nn + N);
			for (j = 0; j < N / 2; j++) {
				ans += nn[N - j - 1] - nn[j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
