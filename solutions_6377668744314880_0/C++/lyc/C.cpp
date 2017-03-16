#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct Point {
	long long x, y;
	int idx;
} p[3010], q[3010], ch[3010];
typedef Point Vector;
int T, n, m, ans[3010];

Vector operator - (Point A, Point B) {
	Vector v;
	v.x = A.x - B.x;
	v.y = A.y - B.y;
	v.idx = -1;
	return v;
}

bool cmp_xy(const Point& p, const Point& q) {
	return p.x < q.x || p.x == q.x && p.y < q.y;
}

bool cmp_idx(const Point& p, const Point& q) {
	return p.idx < q.idx;
}

long long Cross(Vector A, Vector B) {
	return A.x * B.y - A.y * B.x;
}

int ConvexHull(Point* p, int n, Point* ch) {
	sort(p, p + n, cmp_xy);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0) --m;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; --i) {
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0) --m;
		ch[m++] = p[i];
	}
	if (n > 0) m--;
	return m;
}

int main()
{
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
		scanf("%d", &n);
		memset(p, 0, sizeof(p));
		memset(ch, 0, sizeof(ch));
		for (int i = 0; i < n; ++i) {
			scanf("%lld%lld", &p[i].x, &p[i].y);
			p[i].idx = i;
		}
		for (int i = 0; i < n; ++i)
			ans[i] = 0;
		for (int i = 0; i < (1 << n); ++i) {
			sort(p, p + n, cmp_idx);
			int nn = 0;
			for (int j = 0; j < n; ++j)
				if (i & (1 << j)) {
					q[nn] = p[j];
					++nn;
				}
			m = ConvexHull(q, nn, ch);
/*			cout << "\t" << nn << "\t";
			for (int j = 0; j < m; ++j)
				cout << ch[j].idx << " ";
			cout << endl;
*/			for (int j = 0; j < m; ++j)
				if (nn > ans[ch[j].idx]) ans[ch[j].idx] = nn;
		}

		printf("Case #%d:\n", ca);
		for (int i = 0; i < n; ++i)
			printf("%d\n", n - ans[i]);
	}
	return 0;
}
