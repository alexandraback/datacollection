#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define small

const int N = 15;

struct Node {
	int x, y, id;
	bool operator < (const Node& other) const {
		return x < other.x || (x == other.x && y < other.y);
	}
} inp[N], has[N];

int T, n, ps[N], isIn[N][1 << N], one[1 << N];
bool used[N];

void check(const int& s) {
	int tot = 0, top = 0;
	for (int i = 0; i < n; ++i)
		if ((1 << i) & s)
			has[tot++] = inp[i], ++one[s];
	sort(has, has + tot);
	memset(used, false, sizeof(used));
	for (int i = 0; i < tot; ++i) {
		while (top > 1) {
			int x1 = has[ps[top - 2]].x, y1 = has[ps[top - 2]].y;
			int x2 = has[ps[top - 1]].x, y2 = has[ps[top - 1]].y;
			int x3 = has[i].x, y3 = has[i].y;
			if (1LL * (x2 - x1) * (y3 - y1) - 1LL * (x3 - x1) * (y2 - y1) < 0)
				used[ps[--top]] = false;
			else
				break;
		}
		ps[top++] = i;
		used[i] = true;
	}
	for (int i = tot - 1; i > -1; --i) {
		if (used[i] && i != 0)
			continue;
		while (top > 1) {
			int x1 = has[ps[top - 2]].x, y1 = has[ps[top - 2]].y;
			int x2 = has[ps[top - 1]].x, y2 = has[ps[top - 1]].y;
			int x3 = has[i].x, y3 = has[i].y;
			if (1LL * (x2 - x1) * (y3 - y1) - 1LL * (x3 - x1) * (y2 - y1) < 0)
				used[ps[--top]] = false;
			else
				break;
		}
		ps[top++] = i;
		used[i] = true;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < top; ++j)
			if (i == has[ps[j]].id)
				isIn[i][s] = true;
}

int countOne(const int& s) {
	int ret = 0;
	for (int i = 0; i < n; ++i)
		if ((1 << i) & s)
			++ret;
	return ret;
}

int main()
{
#ifdef small
  freopen("C-small.in", "r", stdin);
  freopen("C-small.out", "w", stdout);
#endif
#ifdef large
  freopen("C-large.in", "r", stdin);
  freopen("C-large.out", "w", stdout);
#endif
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d %d", &inp[i].x, &inp[i].y), inp[i].id = i;
		memset(isIn, false, sizeof(isIn));
		memset(one, 0, sizeof(one));
		for (int i = 0; i < (1 << n); ++i)
			check(i);
		printf("Case #%d:\n", Case);
		for (int i = 0; i < n; ++i) {
			int ans = 0, s;
			for (int j = 0; j < (1 << n); ++j)
				if (isIn[i][j] && one[j] > ans)
					ans = one[j];
			printf("%d\n", n - ans);
		}
	}
	return 0;
}
