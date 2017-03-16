#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxN = 3000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

struct point
{
	int x, y;

	inline int type() const
	{
		if (x != 0)
			return x < 0 ? -1 : 1;
		if (y != 0)
			return y < 0 ? -1 : 1;
		return 0;
	}
};

inline s64 cross(const point &a, const point &b)
{
	return (s64)a.x * b.y - (s64)a.y * b.x;
}
inline bool cmpByAngle(const point &a, const point &b)
{
	if (a.type() != b.type())
		return a.type() < b.type();
	return cross(a, b) > 0;
}

int main()
{
	int nT;
	cin >> nT;
	for (int tcase = 1; tcase <= nT; tcase++)
	{
		int n;
		static point a[MaxN];

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i].x >> a[i].y;

		printf("Case #%d:\n", tcase);
		for (int i = 0; i < n; i++)
		{
			int b_n = 0;
			static point b[MaxN * 2];
			for (int j = 0; j < n; j++)
				if (i != j)
					b[b_n].x = a[j].x - a[i].x, b[b_n].y = a[j].y - a[i].y, b_n++;
			sort(b, b + b_n, cmpByAngle);
			copy(b, b + b_n, b + b_n);

			int res = n - 1;
			for (int j = 0, k = 0; j < b_n; j++)
			{
				while (k < j + b_n && cross(b[j], b[k]) >= 0)
					k++;
				tension(res, b_n + j - k);
			}
			cout << res << endl;
		}
	}

	return 0;
}
