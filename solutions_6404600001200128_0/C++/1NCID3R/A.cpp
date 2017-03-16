#include <cstdio>
#include <algorithm>
using namespace std;

int array[10000];

int main()
{
	int t;
	scanf("%d",&t);

	for(int casenum=1; casenum<=t; casenum++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
			scanf("%d",array+i);

		printf("Case #%d: ",casenum);
		//first method
		int curr = 0;
		int total = 0;
		for(int i=0; i<n; i++)
		{
			if(curr<array[i])
				curr = array[i];
			else
			{
				total += curr-array[i];
				curr = array[i];
			}
		}

		printf("%d ",total);

		//second method
		int maximum = 0;
		for(int i=1; i<n; i++)
		{
			maximum = max(maximum,array[i-1]-array[i]);
		}
		total = 0;
		for(int i=1; i<n; i++)
		{
			total += min(array[i-1],maximum);
		}

		printf("%d\n",total);
	}

	return 0;
}