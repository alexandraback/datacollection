#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int table[100][100], rec[10000];
int n, r, c, mini;

int cal() {
	int ct = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; ++j) {
			if (table[i][j]) {
				if (i + 1 < r && table[i + 1][j] == 1) {
					ct++;
				}
				if (j + 1 < c && table[i][j + 1] == 1) {
					ct++;
				}
			}
		}
	}
	return ct;
}

void dfs(int x, int d) {
	if (d == n) {
		for (int i = 0; i < r * c; i++) {
			table[i / c][i % c] = rec[i];
		}
		mini = min(mini, cal());
		memset(table, 0, sizeof(table));
		return;
	}
	for (int i = x + 1; i < r * c; ++i) {
		if (!rec[i]) {
			rec[i] = 1;
			dfs(i, d + 1);
			rec[i] = 0;
		}
	}
}

int main() {
	int t, tc = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &r, &c, &n);
		mini = 1e9;
		dfs(-1, 0);
		printf("Case #%d: %d\n", ++tc, mini);
	}
	return 0;
}