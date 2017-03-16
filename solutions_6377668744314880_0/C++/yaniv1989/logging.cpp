#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

//#define REMOVE_REDUNDANT

typedef double T;
const T EPS = 1e-7;
struct PT { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

bool between(const PT &a, const PT &b, const PT &c) {
	return (fabs(area2(a,b,c)) < EPS);
}

// Based on code for convex hull
void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

int main() {
	ios::sync_with_stdio(false);
	
	int t, T;
	cin >> T;

	for (t = 0; t < T; ++t) {
		int N;
		cin >> N;
		vector<PT> pts(N);
		for (int i = 0; i < N; ++i) {
			cin >> pts[i].x >> pts[i].y;
		}

		vector<int> min_popcnt(N, N+10);
		
		for (int rem = 0; rem < (1<<N); ++rem) {
			vector<PT> chull;
			int popcnt = 0;
			for (int i = 0; i < N; ++i) {
				if (!(rem & (1<<i))) {
					chull.push_back(pts[i]);
				} else {
					popcnt += 1;
				}
			}
			ConvexHull(chull);

			for (size_t i = 0; i < pts.size(); ++i) {
				for (size_t j = 0; j < chull.size(); ++j) { 
					if (pts[i] == chull[j]) {
						min_popcnt[i] = min(min_popcnt[i], popcnt);
					}					
					if (between(pts[i], chull[j], chull[(j+1)%chull.size()])) {
						min_popcnt[i] = min(min_popcnt[i], popcnt);
					}
				}
			}
		}

		cout << "Case #" << (t+1) << ": " << endl;
		for (size_t i = 0; i < min_popcnt.size(); ++i) {
			cout << min_popcnt[i] << endl;
		}

	}

	return 0;
}