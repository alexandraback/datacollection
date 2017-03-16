#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

class point
{
public:
	long long x, y;
	point(){}
	point(long long xx, long long yy):x(xx), y(yy){}
	point operator - (const point &a)
	{
		return point(x - a.x, y - a.y);
	}
};

point p[30000], pp[30000];
int ans[30000];

long long det(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}

int main()
{
	int startNo;
	scanf("%d", &startNo);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%lld%lld", &p[i].x , &p[i].y);
			ans[i] = n + 1;
		}
		printf("Case #%d:\n", cas + startNo);
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				pp[j] = p[j] - p[i];
			for(int j = i + 1; j < n; ++j)
			{
				point sep = p[j] - p[i];
				int neg = 0, online = 0, pos = 0;
				for(int k = 0; k < n; ++k)
				{
					long long val = det(pp[k], sep);
					if(val == 0) online++;
					else if(val < 0) neg++;
					else pos++;
				}
				//printf("%d %d %d %d %d\n", i, j, online, pos, neg);
				ans[i] = min(ans[i], n - (online + pos));
				ans[i] = min(ans[i], n - (online + neg));
				ans[j] = min(ans[j], n - (online + pos));
				ans[j] = min(ans[j], n - (online + neg));
			}
		}
		for(int i = 0; i < n; ++i)
			printf("%d\n", ans[i]);
	}
	return 0;
}