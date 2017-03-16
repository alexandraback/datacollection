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

int n;
int a[1010];

int main()
{
	freopen("try.in","r",stdin);
	freopen("try.out","w",stdout);
	int Test;
	cin>>Test;
	for (int T=1;T<=Test;++T)
	{
		printf("Case #%d: ",T);
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		{
			int ans=0;
			for (int i=1;i<n;++i)
				ans+=max(a[i]-a[i+1],0);
			printf("%d ",ans);
		}
		{
			int v=0;
			for (int i=1;i<n;++i)
				v=max(v,a[i]-a[i+1]);
			int ans=0;
			for (int i=1;i<n;++i)
			{
				ans+=min(a[i],v);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
