#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
struct point{
	long long x, y;
};
point a[10000];
long long xmult(point p1, point p2, point p0){
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}

int main()
{
	int tt, ii, n, i, j, k, t1, t2,t3,_min;
	long long val;
	freopen("111.txt", "r", stdin);
	freopen("222.txt", "w", stdout);
	scanf("%d", &tt);
	val = -3;
	for (ii = 1; ii <= tt; ii++)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%lld%lld", &a[i].x, &a[i].y);
		printf("Case #%d:\n", ii);
		for (i = 1; i <= n; i++)
		{
			_min = n;
			if (n <=3) _min = 0;
			for (j = 1; j <= n; j++)
			{
				if (i == j) continue;
				t1 = 0;
				t2 = 0;
				for (k = 1; k <= n; k++)
				{
					val = xmult(a[k], a[j], a[i]);
					if (val > 0) t1++;
					if (val < 0) t2++;
				}
				if (t1 < t2) t3 = t1;
				else
					t3 = t2;
				if (t3 < _min) _min = t3;
			}
			printf("%d\n", _min);
		}
	}
	return 0;
}
