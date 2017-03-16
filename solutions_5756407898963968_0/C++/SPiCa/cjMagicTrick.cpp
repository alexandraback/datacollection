#include <cstdio>
int cas,i,j,t1,t2,a[9],b[9],no,o[99],CAS,x;

int main()
{
//	freopen("input.in","r",stdin);
//	freopen("output.out","w",stdout);
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&t1);
		for (i=1; i<=4; ++i)
		for (j=1; j<=4; ++j)
		{
			scanf("%d",&x);
			if (i==t1) a[j]=x;
		}
		scanf("%d",&t2);
		for (i=1; i<=4; ++i)
		for (j=1; j<=4; ++j)
		{
			scanf("%d",&x);
			if (i==t2) b[j]=x;
		}
		no=0;
		for (i=1; i<=4; ++i)
		for (j=1; j<=4; ++j)
		if (a[i]==b[j]) o[++no]=a[i];
		printf("Case #%d: ",++CAS);
		if (no==1) printf("%d\n",o[1]); else
		if (no==0) printf("Volunteer cheated!\n"); else printf("Bad magician!\n");
	}
	return 0;
}
