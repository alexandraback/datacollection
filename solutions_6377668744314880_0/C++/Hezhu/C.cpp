#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point
{
	double x, y;
	int id;
	Point(double x = 0, double y = 0): x(x), y(y) {}
	bool operator < (const Point& rhs) const
	{
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
};

Point pp[100];
Point tmp[100];
Point tmp2[100];
Point tmp3[100];
int ans[100];
int pos = 0;
int N;

Point operator - (Point A, Point B)
{
    return Point(A.x - B.x, A.y - B.y);
}

double Cross(Point A, Point B)
{
    return A.x * B.y - A.y * B.x;
}

int ConvexHull(Point* p, int n, Point* ch)
{
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0)
		{
			m--;
		}
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; --i)
	{
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0)
		{
			m--;
		}
		ch[m++] = p[i];
	}
	if (n > 1)
	{
		m--;
	}
	return m;
}

void dfs(int de)
{
	if (de == N)
	{
		for (int i = 0; i < pos; ++i)
		{
			tmp2[i] = tmp[i];
		}
		int m = ConvexHull(tmp2, pos, tmp3);
		for (int i = 0; i < m; ++i)
		{
			ans[tmp3[i].id] = min(ans[tmp3[i].id], N - pos);
		}
	}
	else
	{
		tmp[pos++] = pp[de];
		dfs(de + 1);
		pos--;
		dfs(de + 1);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%lf %lf", &pp[i].x, &pp[i].y);
			pp[i].id = i;
			ans[i] = N;
		}
		dfs(0);
		printf("Case #%d:\n", kase);
		for (int i = 0; i < N; ++i)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
