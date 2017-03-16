//============================================================================
// Name        : Contest.cpp
// Author      : Tarango Khan
// Team        : Byteheads
//============================================================================

#include <bits/stdc++.h>
using namespace std;

int res = 999999999;
int nCase, R, C, N;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int isValid(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C)
		return 0;
	return 1;
}

int visited[18][18];
void backtrack(int r, int c, int cnt, int point) {
	if (cnt == N) {
		res = min(res, point);
		return;
	}
	int i = r, j = c;
	while (true) {
		if (j >= C) {
			i++;
			j = 0;
		}
		if (i >= R)
			break;
		if (visited[i][j] == 0) {
			visited[i][j] = 1;
			int nw = point;
			for (int p = 0; p < 4; p++) {
				int xx = i + dx[p];
				int yy = j + dy[p];
				if (isValid(xx, yy) == 1 && visited[xx][yy] == 1)
					nw++;
			}
			backtrack(i, j + 1, cnt + 1, nw);
			visited[i][j] = 0;
		}
		j++;
	}
}

int main() {
	scanf("%d", &nCase);
	for (int cs = 1; cs <= nCase; cs++) {
		scanf("%d %d %d", &R, &C, &N);
		memset(visited, 0, sizeof(visited));
		res = 99999999;
		backtrack(0, 0, 0, 0);
		printf("Case #%d: %d\n", cs, res);
	}
	return 0;
}
