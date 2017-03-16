#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ldb;

#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

int r, c, n;

const int a[] = {0, 2, 4, 7};
const int b[] = {0, 3, 6, 8};

const int MAXN = 20;

bool x[MAXN][MAXN];

int old_sol() {
	int rc = r * c;

	int ans = 100500;

	forn(mask, (1 << rc))
		if (__builtin_popcount(mask) == n) {
			memset(x, 0, sizeof(x));

			forn(i, rc)
				if ((mask >> i) & 1)
					x[i / c][i % c] = true;

			int cur = 0;

			forn(i, r)
				forn(j, c)
					if (x[i][j]) {
						if (x[i + 1][j])
							cur++;
						if (x[i][j + 1])
							cur++;
					}

			ans = min(ans, cur);
		}

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d ", &T);

	//T = 25;

	forn(test, T) {
		printf("Case #%d: ", test + 1);

		scanf("%d%d%d", &r, &c, &n);

		//r = 8;
		//c = 3;
		//n = test;
		
		int rc = r * c;

		int q = (rc + 1) / 2;

		int all = 2 * rc - r - c;

		if (n <= q) {
			printf("0\n");
			continue;
		}

		if (c < 3)
			swap(r, c);

		if (r == 1) {
			cout << c - 1 - 2 * (c - n) << '\n';
			continue;
		}

		if (r == 2) {
			if (n - q <= 2)
				cout << 2 * (n - q) << '\n';
			else
				cout << all - 3 * (rc - n) << '\n';
			continue;
		}

		
		if (n - q < 4) {
			if (rc % 2 == 1)
				printf("%d\n", b[n - q]);
			else
				printf("%d\n", a[n - q]);
		} else {
			int g = ((r - 2) * (c - 2) + 1) / 2;

			if (rc - n <= g)
				printf("%d\n", all - 4 * (rc - n));
			else
				printf("%d\n", all - 4 * g - 3 * (rc - g - n));
		}

	}
	return 0;
}
