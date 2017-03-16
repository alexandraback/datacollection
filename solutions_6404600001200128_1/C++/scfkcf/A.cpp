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

int a[1003];

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int cas;scanf("%d",&cas);
	for(int t=1;t<=cas;t++)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int r1=0, r2=0, mx=0;
		for(int i=1;i<n;i++)
		{
			if(a[i+1]<a[i])
			{
				r1+=a[i]-a[i+1];
				mx=max(mx,a[i]-a[i+1]);
			}
		}
		for(int i=1;i<n;i++)
		{
			r2+=min(mx,a[i]);
		}
		printf("Case #%d: %d %d\n",t,r1,r2);
	}
	return 0;
}