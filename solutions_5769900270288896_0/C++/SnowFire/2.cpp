#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M, C;
bool grid[18][18];

int dfs(int left, int posx, int posy)
{
	int s=0;
	int best;
	
	if(left==0)
		return 0;

	if(posx>N || posy>M)
		return 10000000;

	grid[posx][posy]=1;
	s=grid[posx-1][posy] + grid[posx][posy-1];

	if(posy<M)
		best= s + dfs(left-1, posx, posy+1);
	else
		best= s + dfs(left-1, posx+1, 1);
	grid[posx][posy]=0;
	
	if(posy<M)
		return min(best, dfs(left, posx, posy+1));
	else
		return min(best, dfs(left, posx+1, 1));
}



int main()
{
	int T, t;

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &T);

	for(t=1; t<=T; t++)
	{
		scanf("%d %d %d", &N, &M, &C);
		printf("Case #%d: %d\n", t, dfs(C, 1, 1));
	}

	return 0;
}