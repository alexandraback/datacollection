/*
 * gcja/win.cpp
 * Created on: 2014-5-4
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;

int tot, n;
char c[110], f[110][110];
int b[110], p[110][110];

int deal() {
	sort(b, b + n);
	int mid = n / 2, s = 0;
	for (int i = 0; i < n; i++) {
		s = s + abs(b[i] - b[mid]);
	}
	return s;
}

int solve() {
	tot = 0;
	memset(p, 0, sizeof(p));
	int len = strlen(f[0]);
	for (int i = 0; i < len; i++) {
		c[tot] = f[0][i];
		int s = 1;
		while (i + 1 < len && f[0][i + 1] == f[0][i]) {
			i++, s++;
		}
		p[0][tot++] = s;
	}

	for (int i = 1; i < n; i++) {
		int len1 = strlen(f[i]), k = 0;
		for (int j = 0; j < len1; j++) {
			if (f[i][j] != c[k]) {
				return -1;
			}
			int s = 1;
			while (j + 1 < len1 && f[i][j + 1] == f[i][j]) {
				j++, s++;
			}
			p[i][k++] = s;
		}
		if (k != tot) {
			return -1;
		}
	}

	int ans = 0;
	for (int i = 0; i < tot; i++) {
		for (int j = 0; j < n; j++) {
			b[j] = p[j][i];
		}
		ans += deal();
	}
	printf("%d\n", ans);
	return 1;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", f[i]);
		}
		int t = solve();
		if (t == -1) {
			printf("Fegla Won\n");
		}
	}
	return 0;
}
