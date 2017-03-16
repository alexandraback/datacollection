#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;

#define INF (1 << 30)

int R, C, N, grid[20][20];

int minUnhappiness(int x, int y, int qt){
	if(qt == N) return 0;

	if(y == C){
		y = 0;
		x++;
	}

	if(x == R){
		return INF;
	}

	grid[x][y] = 0;
	int notUse = minUnhappiness(x, y+1, qt);

	int use = 0;
	if(x > 0) use += grid[x-1][y];
	if(y > 0) use += grid[x][y-1];

	grid[x][y] = 1;
	use += minUnhappiness(x, y+1, qt+1);

	return min(notUse, use);
}

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output", "w", stdout);
	int tcase = 0;

	int T;
	scanf("%d", &T);

	while(T--){
		scanf("%d%d%d", &R, &C, &N);

		printf("Case #%d: %d\n", ++tcase, minUnhappiness(0, 0, 0));
	}
}