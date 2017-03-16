#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<string>
#include<iostream>
#include<vector>
#define LL long long
using namespace std;

struct NODE
{
	int x, y;
	int ans;
};

int v[20][20][20];
int num[20][20], ans;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

void dfs(int x, int y, int xx, int yy, int cnt, int sum)
{
	if(sum >= ans)
	{
		return;
	}
	if((xx - x) * yy + yy - y + 1 < cnt)
	{
		return ;
	}
	if(cnt == 0)
	{
		ans = min(ans,sum);
		return;
	}
	num[x][y] = 1;
	int xs, ys, s = 0;
	for(int i = 0; i < 4; i ++)
	{
		xs = x + dir[i][0];
		ys = y + dir[i][1];
		if(num[xs][ys])
		{
			s ++;
		}
	}
	if(y == yy)
	{
		dfs(x+1,1,xx,yy,cnt-1,sum + s);
		num[x][y] = 0;
		dfs(x+1,1,xx,yy,cnt,sum);
	}
	else
	{
		dfs(x,y + 1,xx,yy,cnt-1,sum + s);
		num[x][y] = 0;
		dfs(x,y + 1,xx,yy,cnt,sum);
	}
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	for(int i = 2; i <= 16; i ++)
	{
		for(int j = 1; j <= 16; j ++)
		{
			for(int k = 1; k * k <= j; k ++)
			{
				if(j * k < i) continue;
				if(j % k == 0)
				{
					int x = k, y = j / k;
					ans = 100000;
					memset(num,0,sizeof(num));
					dfs(1,1,x,y,i,0);
					v[i][x][y] = v[i][y][x] = ans;
				}
			}
		}
	}
	int t;
	scanf("%d",&t);
	for(int ii = 1; ii <= t; ii ++)
	{
		int r, c, n;
		scanf("%d%d%d",&r,&c,&n);
		printf("Case #%d: %lld\n",ii,v[n][r][c]);
	}
	return 0;
}