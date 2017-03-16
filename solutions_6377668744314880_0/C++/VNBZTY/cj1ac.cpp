#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const double pi = acos(-1);
const int inf = ~0U >> 1,N = 10012;
struct point
{
	int x,y;
	double ang;
	void calc(const point & A)
	{
		ang = atan2(y - A.y,x - A.x);
	}
	inline bool operator < (const point & A)const
	{
		return ang < A.ang;
	}
}a[N],b[N];
int T,n,ans,k;

int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	for(int t = 1;t <= T; ++ t)
	{
		scanf("%d",&n);
		for(int i = 1;i <= n; ++ i)
			scanf("%d%d",&a[i].x,&a[i].y);
		printf("Case #%d:\n",t);
		for(int i = 1;i <= n; ++ i)
		{
			ans = n - 1;
			for(int j = 1;j <= n; ++ j)
				b[j] = a[j];
			swap(b[1],b[i]);
			for(int j = 2;j <= n; ++ j)
				b[j].calc(b[1]);
			sort(b + 2,b + n + 1);
			for(int j = n + 1;j < n + n;++ j)
			{
				b[j] = b[j - n + 1];
				b[j].ang += 2 * pi;
			}
			k = 2;
			for(int j = 2;j <= n; ++ j)
			{
				while(b[k].ang - b[j].ang < pi)
					++k;
				ans = min(ans,k - j - 1);		
			}
			printf("%d\n",ans);
		}
	}
}