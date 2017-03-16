#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

int n,r,c;

int count(int x)
{
	int res = 0;
	while (x)
	{
		x = x & (x - 1);
		res++;
	}

	return res;	
}

int calc(int x)
{
	int res = 0;
	for (int i=0;i<r;++i)
		for (int j=0;j<c;++j)
		{
			int pos = i * c + j;
			if (x & (1 << pos))
			{
				if (i+1 < r)
				{
					int next = (i + 1) * c + j;
					if (x & (1 << next)) res++;
				}
				if (j+1 < c)
				{
					int next = i * c + (j + 1);
					if (x & (1 << next)) res ++;
				}
			}
		}

	return res;
}

int main()
{
	int t, ys = 0;

	freopen("B-small-attempt0.in","r",stdin);
	freopen("dataB.out","w",stdout);

	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d%d%d",&r,&c,&n);
		int m = (1 << (r * c));
		int ans = 1000;
		for (int i=0;i<m;++i)
			if (count(i) == n)
				ans = min(ans,calc(i));

		printf("Case #%d: %d\n",++ys,ans);

	}
}