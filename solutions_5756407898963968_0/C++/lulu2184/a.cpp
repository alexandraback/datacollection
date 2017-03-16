#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T,ans1,ans2,TT,x,ans,cnt;
pair <int,int> row[20];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&ans1);
		for (int i=1;i<=4;i++)
		{
			for (int j=1;j<=4;j++)
			{
				scanf("%d",&x);
				row[x].first=i;
			}
		}
		scanf("%d",&ans2);
		for (int i=1;i<=4;i++)
		{
			for (int j=1;j<=4;j++)
			{
				scanf("%d",&x);
				row[x].second=i;
			}
		}
		cnt=0;
		for (int i=1;i<=16;i++)
		{
			if (row[i]==make_pair(ans1,ans2))
			{
				cnt++;
				ans=i;
			}
		}
		printf("Case #%d: ",++TT);
		if (cnt==0) printf("Volunteer cheated!\n");
		else if (cnt==1) printf("%d\n",ans);
		else printf("Bad magician!\n");
	}

	return 0;
}