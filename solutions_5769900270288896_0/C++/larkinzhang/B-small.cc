#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int T, R, C, N;
bool map[128][128];
int ans, test;


void DFS(int x, int y, int rest_rec, int rest_p, int cur) {
	if (rest_rec < rest_p) return;
	if (y > C) DFS(x + 1, 1, rest_rec, rest_p, cur);
	else if (x > R) {
		if (cur < ans) ans = cur;
	} else {

		DFS(x, y + 1, rest_rec - 1, rest_p, cur);

		map[x][y] = true;
		if (map[x - 1][y]) cur++;
		if (map[x][y - 1]) cur++;
		DFS(x, y + 1, rest_rec - 1, rest_p - 1, cur);
		map[x][y] = false;
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &R, &C, &N);

		ans = INT_MAX;
		DFS(1, 1, R * C, N, 0);

		printf("Case #%d: %d\n", ++test, ans);
	}

	return 0;
}
