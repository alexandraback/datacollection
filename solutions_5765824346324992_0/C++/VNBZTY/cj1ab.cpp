#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
const int N = 1012;
long long l,r,mid,ans,tmp,mm;
int a[N],n,T,m;
long long check(long long t)
{
	if (t < 0) return 0;
	long long sum = 0;
	for(int i = 1;i <= n; ++ i)
		sum += (t / a[i]) + 1;
	return sum;
}
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	mm = 10000000;
	mm = mm * mm;
	for(int t = 1;t <= T; ++ t)
	{
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n; ++ i)
			scanf("%d",&a[i]);
		l = 0;r = mm;
		ans = 0;
		while (l <= r)
		{
			mid = (l + r) >> 1;
			if (check(mid) < m)
				l = mid + 1;
			else
				ans = mid,r = mid - 1;
		}
		tmp = m - check(ans - 1);
		for(int i = 1;i <= n; ++ i)
		{
			if (ans % a[i] == 0)
				tmp --;
			if (tmp == 0)
			{
				printf("Case #%d: %d\n",t,i);
				break;
			}
		}
	}
	
}