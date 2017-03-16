#include<stdio.h>

int a[9][9];
int b[9][9];
int c,d;
int mark[20];
int main()
{
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small-attempt0.out","wt",stdout);
	int t;
	scanf("%d",&t);
	int i, j, k;
	int tt=0;
	while(t--)
	{
		tt++;
		scanf("%d",&c);
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				scanf("%d",&a[i][j]);
		scanf("%d",&d);
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				scanf("%d",&b[i][j]);
		c--;d--;
		for(i=0;i<20;i++)
			mark[i]=0;
		for(i=0;i<4;i++)
			mark[a[c][i]]++;
		for(i=0;i<4;i++)
			mark[b[d][i]]++;
		int mi, mj;
		mi = -22;
		for(i=0;i<20;i++)
			if(mark[i]==2)
			{
				if(mi<-3)mi=i;
				else mi = -1;
			}
			printf("Case #%d: ",tt);
		if(mi>=0) printf("%d\n",mi);
		else printf("%s\n",mi<-2?"Volunteer cheated!":"Bad magician!");


	}
}