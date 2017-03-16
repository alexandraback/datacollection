#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct P {
	ll x, y; bool reflect;
	P(){}
	P(ll lx, ll ly, bool lr) {
		x = lx; y = ly; reflect = lr;
	}
};

ll cx, cy;
struct cmpP {
	bool operator()(const P & p1, const P &p2) const {
		ll dx1 = p1.x - cx, dy1 = p1.y - cy;
		ll dx2 = p2.x - cx, dy2 = p2.y - cy;
		ll cross = dx1 * dy2 - dy1 * dx2;
		return cross > 0; // return true if p2 is ccw from p1
	}
};

int main() {
	int nc; cin >> nc; 
	for (int cs = 1; cs <= nc; cs++) {
		int n; cin >> n; 
		P pts[n];
		for (int i = 0; i < n; i++) {
			cin >> pts[i].x >> pts[i].y;
			pts[i].reflect = false;
		}

		cout << "Case #" << cs << ": " << endl;
		vector<P> sorted, s1, s2, s3, s4;
		for (int i = 0; i < n; i++) {
			cx = pts[i].x; cy = pts[i].y;
			sorted.resize(0);
			s1.resize(0);
			s2.resize(0);
			s3.resize(0);
			s4.resize(0);
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				ll dx = pts[j].x - cx;
				ll dy = pts[j].y - cy;
				P reflect(cx - dx, cy - dy, true);

				if (dy == 0) {
					if (dx > 0) {
						s2.push_back(pts[j]);
						s4.push_back(reflect);
					} else {
						s4.push_back(pts[j]);
						s2.push_back(reflect);
					}
				} else if (dy < 0) {
					s1.push_back(pts[j]);
					s3.push_back(reflect);
				} else {
					s3.push_back(pts[j]);
					s1.push_back(reflect);
				}
			}
			sort(s1.begin(), s1.end(), cmpP());
			sort(s3.begin(), s3.end(), cmpP());
			for (int j = 0; j < s1.size(); j++) sorted.push_back(s1[j]);
			for (int j = 0; j < s2.size(); j++) sorted.push_back(s2[j]);
			for (int j = 0; j < s3.size(); j++) sorted.push_back(s3[j]);
			for (int j = 0; j < s4.size(); j++) sorted.push_back(s4[j]);

			int start = 0;
			int equal1 = 0, equal2 = 0, below = 0, above = 0;
			for (int j = 0; j < sorted.size(); j++) {
				if (!sorted[j].reflect) {
					if (sorted[j].y > cy) {
						above++;
					} else if (sorted[j].y == cy) {
						if (sorted[j].x > cx) equal1++;
						else equal2++;
					} else {
						below++;
						start = j;
					}
				}
			}
			if (above == 0 || below == 0) {
				cout << 0 << endl;
				continue;
			}

			int ans = min(above, below); int ans0 = ans;
			int curr = start;
			while (sorted[curr].y <= cy) curr = (curr+1)%sorted.size();

			//cerr << "pivot: " << cx << " " << cy << endl;
			//cerr << "start: " << below << " " << equal1 << " " << above << " " << equal2 << endl;

			P prev(cx+1, cy, true);
			for (int cnt = 0; cnt < sorted.size(); cnt++) {
				int j = (curr + cnt)%sorted.size();
				P pt = sorted[j];

				// test if same as before
				ll dx1 = pt.x - cx, dy1 = pt.y - cy;
				ll dx2 = prev.x - cx, dy2 = prev.y - cy;
				ll cross = dx1 * dy2 - dy1 * dx2;
				if (cross == 0) {
					if (pt.reflect) {
						equal2++; below--;
					} else {
						equal1++; above--;
					}
				} else {
					below += equal1;
					above += equal2;
					equal1 = 0;
					equal2 = 0;
					if (pt.reflect) {
						below--; equal2++;
					} else {
						above--; equal1++;
					}
				}
				prev = pt;
				ans = min(ans, min(above, below));

				//cerr << "processed: " << pt.x << " " << pt.y << " " << pt.reflect << endl;
				//cerr << "curr: " << below << " " << equal1 << " " << above << " " << equal2 << endl;
			}

			// brute force
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				above = 0; below = 0;
				for (int k = 0; k < n; k++) {
					if (k == i) continue;
					ll dx1 = pts[j].x - cx, dy1 = pts[j].y - cy;
					ll dx2 = pts[k].x - cx, dy2 = pts[k].y - cy;
					ll cross = dx1 * dy2 - dy1 * dx2;
					if (cross > 0) above++;
					else if (cross < 0) below++;
				}
				ans0 = min(ans0, min(above, below));
			}
			if (ans < 0) ans = 0; // hack
			if (ans != ans0) cerr << "wrong!" << endl;
			cout << ans << endl;
		}
	}
}
