#include <cstdio>
#include <algorithm>
using namespace std;

int T;
int r, c, n;

int Bits(int x)
{
	int res = 0;
	while (x) {
		res += x & 1;
		x >>= 1;
	}
	return res;
}

bool isIn(int x, int gr, int gc) { return x & 1 << (gr * c + gc); }

int Cost(int x)
{
	int res = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) if (isIn(x, i, j)) {
			res += j + 1 < c && isIn(x, i, j + 1);
			res += i + 1 < r && isIn(x, i + 1, j);
		}
	return res;
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d %d", &r, &c, &n);
		int res = 1000000000;
		for (int i = 0; i < 1 << r * c; i++)
			if (Bits(i) == n) res = min(res, Cost(i));
		printf("Case #%d: %d\n", tc, res);
	}
	return 0;
}