#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define lc (k<<1)
#define rc ((k<<1)|1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll B, N;
ll a[1003];
vector<int> v;

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int cas;scanf("%d",&cas);
	for(int t=1;t<=cas;t++)
	{
		scanf("%lld%lld",&B,&N);
		for(int i=1;i<=B;i++)
			scanf("%lld",&a[i]);
		ll l=0, r=1e14, num;
		while(1)
		{
			ll mid=(l+r)/2;
			v.clear();
			num=0;
			
			for(int i=1;i<=B;i++)
			{
				num+=mid/a[i];
				if(mid%a[i]) num++;
				else v.PB(i);
			}
			ll sz=v.size();
			//printf("l=%lld r=%lld mid=%lld num=%lld sz=%lld N=%lld\n",l,r,mid,num,sz,N);
			if(num+sz>=N && num<=N-1) break;
			//puts("fuck!");
			if(num+sz<N) l=mid+1;
			else if(num>N-1) r=mid-1;
		}
		int cha=N-num;
		printf("Case #%d: %d\n",t,v[cha-1]);
	}
	return 0;
}