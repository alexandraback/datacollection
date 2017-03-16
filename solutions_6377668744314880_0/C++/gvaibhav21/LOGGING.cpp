#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<map>
using namespace std;
#define gc getchar_unlocked
#define sd(a) scanf("%lld",&a)
#define pd(a) prlong longf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
long long x[20],y[20];
long long orientation(long long p, long long q, long long r)
{
    long long val = (y[q] - y[p]) * (x[r] - x[q]) -
              (x[q] - x[p]) * (y[r] - y[q]);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

int main()
{
	long long t,n,i,j,k,l,ans1,ans2,curmin;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	sd(t);
	for(l=1;l<=t;++l)
	{
		sd(n);
		for(i=0;i<n;++i)
		{
			sd(x[i]);
			sd(y[i]);
		}
		printf("Case #%lld:\n",l);
		for(i=0;i<n;++i)
		{
			curmin=1000000000;
			for(j=0;j<n;++j)
			{
				if(j!=i)
				{
					ans1=ans2=0;
					for(k=0;k<n;++k)
					{
						if(k!=i&&k!=j)
						{
							if(orientation(i,j,k)==1)
								ans1++;
							else if(orientation(i,j,k)==2)
								ans2++;
						}
					}
					curmin=min(curmin,min(ans1,ans2));
				}
			}
			if(curmin==1000000000)
				curmin=0;
			printf("%lld\n",curmin);
		}
	}
}