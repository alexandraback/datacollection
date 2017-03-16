#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int T, n, ans;
char s[105][105];

struct node {
	char c;
	int i;
}a[105][105];
int l[105];

bool valid() {
	for (int i = 1; i < n; ++i) {
		if (l[0] != l[i]) return false;
		for (int j = 0; j < l[i]; ++j) {
			if (a[0][j].c != a[i][j].c) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s[i]);
			l[i] = 0;
			for (int j = 0, k = strlen(s[i]); j < k; ++j) {
				if (j == 0 || s[i][j] != s[i][j-1]) {
					a[i][l[i]].c = s[i][j];
					a[i][l[i]].i = 0;
					l[i]++;
				}
				a[i][l[i]-1].i++;
			}
		}
		printf("Case #%d: ", tc);
		if (valid()) {
			ans = 0;
			for (int i = 0; i < l[0]; ++i) {
				int mi = (int)(1e8);
				for (int j = 1; j <= 100; ++j) {
					int tmp = 0;
					for (int k = 0; k < n; ++k) {
						tmp += abs(a[k][i].i - j);
					}
					mi = min(mi, tmp);
				}
				ans += mi;
			}
			printf("%d\n", ans);
		}
		else {
			printf("Fegla Won\n");
		}
	}
	return 0;
}