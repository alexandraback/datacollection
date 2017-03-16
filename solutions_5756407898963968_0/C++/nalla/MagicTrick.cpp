#include <stdio.h>
#include <string.h>

using namespace std;
int main()
{
	int t,i,j,k,a[17],tc,ans,temp;
	scanf("%d",&tc);
	for(t=1;t<=tc;t++)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&ans);

		for(i=1;i<=4;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%d",&temp);
				if(i==ans){a[temp]=1;}
			}
		}

		int cnt=0,res;
		scanf("%d",&ans);
		
		for(i=1;i<=4;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%d",&temp);
				if(i==ans)
				{
					if(a[temp]==1){cnt++;res=temp;}
				}
			}
		}

		if(cnt==0){printf("Case #%d: Volunteer cheated!\n",t);continue;}
		if(cnt==1){printf("Case #%d: %d\n",t,res);continue;}
		if(cnt>1){printf("Case #%d: Bad magician!\n",t);continue;}

	}
	return 0;
}
