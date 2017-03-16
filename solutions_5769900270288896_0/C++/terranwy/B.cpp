#include <cstdio>


int casei, cases, n, m, ten;
int ans[20][20][20];

inline bool check(int x1, int y1, int x2, int y2, int tenant) {
	return (tenant & (1 << (x1 * m + y1))) && (tenant & (1 << (x2 * m + y2)));
}

inline int getTenant(int tenant) {
	int res = 0;
	while (tenant > 0) {
		++res;
		tenant = (tenant - 1) & tenant;
	}
	return res;
}

void prepare() {
	for (n = 1; n <= 16; ++n)
		for (m = 1; m <= 16; ++m) if (n * m <= 16) {
			ans[n][m][0] = 0;
			ans[n][m][1] = 0;
			for (int i = 2; i <= n * m; ++i) ans[n][m][i] = n * m * 4;
			
			for (int k = (1 << (n * m)) - 1; k > 0; --k) {
				int un = 0;
				for (int i = 0; i < n; ++i)
					for (int j = 1; j < m; ++j)
						if (check(i, j - 1, i, j, k)) ++un;
				
				for (int i = 1; i < n; ++i)
					for (int j = 0; j < m; ++j)
						if (check(i - 1, j, i, j, k)) ++un;
				
				int cnt = getTenant(k);
				if (un < ans[n][m][cnt])
					ans[n][m][cnt] = un;
			}
		}
			
}

int main() {
	prepare();
	
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d%d%d", &n, &m, &ten);
		printf("Case #%d: %d\n", casei, ans[n][m][ten]);
	}
	
	return 0;
}

