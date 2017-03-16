#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define SZ pts.size()
typedef long long ll;

struct point
{
	ll x, y, id;
	point operator- (const point& oth) const
	{
		point res;
		res.x = x-oth.x;
		res.y = y-oth.y;
		res.id = -1;
		return res;
	}
};

vector<point> pts;
point orig[20];
point all[20];
int ans[20];
int t;
int n;

double cross(point a, point b)
{
	return (a.x*b.y-a.y*b.x);
}

bool cw(point a, point b)
{
	return cross(a, b) < -0.00000000001;
}

bool collinear(point a, point b, point c)
{
	return fabs(cross(b-a, c-a)) < 0.00000000001;
}

int i, j;

int main()
{
	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		scanf("%d", &n);
		for (i = 0;i < n;i++)
			scanf("%lld%lld", &all[i].x, &all[i].y), all[i].id = i, orig[i] = all[i];
		for (i = 0;i < n;i++)
		{
			ans[i] = 2000;
			for (j = 0;j < (1<<n);j++) if (!(j&(1<<i)))
			{
				pts.clear();
				sort(all, all+n, [](const point& a, const point& b)->bool
				{
					if ((j&(1<<a.id)) && (j&(1<<b.id)))
						return (a.id < b.id);
					if (j&(1<<a.id))
						return false;
					if (j&(1<<b.id))
						return true;
					return (a.y != b.y) ? a.y < b.y : a.x < b.x;
				});
				sort(all+1, all+n, [](const point& a, const point& b)->bool
				{
					if ((j&(1<<a.id)) && (j&(1<<b.id)))
						return (a.id < b.id);
					if (j&(1<<a.id))
						return false;
					if (j&(1<<b.id))
						return true;
					return atan2(a.y-all[0].y, a.x-all[0].x) < atan2(b.y-all[0].y, b.x-all[0].x);
				});
				for (int k = 0;k < n;k++) if (!(j&(1<<all[k].id)))
				{
					while (SZ >= 2 && cw(pts[SZ-1]-pts[SZ-2], all[k]-pts[SZ-2]))
						pts.pop_back();
					pts.push_back(all[k]);
				}
				pts.push_back(pts[0]);
				bool ok = false;
				int N = SZ-1;
				for (int k = 0;k < N;k++) if (pts[k].id == i || collinear(pts[k], orig[i], pts[k+1]))
				{
					ok = true;
					break;
				}
				if (ok)
					ans[i] = min(ans[i], __builtin_popcount(j));
			}
		}
		printf("Case #%d:\n", _);
		for (i = 0;i < n;i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}
