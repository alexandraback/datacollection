#include<bits/stdc++.h>
using namespace std;
int m[10005];
int main()
{
	int tc;
	scanf("%d",&tc);
	for(int cas = 1;cas<=tc;cas++)
	{
		int n;
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&m[i]);
		}
		int sumdiff=0,maxdiff=0,second=0;
		for(int i = 1;i<n;i++)
		{
			if(m[i-1]>m[i])
			{
				sumdiff += m[i-1]-m[i];
				maxdiff = max(maxdiff,m[i-1]-m[i]);
			}
		}
		for(int i = 0;i<n-1;i++)
		{
			second += min(m[i],maxdiff);
		}
		printf("Case #%d: %d %d\n",cas,sumdiff,second);
	}
	return 0;
}
