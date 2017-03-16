#include <stdio.h>

int row, col, n;

int numOf(int x)
{
	int ret = 0;
	for(;x;x>>=1) ret += x&1;
	return ret;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);

	int tcn;
	scanf("%d",&tcn);

	for(int tc=1;tc<=tcn;tc++)
	{
		scanf("%d%d%d",&row,&col,&n);

		int tot = 1<<(row*col), ans = row*col*10;
		for(int x=0;x<tot;x++)
		{
			if( numOf(x) != n ) continue;

			int prev=0, now=0, i=0, t=x, cost = 0;
			for(int r=0;r<row;r++)
			{
				prev = now;
				now = 0;
				for(int c=0;c<col;c++)
				{
					if( c && now&1 && t&1 ) cost++;
					now = (now<<1) | (t&1);
					t>>=1;
				}
				cost += numOf(prev&now);
			}

			if( cost < ans )
			{
				ans = cost;
			}
		}

		printf("Case #%d: %d\n",tc,ans);
	}

	return 0;
}