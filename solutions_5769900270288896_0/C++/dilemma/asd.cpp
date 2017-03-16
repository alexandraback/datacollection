#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int a[105][105];
int main(void)
{
	int i,j,u,p,n,m,r,c,x,y,uu,vv,pi,qi,sum,ans,M;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&pi);
	for(qi=1;qi<=pi;qi++)
	{
		scanf("%d%d%d",&r,&c,&m);
		if(m==0)
		{
			printf("Case #%d: 0\n",qi);
		}
		else
		{
			n=r*c;
			M=(1<<n);
			u=(1<<m)-1;
			ans=(1<<29);
			while(u<M)
			{
				p=u;
				for(i=1;i<=n;i++)
				{
					uu=(i-1)/c+1;
					vv=(i-1)%c+1;
					a[uu][vv]=p%2;
					p/=2;
				}
				sum=0;
				for(i=1;i<=r;i++)
				{
					for(j=1;j<=c;j++)
					{
						if(a[i][j]==1)
						{
							if((i>1)&&(a[i-1][j]==1))
							{
								sum++;
							}
							if((i<r)&&(a[i+1][j]==1))
							{
								sum++;
							}
							if((j>1)&&(a[i][j-1]==1))
							{
								sum++;
							}
							if((j<c)&&(a[i][j+1]==1))
							{
								sum++;
							}
						}
					}
				}
				sum/=2;
				ans=sum<ans?sum:ans;
				x=u&-u;
				y=u+x;
				u=((u&~y)/x>>1)|y;
			}
			printf("Case #%d: %d\n",qi,ans);
		}
	}
	return 0;
}