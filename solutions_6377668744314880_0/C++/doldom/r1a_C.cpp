#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> point;

long long ccw(point a, point b, point c) {
	b.first -= a.first; b.second -= a.second;
	c.first -= a.first; c.second -= a.second;
	return b.first * (long long)c.second - c.first * (long long)b.second;
}

vector<int> convexHull(const vector<point>& dat, int enable) {
	vector<int> l, u;
	vector<point> upper, lower;
	for (int i = 0; i < dat.size(); i++) {
		if (!(enable&(1<<i))) continue;
		while (upper.size() >= 2 && ccw(*++upper.rbegin(), *upper.rbegin(), dat[i]) > 0) upper.pop_back(), u.pop_back();
		while (lower.size() >= 2 && ccw(*++lower.rbegin(), *lower.rbegin(), dat[i]) < 0) lower.pop_back(), l.pop_back();
		upper.emplace_back(dat[i]);
		lower.emplace_back(dat[i]);
		l.push_back(i); u.push_back(i);
	}
	u.insert(u.end(), ++l.rbegin(), --l.rend());
	return u;
}

vector<point> dat;
int n;
int ans[15];

void backtrack(int enable) {
	int nsize = n;
	for (int i=0; i<n; ++i)
		if (!(enable&(1<<i)))
			--nsize;
	if (nsize < 3) return;
	vector<int> hull = convexHull(dat, enable);
	for (int i : hull)
		ans[i] = min(ans[i], n - nsize);
}

int main() {
	//freopen("input.txt", "r", stdin);
	freopen("r1a\\C-small-attempt1.in", "r", stdin);
	freopen("r1a\\C-small.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		dat.clear();
		scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			dat.emplace_back(x, y);
			ans[i] = n;
		}
		sort(dat.begin(), dat.end());
		for (int i=0; i<(1<<n); ++i)
			backtrack(i);
		printf("Case #%d:\n", N);
		for (int i=0; i<n; ++i)
			printf("%d\n", ans[i]);
	}
}