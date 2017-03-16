#include <bits/stdc++.h>
using namespace std;
long long int ccw(pair<long long int, long long int> p1, pair<long long int, long long int> p2, pair<long long int, long long int> p3)
{
  return (p2.first - p1.first)*(p3.second - p1.second) - (p2.second - p1.second)*(p3.first - p1.first);
}
pair<long long int, long long int> points[3005];
int main()
{
	int tc;
	scanf("%d",&tc);
	for(int t = 1;t<=tc;t++)
	{
		printf("Case #%d:\n",t);
		int n;
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
		{
			scanf("%lld%lld",&points[i].first,&points[i].second);
		}
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		for(int i = 0;i<n;i++)
		{
			int mini = 1000000000;
			for(int j = 0;j<n;j++)
			{
				if(i!=j)
				{
					int sum=0;
					for(int k = 0;k<n;k++)
					{
						if(k!=i && k!=j)
						{
							if(ccw(points[i],points[j],points[k])<=0)
							{
								sum++;
							}
						}
					}
					mini = min(mini,sum);
					mini = min(mini,n-2-sum);
				}
			}
			printf("%d\n",mini);
		}
	}
	return 0;
}
