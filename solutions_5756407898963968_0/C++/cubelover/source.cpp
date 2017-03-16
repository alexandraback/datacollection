#include<cstdio>

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int tc,tcn;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++)
	{
		int a[20];
		int i,j,k,t;
		for(i=1;i<=16;i++)a[i]=0;
		scanf("%d",&k);
		for(i=1;i<=4;i++)for(j=1;j<=4;j++)
		{
			scanf("%d",&t);
			if(i==k)a[t]++;
		}
		scanf("%d",&k);
		for(i=1;i<=4;i++)for(j=1;j<=4;j++)
		{
			scanf("%d",&t);
			if(i==k)a[t]++;
		}
		k=0;
		for(i=1;i<=16;i++)if(a[i]==2)
		{
			k++;
			t=i;
		}
		if(k>1)printf("Case #%d: Bad magician!\n",tc);
		if(k<1)printf("Case #%d: Volunteer cheated!\n",tc);
		if(k==1)printf("Case #%d: %d\n",tc,t);
	}
}