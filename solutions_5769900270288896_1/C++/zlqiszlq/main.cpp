#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int R,C,N,T;

bool G[16][16];

int calc()
{
	int i,j;
	int cnt = 0;
	for (i=0;i<R-1;++i)
	{
		for (j=0;j<C;++j)
		{
			if (G[i][j] && G[i+1][j])
			{
				cnt ++;
			}
		}
	}
	for (j=0;j<C-1;++j)
	{
		for (int i=0;i<R;++i)
		{
			if (G[i][j] && G[i][j+1])
			{
				cnt ++;
			}
		}
	}
	return cnt;
}

int Ans;

void dfs(int idx, int nleft)
{
	if (idx == R * C)
	{
		Ans = min(Ans, calc());
	}
	int c = idx % C, r = idx / C;
	if (R*C - idx -1 >= nleft)
	{
		G[r][c] = false;
		dfs(idx +1, nleft);
	}
	if (nleft)
	{
		G[r][c] = true;
		dfs(idx +1, nleft-1);
	}
}

int main()
{
    int i,j,k;
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++)
	{
		scanf("%d%d%d",&R,&C,&N);
		int d = N - (R*C+1)/2;
		if (d <= 0)
		{
			Ans = 0;
		}
		else
		{
			if ((R & 1) && (C & 1))
			{
				if (d < R + C - 3)
				{
					Ans = 3 * d;
				}
				else
				{
					Ans = 4 * d - C - R + 2;
				}
			}
			else //if ( !(R & 1) && !(C & 1))
			{
				if (d < R + C - 2)
				{
					if (d == 1)
					{
						Ans = 2;
					}
					else
					{
						Ans = 3 * d - 2;
					}
				}
				else
				{
					Ans = 4 * d - C - R;
				}
			}
			
		}
		printf("Case #%d: %d\n",cases,Ans);
	}
    return 0;
}
