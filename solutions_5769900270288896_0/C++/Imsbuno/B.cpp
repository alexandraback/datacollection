#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
using namespace std;

typedef long long int64;

int M, N, T, ans;
int a[55][55];

void dfs(int x, int y, int z) {
	if (z < 0) return;
	if (y >= N) {
		x++;
		y = 0;
	}
	if (x == M) {
		if (z != 0) return;
		int now = 0;
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j) {
				if (i < M && a[i][j] && a[i + 1][j]) ++now;
				if (j < N && a[i][j] && a[i][j + 1]) ++now;
			}
		ans = min(ans, now);
		return;
	}
	dfs(x, y + 1, z);
	a[x][y] = 1;
	dfs(x, y + 1, z - 1);
	a[x][y] = 0;
}

int main() {
	int testCase;
	scanf("%d", &testCase);
	for (int test = 1; test <= testCase; ++test) {
		scanf("%d%d%d", &M, &N, &T);
		ans = 1 << 30;
		memset(a, 0, sizeof(a));
		dfs(0, 0, T);
		printf("Case #%d: %d\n", test, ans);
	}
}