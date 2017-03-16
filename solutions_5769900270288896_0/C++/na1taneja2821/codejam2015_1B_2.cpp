#include <bits/stdc++.h>
using namespace std;
int grid[100][100] = {0, 0};
int visited[100][100] = {0, 0};
int finalans;
void brute(int x, int y, int left, int r, int c) {
	if(x < 1 || y < 1 || x > r || y > c) {
		return;
	}
	if(visited[x][y] == 1) {
		return;
	}
	if(left < 0) {
		return;
	}
	//printf("%d %d %d\n", x, y, left);
	grid[x][y] = 1;
	if(left == 0) {
		//printf("yo\n");
		int i, j;
		int ans = 0;
		for(i = 1; i <= r; i++) {
			for(j = 1; j <= c; j++) {
				//cout << grid[i][j];
				if(grid[i][j] == 1) {
					if(grid[i - 1][j] == 1) {
						ans++;
					} 
					if(grid[i + 1][j] == 1) {
						ans++;
					}
					if(grid[i][j - 1] == 1) {
						ans++;
					}
					if(grid[i][j + 1] == 1) {
						ans++;
					}
				}
			}
			//cout << endl;
		}
		//cout << ans;
		ans = ans / 2;
		finalans = min(ans, finalans);
	}
	visited[x][y] = 1;
	brute(x + 1, y, left - 1, r, c);
	brute(x - 1, y, left - 1, r, c);
	brute(x, y + 1, left - 1, r, c);
	brute(x, y - 1, left - 1, r, c);
	grid[x][y] = 0;
	brute(x + 1, y, left, r, c);
	brute(x - 1, y, left, r, c);
	brute(x, y + 1, left, r, c);
	brute(x, y - 1, left, r, c);
	visited[x][y] = 0;
}
int main() {
	int t; 
	cin >> t;
	int run;
	for(run = 1; run <= t; run++) {
		memset(grid, 0, sizeof(grid));
		memset(visited, 0, sizeof(visited));
		int r, c, n;
		cin >> r >> c >> n;
		if(n == 0)
		{
			finalans = 0;
		} else {
			finalans = INT_MAX;
			brute(1, 1, n - 1, r, c);	
		}
		printf("Case #%d: %d\n", run, finalans);
	}
	return 0;
}