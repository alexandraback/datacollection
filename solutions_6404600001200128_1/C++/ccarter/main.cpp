#include <iostream>
#include <cstdio>
using namespace std;
int nums[10000];
int main()
{
    int tt,tc,n;
    scanf("%d",&tt);
    for (tc=1;tc<=tt;tc++)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d",&nums[i]);
		int s1=0,s2=0,maxrate=0;
		for (int i=1;i<n;i++)
		{
			if (nums[i]<nums[i-1])
			{
				s1+=nums[i-1]-nums[i];
				if (nums[i-1]-nums[i]>maxrate)
					maxrate=nums[i-1]-nums[i];

			}

		}
		for (int i=0;i<n-1;i++)
			if (nums[i]>maxrate)
				s2+=maxrate;
			else
				s2+=nums[i];
		printf("Case #%d: %d %d\n",tc,s1,s2);
	}
    return 0;
}
