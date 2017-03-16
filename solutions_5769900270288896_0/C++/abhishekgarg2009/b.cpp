#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <cstring>
using namespace std;
int main()
{
	int t,r,c,n,min1,max1,ans,temp;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		ans = 0;
		scanf("%d",&r);
		scanf("%d",&c);
		scanf("%d",&n);
		min1 = min(r,c);
		max1 = max(r,c);
		if(min1==1)
		{
			temp = (max1+1)/2;
			if(n<=temp)
			{
				ans = 0;
			}
			else
			{
				n = n - temp;
				if(max1%2==0)
				{
					n--;
					ans++;
					ans = ans + n*2;
				}
				else
				{
					ans = n*2;
				}
			}
		}
		else if(min1 == 2)
		{
			temp = max1;
			if(n<=temp)
			{
				ans = 0;
			}
			else
			{
				n = n - temp;
				if(n<=2)
				{
					ans = 2*n;
				}
				else
				{
					ans = 4 + (n-2)*3;
				}
			}
		}
		else if(min1 == 3)
		{
			temp = max1/2;
			temp = temp + max1 + 1;
			if(n<=temp)
			{
				ans = 0;
			}
			else
			{
				n = n - temp;
				if(max1==3)
				{
					if(n==3)
						ans = 8;
					else
						ans = 3*n;
				}
				else if(max1==4)
				{
					if(n<=2)
					{
						ans = n*2;
					}
					else if(n<=5)
					{
						ans = 4 + (n-2)*3;
					}
					else
					{
						ans = 17;
					}
				}
				else
				{
					if(n<=6)
					{
						if(n==5)
							ans=15;
						else
							ans = n*3;
					}
					else
					{
						ans = 22;
					}
				}
			}
		}
		else
		{
			temp = max1*2;
			if(n<=temp)
			{
				ans = 0;
			}
			else
			{
				n = n -temp;
				if(n<=2)
				{
					ans = 2*n;
				}
				else if(n<=6)
				{
					ans = 4 + (n-2)*3;
				}
				else
				{
					ans = 16 + (n-6)*4;
				}
			}
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}