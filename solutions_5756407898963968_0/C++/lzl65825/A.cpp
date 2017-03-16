#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;
int T,ans1,ans2,map1[10][10],map2[10][10];
bool vis[20];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int i,j;
	scanf("%d",&T);
	for (int ii=1;ii<=T;++ii)
	{
		bool flag1=0,flag2=0;
		int ans;
		scanf("%d",&ans1);
		for (i=1;i<=4;++i)
			for (j=1;j<=4;++j)
				scanf("%d",&map1[i][j]);
		scanf("%d",&ans2);
		for (i=1;i<=4;++i)
			for (j=1;j<=4;++j)
				scanf("%d",&map2[i][j]);
		memset(vis,0,sizeof(vis));
		for (i=1;i<=4;++i)
			vis[map1[ans1][i]]=1;
		for (i=1;i<=4;++i)
		{
			if (vis[map2[ans2][i]])
			{
				if (flag1)
					flag2=1;
				else
					flag1=1,ans=map2[ans2][i];
			}
		}
		printf("Case #%d: ",ii);
		if (flag2)
		{
			puts("Bad magician!");
			continue;
		}
		if (!flag1)
		{
			puts("Volunteer cheated!");
			continue;
		}
		printf("%d\n",ans);
	}
	//system("pause");
	return 0;
}
