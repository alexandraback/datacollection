#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (int)(x.size())
#define FOR(i, s, e) for (int i = int(s); i < int(e); ++i)
#define FORIT(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
const int MOD = 1000000007;
const int MAX = 3010;

char str_template[] = "Case #%d:";
char str_answer[sizeof(str_template)];

const double eps = 1e-10;

int dcmp(double x) {
	if (fabs(x) < eps) {
		return 0;
	}
	return x < 0 ? -1 : 1;
}

struct Point {
	double x, y;
	Point() {
		x = y = 0;
	}
	Point(double x, double y) :
			x(x), y(y) {
	}
	bool operator==(const Point& rhs) const {
		return dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) == 0;
	}
	bool operator<(const Point& rhs) const {
		return dcmp(x - rhs.x) < 0
				|| (dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) < 0);
	}
};
typedef Point Vector;

double dist(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Vector operator-(Point A, Point B) {
	return Vector(A.x - B.x, A.y - B.y);
}

double Cross(Vector A, Vector B) {
	return A.x * B.y - A.y * B.x;
}

int ConvexHull(Point *p, Point *ch, int n) {
	sort(p, p + n);
	int i, m = 0, k;
	for (i = 0; i < n; i++) {
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0) {
			m--;
		}
		ch[m++] = p[i];
	}
	k = m;
	for (i = n - 2; i >= 0; i--) {
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) < 0) {
			m--;
		}
		ch[m++] = p[i];
	}
	if (n > 1) {
		m--;
	}
	return m;
}

Point P[MAX], ch[MAX], pt[MAX];
int n;
int ans[MAX];

int main() {
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; ++testcase) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> P[i].x >> P[i].y;
		}
		int lim = (int) pow(2, n);
		memset(ans, 0x3f, sizeof(ans));

		for (int i = 1; i < lim; ++i) {
			int len = 0;
			for (int j = 0; j < n; ++j) {
				if ((i & (1 << j)) > 0) {
					pt[len++] = P[j];
				}
			}
			int m = ConvexHull(pt, ch, len);
//			if (i == 511) {
//				for (int j = 0; j < len; ++j) {
//					cout << pt[j].x << " " << pt[j].y << endl;
//				}
//				cout <<endl;
//				for (int j = 0; j < m; ++j) {
//					cout << ch[j].x << " " << ch[j].y << endl;
//				}
//			}
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < n; ++k) {
					if (ch[j] == P[k]) {
//						if (n - len == 1 && k == 4 && i == 510) {
//							cout << pt[k].x << " " << pt[k].y << endl;
//						}
						ans[k] = min(ans[k], n - len);
					}
				}
			}
		}
		sprintf(str_answer, str_template, testcase);
		cout << str_answer << endl;

		for (int i = 0; i < n; ++i) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}
