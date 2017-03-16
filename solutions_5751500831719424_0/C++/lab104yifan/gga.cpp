#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define INF 0x3f3f3f3f
const int N = 105;

int t, n, i, j, ans;
struct SB {
	char str[N];
	int v;
} s[N];

bool check() {
	for (int i = 0; i < n; i++) {
		if (s[i].v < strlen(s[i].str))
			return true;
	}
	return false;
}

bool judge() {
	while (check()) {
		int save[N], i;
		memset(save, 0, sizeof(save));
		char c = s[0].str[s[0].v];
		for (i = 0; i < n; i++) {
			int num = 0;
			if (s[i].str[s[i].v] != c) return false;
			while (s[i].str[s[i].v] == c) {
				s[i].v++;
				num++;
			}
			save[i] = num;
		}
		sort(save, save + n);
		int mid = save[n / 2];
		for (i = 0; i < n; i++)
			ans += abs(save[i] - mid);
	}
	return true;
}

int main() {
	scanf("%d", &t);
	int cas = 0;
	while (t--) {
		memset(s, 0, sizeof(s));
		ans = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%s", s[i].str);
			s[i].v = 0;
		}
		printf("Case #%d: ", ++cas);
		if (!judge()) printf("Fegla Won\n");
		else printf("%d\n", ans);
	}
	return 0;
}