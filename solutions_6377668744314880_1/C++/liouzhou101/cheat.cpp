#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<complex>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int abs(int x)
{
	return (x>=0)?x:-x;
}

const int MaxN=6010;

int n;
int x[MaxN],y[MaxN],p[MaxN];
ld a[MaxN];

bool cmp(int i,int j)
{
	return a[i]<a[j];
}

ll det(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
	return x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3;
}

ll area(int i,int j,int k)
{
	return det(x[i],y[i],x[j],y[j],x[k],y[k]);
}

int main()
{
	freopen("try.in","r",stdin);
	freopen("try.out","w",stdout);
	int Test;
	cin>>Test;
	for (int T=1;T<=Test;++T)
	{
		printf("Case #%d:\n",T);
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d%d",&x[i],&y[i]);
		for (int i=1;i<=n;++i)
		{
			int ans=n-1;
			
			for (int j=1;j<=n;++j)
			{
				p[j]=j;
				if (i==j) a[j]=-10;
				else
				{
					int ty=y[j]-y[i],tx=x[j]-x[i];
					int d=gcd(abs(tx),abs(ty));
					a[j]=atan2(ty/d,tx/d);
				}
			}
			sort(p+1,p+n+1,cmp);
			for (int j=n+1;j<2*n;++j)
				p[j]=p[j-n+1];
			for (int j=2,k=2;j<=n;++j)
			{
				k=max(k,j);
				if (a[p[j]]==a[p[j-1]]) continue;
				while (area(p[j],i,p[k])<=0)
				{
					++k;
					if (k-j==n-1) break;
				}
				ans=min(ans,min(k-j,n-1-(k-j)));
			}
			
			for (int j=1;j<=n;++j)
			{
				y[j]=-y[j];
			}
			
			for (int j=1;j<=n;++j)
			{
				p[j]=j;
				if (i==j) a[j]=-10;
				else
				{
					int ty=y[j]-y[i],tx=x[j]-x[i];
					int d=gcd(abs(tx),abs(ty));
					a[j]=atan2(ty/d,tx/d);
				}
			}
			sort(p+1,p+n+1,cmp);
			for (int j=n+1;j<2*n;++j)
				p[j]=p[j-n+1];
			for (int j=2,k=2;j<=n;++j)
			{
				k=max(k,j);
				if (a[p[j]]==a[p[j-1]]) continue;
				while (area(p[j],i,p[k])<=0)
				{
					++k;
					if (k-j==n-1) break;
				}
				ans=min(ans,min(k-j,n-1-(k-j)));
			}
			
			for (int j=1;j<=n;++j)
			{
				y[j]=-y[j];
			}
			
			printf("%d\n",ans);
		}
	}
	return 0;
}
