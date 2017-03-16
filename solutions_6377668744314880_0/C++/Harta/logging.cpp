#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz size()
typedef long long ll;
typedef vector<int> vi;
const int oo = (int)1e9;

struct point {
	int x, y;
	point() {};
	point(int _x, int _y) {
		x = _x; y = _y;
	}

	bool operator<(const point &X) const {
		return make_pair(y, x) < make_pair(X.y, X.x);
	}
	bool operator==(const point &X) const {
		return make_pair(y, x) == make_pair(X.y, X.x);
	}
};

const int MAXN = 3010;

int t, n, ans[MAXN];
point p[MAXN];

ll cross(point p, point q) {
	return (ll)p.x * (ll)q.y - (ll)p.y * (ll)q.x;
}

ll area2(point a, point b, point c) {
	return cross(a, b) + cross(b, c) + cross(c, a);
}

void convexHull(vector<point> &pts) {
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());
	vector<point> up, dn;
	for (int i = 0; i < pts.sz; i++) {
		while (up.sz > 1 && area2(up[up.sz - 2], up.back(), pts[i]) > 0) up.pop_back();
		while (dn.sz > 1 && area2(dn[dn.sz - 2], dn.back(), pts[i]) < 0) dn.pop_back();
		up.pb(pts[i]);
		dn.pb(pts[i]);
	}
	pts = dn;
	for (int i = (int)up.sz - 2; i >= 1; i--) pts.pb(up[i]);
}

int main() {
	scanf("%d", &t);
	int xx = 1;
	while (t--) {
		scanf("%d", &n);
		map<point, int> mp;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &p[i].x, &p[i].y);
			mp[p[i]] = i;
		}
		printf("Case #%d:\n", xx++);
		for (int i = 0; i < n; i++) ans[i] = INT_MAX;
		for (int i = 0; i < (1 << n); i++) {
			vector<point> vtr;
			int taken = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					vtr.pb(p[j]);
					taken++;
				}
			}
//			for (int j = 0; j < vtr.sz; j++) 
//				cout << vtr[j].x << ' ' << vtr[j].y << endl;
			convexHull(vtr);
//			cout << "CV" << endl;
			for (int j = 0; j < vtr.sz; j++) {
//				cout << vtr[j].x << ' ' << vtr[j].y << endl;
				int id = mp[vtr[j]];
				ans[id] = min(ans[id], n - taken);
			}
		}
		for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
	}
	return 0;
}
