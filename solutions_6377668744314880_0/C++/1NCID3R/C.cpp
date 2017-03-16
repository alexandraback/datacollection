#include <cstdio>
#include <utility>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<int,int> ii;

ii array[3000];
bool cut[3000];

long long ccw(ii a, ii b, ii c)
{
	ii v1 = ii(b.first-a.first,b.second-a.second);
	ii v2 = ii(c.first-b.first,c.second-b.second);
	return (long long)v1.first*v2.second - (long long)v1.second*v2.first;
}

int main()
{
	int t;
	scanf("%d",&t);

	for(int casenum=1; casenum<=t; casenum++)
	{
		int n;
		scanf("%d",&n);

		for(int i=0; i<n; i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			array[i] = ii(x,y);
		}


		printf("Case #%d:\n",casenum);
		if(n==1)
		{
			puts("0");
			continue;
		}
		for(int i=0; i<n; i++)
		{
			int minimum = n;
			for(int j=0; j<n; j++)
			{
				if(i==j)
					continue;
				int t1 = 0;
				int t2 = 0;
				for(int k=0; k<n; k++)
				{
					if(i==k || j==k)
						continue;
					long long a = ccw(array[j],array[i],array[k]);
					if(a<0)
						t1++;
					else if(a>0)
						t2++;
				}
				minimum = min(minimum,min(t1,t2));
			}

			printf("%d\n",minimum);
		}
	}
}