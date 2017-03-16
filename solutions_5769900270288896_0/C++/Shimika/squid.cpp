#include <stdio.h>
#include <memory.h>
using namespace std;

int r, c, n;
int a[19][19];

int mx = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void check() {
	int cnt = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (a[i][j]) {
				for (int k = 0; k < 4; k++) {
					int tx = i + dx[k];
					int ty = j + dy[k];
					cnt += a[tx][ty];
				}
			}
		}
	}

	if (mx > cnt / 2) {
		mx = cnt / 2;
	}
}

void recall(int lev, int cnt) {
	if (lev >= r * c) {
		if (cnt == n) {
			check();
		}
	}
	else {
		a[lev / c + 1][lev % c + 1] = 0;
		recall(lev + 1, cnt);
		a[lev / c + 1][lev % c + 1] = 1;
		recall(lev + 1, cnt + 1);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		memset(a, 0, sizeof(a));
		scanf("%d %d %d", &r, &c, &n);

		mx = 1000000000;
		recall(0, 0);
		printf("Case #%d: %d\n", t, mx);
	}
}