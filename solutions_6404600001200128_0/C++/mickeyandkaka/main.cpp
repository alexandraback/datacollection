#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#define clr(a,b)	memset(a,b,sizeof(a))
using namespace std;

typedef long long LL;

int T;
int n;
int a[1111];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out","w", stdout);

	scanf("%d",&T);
	int cas = 1;
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);

		int ans1 = 0, ans2 = 0;
		int maxi = 0;
		for(int i=1; i<n; i++)
		{
			if(a[i+1] < a[i])
			{
				ans1 += a[i] - a[i+1];
				maxi = max(maxi, a[i] - a[i+1]);
			}
		}

		for(int i=1; i<n; i++)
		{
			if(a[i] < maxi)
				ans2 += a[i];
			else
				ans2 += maxi;
		}

		printf("Case #%d: %d %d\n",cas++, ans1, ans2);
	}

    return 0;
}
