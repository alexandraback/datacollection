#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 10000;

class point
{
public:
	long long x, y;
	int id;
	point(){}
	point(long long xx, long long yy):x(xx), y(yy){}
	bool operator == (const point &b) const
	{
		return b.x == x && b.y == y;
	}
	point operator - (const point &b) const
	{
		return point(x - b.x, y - b.y);
	}
};

bool cmpByXY(const point &a, const point &b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

#define EPS -1e-9

inline long long det(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}

vector <point > convexHull(int n, point ps[]) { // counter-clockwise, strict
	static point qs[MAXN * 2];
	sort(ps , ps + n, cmpByXY);
	if (n <= 2) return vector<point>(ps , ps + n);
	int k = 0;
	for (int i = 0; i < n; qs[k++] = ps[i++])
	while (k > 1 && det(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) < EPS) --k;
	for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
	while (k > t && det(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) < EPS) --k;
	return vector <point >(qs , qs + k);
}

point p[10000];
point pp[10000];

int main()
{
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%lld%lld", &p[i].x, &p[i].y), p[i].id = i;
		printf("Case #%d:\n", cas);
		for(int i = 0; i < n; ++i)
		{
			int ans = n + 1;
			for(int msk = 0; msk < (1 << n); ++msk)
			{
				if(!((msk >> i) & 1)) continue;
				int cnt = 0;
				for(int j = 0; j < n; ++j)
				{
					if(msk & (1 << j))
						pp[cnt++] = p[j];
				}
				if(cnt <= 3)
				{
					ans = min(ans, n - cnt);
					continue;
				}
				vector<point> hull = convexHull(cnt, pp);
				for(int j = 0; j < hull.size(); ++j)
				{
					if(hull[j].id == i)
					{
						ans = min(ans, n - cnt);
						break;
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
