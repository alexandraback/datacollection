#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int a[4][4], b[4][4];
int c[20];
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-out.txt", "w", stdout);
	int ca = 1; int T;
	for (scanf("%d", &T); T--; ) {
		int x, y;
		clr(c, 0);
		scanf("%d", &x); --x; rep(i, 4) rep(j, 4) scanf("%d", &a[i][j]);
		scanf("%d", &y); --y; rep(i, 4) rep(j, 4) scanf("%d", &b[i][j]);
		rep(i, 4) {
			++c[a[x][i]];
			++c[b[y][i]];
		}
		int cc = 0, ret;
		Rep(i, 16) {
			if (c[i] == 2) ret = i, ++cc;
		}
		printf("Case #%d: ", ca++);
		if (cc == 0) puts("Volunteer cheated!");
		else if (cc == 1) printf("%d\n", ret);
		else puts("Bad magician!");
	}
	return 0;
}

