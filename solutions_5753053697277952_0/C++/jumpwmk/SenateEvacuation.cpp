#include <stdio.h>
#include <algorithm>

using namespace std;

int x[30];

int main()
{
	bool check;
	freopen("../test.in","r",stdin);
	freopen("../test.out","w",stdout);
	int i,j,t,n,loop,sum,mx,ii,res;
	scanf("%d",&t);
	for(loop = 1;loop <= t;loop++)
	{
		printf("Case #%d: ",loop);
		scanf("%d",&n);
		sum = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x[i]);
			sum += x[i];
		}
		while(sum > 0)
		{
			mx = 0;
			for(i=0;i<n;i++)
			{
				if(mx < x[i])
				{
					mx = x[i];
					ii = i;
				}
			}
			printf("%c",ii+'A');
			x[ii]--;
			sum--;
			if(sum == 2)
			{
				printf(" ");
				continue;
			}
			mx = 0;
			check = false;
			for(i=0;i<n;i++)
			{
				if(mx < x[i])
				{
					mx = x[i];
					ii = i;
				}
			}
			// res = sum-1;
			// for(i=0;i<n;i++)
			// {
			// 	if(i != ii)
			// 	{
			// 		if(x[i] > res/2)
			// 			check = true;
			// 	}
			// }
			// if(check)
			// 	continue;
			printf("%c",ii+'A');
			sum--;
			x[ii]--;
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}