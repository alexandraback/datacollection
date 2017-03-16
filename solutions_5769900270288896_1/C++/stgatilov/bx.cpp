#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

int r, c, n;
vector<vector<char>> matr;

int ans[1<<16];

void Relax(int k, int tres) {
	if (ans[k] > tres) {
		ans[k] = tres;
//		memcpy(bestMatr[k], matr, sizeof(matr));
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d%d%d", &r, &c, &n);

		memset(ans, 63, sizeof(ans));

		for (int q = 0; q < 2; q++) {
			int k0 = 0;
			matr.assign(r, vector<char>(c, '.'));
			for (int i = 0; i<r; i++)
				for (int j = 0; j<c; j++) {
					matr[i][j] = ((i ^ j ^ q) & 1 ? 'X' : '.');
					k0 += (matr[i][j] == 'X');
				}
			Eo(k0);

			for (int k = 0; k <= k0; k++)
				Relax(k, 0);

			vector<pair<int, pair<int, int>>> rem;
			for (int i = 0; i<r; i++)
				for (int j = 0; j<c; j++) if (matr[i][j] == '.') {
					int deg = 0;
					for (int di = -1; di <= 1; di++)
						for (int dj = -1; dj <= 1; dj++) {
							if (abs(di) + abs(dj) != 1)
								continue;
							int ni = i + di;
							int nj = j + dj;
							if (ni < 0 || ni >= r || nj < 0 || nj >= c)
								continue;
							deg++;
						}
					rem.push_back(make_pair(deg, make_pair(i, j)));
				}
			sort(rem.begin(), rem.end());

			int tres = 0;
			for (int i = 0; i < rem.size(); i++) {
				tres += rem[i].first;
				auto p = rem[i].second;
				matr[p.first][p.second] = 'X';
				k0++;
				Relax(k0, tres);
			}
		}

		printf("Case #%d: %d\n", tt, ans[n]);
//		for (int i = 0; i<r; i++) printf("%s\n", bestMatr[n][i]);

/*		printf("Case #%d: %d x %d\n", tt, r, c);
		for (int k = 0; k <= r*c; k++) {
			printf("%d -> %d\n", k, ans[k]);
			for (int i = 0; i<r; i++) printf("%s\n", bestMatr[k][i]);
		}*/
		fflush(stdout);
	}
	return 0;
}
