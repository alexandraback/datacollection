#include <stdio.h>
int tcase,r,c,n,a[18][18],min;
void f(int x,int y,int cnt)
{
	int i,j,x2,y2,ans;
	if(x==r && y==c)
	{
		if(cnt==n)
		{
			ans=0;
			for(i=1;i<=r;i++)
			{
				for(j=1;j<=c;j++)
				{
					if(a[i][j] && a[i+1][j])
						ans++;
					if(a[i][j] && a[i][j+1])
						ans++;
				}
			}
			if(min>ans)
				min=ans;
		}
		return;
	}

	x2=x;
	y2=y+1;
	if(y2>c)
	{
		x2=x+1;
		y2=1;
	}

	f(x2,y2,cnt);
	if(cnt<n)
	{
		a[x2][y2]=1;
		f(x2,y2,cnt+1);
		a[x2][y2]=0;
	}
}
int main()
{
	int loop,i,j;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&tcase);
	for(loop=1;loop<=tcase;loop++)
	{
		scanf("%d %d %d",&r,&c,&n);
		min=2147483647;
		f(1,0,0);
		printf("Case #%d: %d\n",loop,min);
	}
	return 0;
}