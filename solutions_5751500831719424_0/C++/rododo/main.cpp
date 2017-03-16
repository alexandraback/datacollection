#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char strings[110][110];
char *p[110];
int tmp[110];
long long ans;
int N;

void count() {
	sort(tmp, tmp + N);
	long long mid = tmp[N >> 1];
	for (int i = 0; i < N; i++)
		ans += abs(tmp[i] - mid);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, TC;
	scanf("%d", &T);
	TC = T;
	while (TC--) {
		ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s", strings[i]);
			p[i] = strings[i];
		}
		for (;;) {
			int i = 0;
			for (i = 0; i < N; i++)
				if (*p[0] != *p[i]) {
					printf("Case #%d: Fegla Won\n", T - TC);
					break;
				}
			if (i != N)
				break;
			if (*p[0] == '\0') {
				printf("Case #%d: %lld\n", T - TC, ans);
				break;
			}
			memset(tmp, 0, sizeof(tmp));
			for (i = 0; i < N; i++) {
				tmp[i]++;
				while (*p[i] == *(p[i] + 1)) {
					tmp[i]++;
					p[i]++;
				}
				p[i]++;
			}
			count();
		}
	}
}
