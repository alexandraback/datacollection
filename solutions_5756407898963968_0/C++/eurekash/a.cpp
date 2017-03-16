#include <cstdio>

int a[4][4],b[4][4],aa,ab;

int main()
{
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		scanf("%d",&aa);aa--;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++) scanf("%d",a[i]+j);
		scanf("%d",&ab);ab--;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++) scanf("%d",b[i]+j);
		int n=0,ans=0;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			if(a[aa][i]==b[ab][j]) n++,ans=a[aa][i];
		printf("Case #%d: ",tt);
		if(n==0)  puts("Volunteer cheated!");
		else if(n>1)  puts("Bad magician!");
		else printf("%d\n",ans);
	}
	return 0;
}
