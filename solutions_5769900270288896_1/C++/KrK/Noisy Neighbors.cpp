#include <cstdio>
#include <algorithm>
using namespace std;

int T;
int r, c, n;
int has4, has3, has2, has1;

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d %d", &r, &c, &n);
		int lft = r * c - n, res = 2 * r * c - r - c;
		if (r > c) swap(r, c);
		if (r == 1)
			if (c % 2) { has4 = 0; has3 = 0; has2 = c / 2; has1 = 0; }
			else { has4 = 0; has3 = 0; has2 = c / 2 - 1; has1 = 1; }
		else if (r == 2) { has4 = 0; has3 = c - 2; has2 = 2; has1 = 0; }
		else {
			has4 = ((r - 2) * (c - 2) + 1) / 2;
			has3 = (r - 2) / 2 * 2 + (c - 2) / 2 * 2;
			has2 = r * c % 2? 4: 2;
			has1 = 0;
			if (r % 2 == 0 && c % 2) swap(r, c);
			if (r % 2 && c % 2 == 0) {
				has3 = (c - 2) / 2 * 2 + r / 2 + r / 2 - 1;
				has2 = 2;
			}
		}
		int tk = min(lft, has4); lft -= tk; res -= 4 * tk;
		tk = min(lft, has3); lft -= tk; res -= 3 * tk;
		tk = min(lft, has2); lft -= tk; res -= 2 * tk;
		tk = min(lft, has1); lft -= tk; res -= tk;
		if (r > 2 && c > 2 && r % 2 && c % 2) {
			has4 = (r - 2) * (c - 2) / 2;
			has3 = r / 2 * 2 + c / 2 * 2;
			has2 = 0; has1 = 0;
			int lft = r * c - n, res2 = 2 * r * c - r - c;
			int tk = min(lft, has4); lft -= tk; res2 -= 4 * tk;
			tk = min(lft, has3); lft -= tk; res2 -= 3 * tk;
			tk = min(lft, has2); lft -= tk; res2 -= 2 * tk;
			tk = min(lft, has1); lft -= tk; res2 -= tk;
			res = min(res, res2);
		}
		printf("Case #%d: %d\n", tc, res);
	}
	return 0;
}