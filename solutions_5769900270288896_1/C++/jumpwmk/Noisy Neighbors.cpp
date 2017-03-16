#include <stdio.h>
#include <string.h>

using namespace std;

int x[10100][10100];
int chk[10100][10100];

int main()
{
	int i,j,r,c,n,k,q,max,chki,chkj,cnt;
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&q);
	for(k=1;k<=q;k++)
	{
		cnt=0;
		scanf("%d %d %d",&r,&c,&n);
		for(i=1;i<=r+2;i++)
		{
			for(j=1;j<=c+2;j++)
			{
				x[i][j]=0;
				chk[i][j]=0;
			}
		}
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				x[i][j]=1;
			}
		}
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(x[i-1][j]==1)
					chk[i][j]++;
				if(x[i+1][j]==1)
					chk[i][j]++;
				if(x[i][j-1]==1)
					chk[i][j]++;
				if(x[i][j+1]==1)
					chk[i][j]++;
			}
		}
		n=(r*c)-n;
		while(n--)
		{
			max=-1;
			for(i=1;i<=r;i++)
			{
				for(j=1;j<=c;j++)
				{
					if(chk[i][j]>max)
					{
						max=chk[i][j],chki=i,chkj=j;
					}
				}
			}
			chk[chki][chkj]=0;
			x[chki][chkj]=0;
			if(chk[chki][chkj-1])
				chk[chki][chkj-1]--;
			if(chk[chki][chkj+1])
				chk[chki][chkj+1]--;
			if(chk[chki-1][chkj])
				chk[chki-1][chkj]--;
			if(chk[chki+1][chkj])
				chk[chki+1][chkj]--;
		}
		// for(i=1;i<=r;i++)
		// {
		// 	for(j=1;j<=c;j++)
		// 	{
		// 		printf("%d ",x[i][j]);
		// 	}
		// 	printf("\n");
		// }
		cnt=0;
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(x[i][j]&&x[i+1][j])
					cnt++;
				if(x[i][j]&&x[i][j+1])
					cnt++;
			}
		}
		printf("Case #%d: %d\n",k,cnt);
	}
	return 0;
}