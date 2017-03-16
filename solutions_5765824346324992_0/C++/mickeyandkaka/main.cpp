#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#define clr(a,b)	memset(a,b,sizeof(a))
using namespace std;

typedef long long LL;

int T;
int n, b;
int a[1111];

LL c[1111];

bool check(LL t)
{
	LL c1 = 0, c2 = 0;
	for(int i=1; i<=b; i++)
	{
		c1 += t / a[i];
		if(t % a[i])	c2++;
	}

	if(c1 + c2 >= n)	return true;
	return false;
}

int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("out","w", stdout);

	scanf("%d",&T);
	int cas = 1;
	while(T--)
	{
		scanf("%d%d",&b, &n);
		for(int i=1; i<=b; i++)
			scanf("%d",&a[i]);

		int ans = 0;
		if(n <= b)
		{
			ans = n;
		}
		else
		{
			LL l = 0, r = 1000000000000000LL;
			while(l + 1 < r)
			{
				LL mid = (l + r) >> 1;
				if(check(mid)) r = mid;
				else	l = mid;
			}
			LL t = r;
			if(check(l)) t = l;


			clr(c, 0);
			LL f1 = 0, f2 = 0;
			for(int i=1; i<=b; i++)
			{
				c[i] = (t-1) % a[i];

				f1 += (t-1) / a[i];
				if( (t-1) % a[i]) f2++;
			}

			LL d = n - (f1+f2);
			for(int i=1; i<=b; i++)
			{
				if(c[i] == 0)
				{
					d--;
					if(d == 0)
					{
						ans = i;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n",cas++, ans);
	}

    return 0;
}
