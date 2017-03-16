#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll sqr(ll x)
{
	return x * x;
}

struct Point
{
	ll x, y;
	Point(ll x = 0, ll y = 0) : x(x), y(y) {}
	int getside()
	{
		if (y > 0 || (y == 0 && x > 0))
			return 1;
		else
			return -1;
	}
	ll len()
	{
		return sqr(x) + sqr(y);
	}
	Point operator + (Point a)
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (Point a)
	{
		return Point(x - a.x, y - a.y);
	}
};

vector<Point> p;
Point o;
int num[10000];

ll det(Point v1, Point v2)
{
	return v1.x * v2.y - v1.y * v2.x;
}

ll dot(Point v1, Point v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

bool cmp(int g, int h)
{
	Point p1 = p[g] - o;
	Point p2 = p[h] - o;
	int ty1 = p1.getside();
	int ty2 = p1.getside();
	if (ty1 > ty2)
		return true;
	if (ty1 < ty2)
		return false;
	ll s = det(p1, p2);
	if (s > 0)
		return true;
	if (s < 0)
		return false;
	return p1.len() < p2.len();
}

int cek1(int g, int h)
{
	ll s = det(p[g] - o, p[h] - o);
	if (s > 0)
		return 1;
	if (s < 0)
		return -1;
	return 0;
}

ll cek2(int g, int h)
{
	return dot(p[g] - o, p[h] - o);
}

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
	// freopen("B-large.in", "r", stdin);
	// freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++)
	{
		printf("Case #%d:\n", ca);
		int n;
		scanf("%d", &n);
		// if (n < 4)
		// {
		// 	for (int i = 0; i < n; i++)
		// 		cout << 0 << endl;
		// 	continue;
		// }
		p.clear();
		for (int i = 0; i < n; i++)
		{
			ll x, y;
			scanf("%I64d %I64d", &x, &y);
			p.push_back(Point(x, y));
		}
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
				num[i] = i;
			swap(num[0], num[k]);
			o = p[k];
			sort(num + 1, num + n, cmp);

			for (int i = 1; i < n * 2; i++)
				num[i + n - 1] = num[i];

			// for (int i = 0; i < n * 3; i++)
			// 	printf("%d%c", num[i], " \n"[i == n * 3 - 1]);

			int lim = n - 1;

			int x1 = 1;
			while (x1 < lim && cek1(num[1], num[x1]) == 0 && cek2(num[1], num[x1]) > 0)
				x1++;
			if (cek1(num[1], num[x1]) == -1 || (cek1(num[1], num[x1]) == 0 && cek2(num[1], num[x1]) < 0))
				x1--;
			int y1 = x1;
			while (cek1(num[1], num[y1]) == 1)
				y1++;

			int x2 = y1;
			while (x2 < lim && cek1(num[1], num[x2]) == 0 && cek2(num[1], num[x2]) < 0)
				x2++;
			if (cek1(num[1], num[x2]) == 1 || (cek1(num[1], num[x2]) == 0 && cek2(num[1], num[x2]) > 0))
				x2--;
			int y2 = x2;
			while (cek1(num[1], num[y2]) == -1)
				y2++;

			// printf("%d %d %d %d\n", x1, y1, x2, y2);

			int res = n - 1;
			for (int i = 1; i < n;)
			{
				res = min(res, y1 - x1);
				res = min(res, y2 - x2);
				// cout << res << endl;
				i++;
				int lim = i + n - 2;
				while (x1 < lim && (cek1(num[i], num[x1]) == -1 || (cek1(num[i], num[x1]) == 0 && cek2(num[i], num[x1]) > 0)))
					x1++;
				if (cek1(num[i], num[x1]) == -1 || (cek1(num[i], num[x1]) == 0 && cek2(num[i], num[x1]) < 0))
					x1--;
				while (cek1(num[i], num[y1]) == 1 || y1 < x1)
					y1++;
				while (x2 < lim && (cek1(num[i], num[x2]) == 1 || (cek1(num[i], num[x2]) == 0 && cek2(num[i], num[x2]) < 0)))
					x2++;
				if (cek1(num[i], num[x2]) == 1 || (cek1(num[i], num[x2]) == 0 && cek2(num[1], num[x2]) > 0))
					x2--;
				while (cek1(num[i], num[y2]) == -1 || y2 < x2)
					y2++;
				// printf("%d %d %d %d\n", x1, y1, x2, y2);
			}
			printf("%d\n", res);
		}
	}
	return 0;
}