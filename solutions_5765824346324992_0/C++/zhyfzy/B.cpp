#include<bits/stdc++.h>
#define eps 1e-9
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAXN 1005
#define MAXM 40005
#define INF 0x3fffffff
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define lc (k<<1)
#define rc ((k<<1)1)
using namespace std;
typedef long long LL;
LL i,j,k,n,m,x,y,T,ans,big,cas,num,len;
bool flag;
LL now,cur[MAXN],a[MAXN],b;
LL gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("output3.txt","w",stdout);
	scanf("%I64d",&T);
	while (T--)
	{
		scanf("%I64d%I64d",&b,&n);
		LL lim=1;
		for (i=1;i<=b;i++)
		{
			scanf("%I64d",&a[i]);
			lim=lim*a[i]/gcd(a[i],lim);
		}
		LL one=0;
		for (i=1;i<=b;i++)
		{
			one+=lim/a[i];
		}
		n%=one;
		printf("Case #%d: ",++cas);
		if (n==0) n=one;
		if (b>=n)
		{
			if (n==0) printf("%I64d\n",b);
			else printf("%I64d\n",n);
			continue;
		}
		
		for (i=1;i<=b;i++)
		{
			cur[i]=a[i];	 
		}
		
		now=b;
		flag=true;
		while (flag)
		{
			LL mi=1e18;
			for (i=1;i<=b;i++)
			{
				mi=min(cur[i],mi);
			}
			for (i=1;i<=b;i++)
			{
				cur[i]-=mi;
				if (!cur[i])
				{
					now++;
					cur[i]=a[i];
					if (now==n)
					{
						printf("%I64d\n",i);
						flag=false;
						break;
					}
				}
			}
			
		}
	}
	return 0;
}
