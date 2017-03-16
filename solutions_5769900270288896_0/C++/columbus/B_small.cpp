#include <cstdio>
#include <algorithm>
#define MAX 20
#define INF 1 << 30
using namespace std;

int grid[MAX][MAX], r, c, n;

int check() {
	int cost = 0;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(grid[i][j] == 1) {
				if(j + 1 < c && grid[i][j+1] == 1) cost++;
				if(i + 1 < r && grid[i+1][j] == 1) cost++; 
			}
		}
	}
	return cost;
}

int brute(int x, int y, int m) {
	if(m == 0) {
		return check();
	} else {
		if(x == c){
			if(y != r - 1) return brute(0, y + 1, m);
			else return INF;
		} else {
			int res = brute(x+1, y, m);
			grid[y][x] = 1;
			res = min(res, brute(x+1, y, m-1));
			grid[y][x] = 0;
			return res;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		scanf("%d%d%d", &r, &c, &n);
		printf("Case #%d: %d\n", i, brute(0,0,n));
	}
	return 0;
}