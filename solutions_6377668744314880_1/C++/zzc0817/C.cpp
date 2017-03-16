#include <stdio.h>
#include <math.h>
#include <algorithm>

struct Point
{
	double x, y;
} pts[10000];
double angels[10000];

int n;



int main()
{
	int T;
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ++ca)
	{
		printf("Case #%d:\n", ca);
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%lf %lf", &pts[i].x, &pts[i].y);
		int r = n-1;
		for(int i = 0; i < n; ++i)
		{
			std::swap(pts[i], pts[0]);
			for(int j = 1; j < n; ++j)
				angels[j - 1] = atan2(pts[j].y - pts[0].y, pts[j].x - pts[0].x);
			std::sort(angels, angels + r);
			for(int j = r; j < r + r; ++j)
				angels[j] = angels[j - r] + 2*M_PI;
			//for(int j = 0; j < r + r; ++j)
				//printf("#[%d]=%lf\n", j, angels[j]);
			int ans = n-1;
			for(int j = 0, k = 0; j < r; ++j)
			{
				while(angels[k]-angels[j] < M_PI-1e-9 && k < r+r)
				{
					++k;
					//printf("#[%d] %d %d %g\n", i, j, k, angels[k] - angels[j]);
					//system("sleep 5");
				}
				//printf("#(%d,%d)\n", j, k);
				ans = std::min(ans, k-j - 1);
			}
			printf("%d\n", ans);
		}
	}
}
