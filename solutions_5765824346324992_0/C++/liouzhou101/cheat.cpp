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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

int b,n;
int a[1010];
int ans;

bool check(ll m)
{
	ll cnt=0;
	for (int i=1;i<=b;++i)
		cnt+=m/a[i]+1;
	if (cnt>=n)
	{
		cnt=0;
		for (int i=1;i<=b;++i)
		{
			cnt+=m/a[i]+1;
			if (m%a[i]==0) cnt--;
		}
		if (cnt>=n) return true;
		for (int i=1;i<=b;++i)
			if (m%a[i]==0)
			{
				cnt++;
				if (cnt==n)
				{
					ans=i;
					break;
				}
			}
		return true;
	}
	return false;
}

int main()
{
	freopen("try.in","r",stdin);
	freopen("try.out","w",stdout);
	int Test;
	cin>>Test;
	for (int T=1;T<=Test;++T)
	{
		printf("Case #%d: ",T);
		scanf("%d%d",&b,&n);
		for (int i=1;i<=b;++i)
			scanf("%d",&a[i]);
		ll L=0,R=100000000000000;
		ans=1;
		while (L<=R)
		{
			ll m=(L+R)/2;
			if (check(m))
				R=m-1;
			else
				L=m+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
