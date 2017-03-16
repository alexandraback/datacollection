#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>

using namespace std;

#define REP(a,b) for (int a=0; a<(int)(b); ++a)
#define FOR(a,b,c) for (int a=(b); a<(int)(c); ++a)

int r, c, n;

void read_input() {
	cin >> r >> c >> n;
}


void solve() {
	if (r > c) swap(r, c);
	int res = r*(c - 1) + c*(r - 1), nn = n;
	n = r*c - n;

	if (r == 1) {
		res -= 2 * min(n, (c-1) / 2);
		n -= min(n, (c-1) / 2);
		if (c % 2 == 0 && n) {
			--n; --res;
		}
	}
	else if (r == 2) {
		res -= 3 * min(n, max(0, c - 2));
		n -= min(n, max(0, c - 2));
		res -= 2 * min(n, 2);
		n -= min(n, 2);
	}
	else {
		res -= 4 * min(n, ((r - 2)*(c - 2) + 1) / 2);
		n -= min(n, ((r - 2)*(c - 2) + 1) / 2);
		int z = (r*c) % 2 ? 4 : 2;
		res -= 3 * min(n, (r*c + 1) / 2 - (((r - 2)*(c - 2) + 1) / 2) - z);
		n -= min(n, (r*c + 1) / 2 - (((r - 2)*(c - 2) + 1) / 2) - z);
		res -= 2 * min(n, z);
		n -= min(n, z);

		if (z == 4) {
			int res1 = res;
			res = r*(c - 1) + c*(r - 1);
			n = r*c - nn;
			res -= 4 * min(n, ((r - 2)*(c - 2)) / 2);
			n -= min(n, ((r - 2)*(c - 2)) / 2);
			res -= 3 * min(n, (r*c) / 2 - (((r - 2)*(c - 2)) / 2) );
			n -= min(n, (r*c) / 2 - (((r - 2)*(c - 2)) / 2) );
			res = min(res, res1);
		}
	}

	printf("%d\n", res);
}

void bf() {
	int nc = r*c;
	int b[32][32];
	int res = 999999;
	int dr[] = { 1, 0, -1, 0 };
	int dc[] = { 0, 1, 0, -1 };

	REP(mask, 1 << nc) {
		REP(i, r) REP(j, c) b[i][j] = mask&(1 << (i*c + j));
		int cnt = 0;
		REP(i, r) REP(j, c) if (b[i][j]) ++cnt;
		if (cnt != n) continue;
		cnt = 0;
		REP(i, r) REP(j, c) if (b[i][j]) {
			REP(k, 4) {
				int x = i + dr[k], y = j + dc[k];
				if (x < 0 || x >= r || y < 0 || y >= c || !b[x][y]) continue;
				++cnt;
			}
		}
		res = min(res, cnt/2);
	}

	printf("%d\n", res);
}


int main(int argc, char* argv[]) {
	int nt, single_tc = 0;

	if (argc > 1) {
		sscanf(argv[1], "%d", &single_tc);
	}

	scanf("%d", &nt);
	for (int t = 1; t <= nt; ++t) {
		fprintf(stderr, "Case #%d ", t);
		read_input();
		if (single_tc == 0 || single_tc == t) {
			printf("Case #%d: ", t);
			solve();
		}
		fprintf(stderr, "done.\n");
	}

	return 0;
}