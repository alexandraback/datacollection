#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 20;

int r, c, n, ans;
bool v[N][N];

void dfs(int x, int y, int calc = 0){

	if (calc == n){
		int tmp = 0;
		for (int i = 1; i <= r; ++ i)
			for (int j = 1; j <= c; ++ j)
				if (v[i][j]){
					if (v[i][j + 1]) ++ tmp;
					if (v[i + 1][j]) ++ tmp;
				}
		if (tmp < ans || ans == -1) ans = tmp;
		return;
	}
	if (x > r) return;
	
	y == c ? dfs(x + 1, 1, calc) : dfs(x, y + 1, calc);

	v[x][y] = 1;
	y == c ? dfs(x + 1, 1, calc + 1) : dfs(x, y + 1, calc + 1);
	v[x][y] = 0;
}

int main(){

	int tcase; scanf("%d", &tcase);
	for (int t = 1; t <= tcase; ++ t){
		scanf("%d%d%d", &r, &c, &n);
		ans = -1;
		dfs(1, 1);
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}
