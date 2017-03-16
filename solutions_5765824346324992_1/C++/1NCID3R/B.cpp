#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

int array[10000];
int b,n;

ii sorter[10000];

long long f(long long tm)
{
	long long total = 0;
	for(int i=0; i<b; i++)
	{
		total += (tm+array[i]-1)/array[i];
	}

	return total;
}

int main()
{
	int t;
	scanf("%d",&t);

	for(int casenum=1; casenum<=t; casenum++)
	{
		scanf("%d %d",&b,&n);

		for(int i=0; i<b; i++)
		{
			scanf("%d",array+i);
		}

		printf("Case #%d: ",casenum);

		if(n<=b)
		{
			printf("%d\n",n);
			continue;
		}
		long long tm = 1;
		while(1)
		{
			//check how many customers
			long long total = f(tm);

			if(total<n-1)
				tm <<= 1;
			else
				break;
		}
		//printf("[%lld]",tm);
		//puts("HURRAH");

		long long add = tm>>1;
		while(add)
		{
			long long total = f(tm);

			if(total<n-1)
			{
				tm += add;
			}
			else if(total>=n)
			{
				tm -= add;
			}
			else
			{
				break;
			}
			add >>= 1;
		}

		long long total = f(tm);
		if(total>=n)
			tm--;

		//printf("%lld\n",tm);

		int minimum = 1<<30;
		int ans = -1;
		for(int i=0; i<b; i++)
		{
			int modded = tm%array[i];
			int temp = (array[i]-modded)%array[i];
			sorter[i] = ii(temp,i+1);
		}

		sort(sorter,sorter+b);
		total = f(tm);
		int goal = n-total-1;
		printf("%d\n",sorter[goal].second);

		//printf("%d\n",ans);
	}
}