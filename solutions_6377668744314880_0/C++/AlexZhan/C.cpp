#include <cstdio>
using namespace std;

const int N = 3000 + 100, INF = 1000000000;

struct Point {
	long long x, y;
} p[N];

Point operator-(const Point &a, const Point &b)
{
	Point c = {a.x - b.x, a.y - b.y};
	return c;
}

long long operator*(const Point &a, const Point &b)
{
	return a.x * b.y - a.y * b.x;
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int ca = 1; ca <= T; ++ca) {	
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%lld%lld", &p[i].x, &p[i].y);

		printf("Case #%d:\n", ca);

		for(int i = 1; i <= n; ++i) {
			if(n == 1) {
				printf("0\n");
				continue;
			}

			int ans = INF;
			for(int j = 1; j <= n; ++j)
				if(i != j) {
					int s1 = 0, s2 = 0;
					Point vec = p[j] - p[i];
					for(int k = 1; k <= n; ++k)
						if(k != i && k != j) {
							long long w = vec * (p[k] - p[i]);
							if(w > 0) ++s1;
							if(w < 0) ++s2;
						}
					if(s1 < ans) ans = s1;
					if(s2 < ans) ans = s2;
				}

			printf("%d\n", ans);
		}
	}
}