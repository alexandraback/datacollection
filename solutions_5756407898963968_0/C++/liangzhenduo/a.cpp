#include<cstdio>
#include<cstring>
bool b[20];
int main()
{
	int T;
	scanf("%d",&T);
	for(int tcase=1; tcase<=T;tcase++)
	{
		memset(b,0,sizeof(b));
		int ans=-1;
		int n,cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
			{
				int t;
				scanf("%d",&t);
				if(i==n)b[t]=1;
			}
		scanf("%d",&n);
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
			{
				int t;
				scanf("%d",&t);
				if(i==n)
				{
					if(b[t])
					{
						ans=t;
						cnt++;
					}
				}
			}
		printf("Case #%d: ",tcase);
		if(cnt>1)printf("Bad magician!\n");
		else if(cnt<1)printf("Volunteer cheated!\n");
		else printf("%d\n",ans);
	}
}
