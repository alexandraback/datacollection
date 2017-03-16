#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define MP make_pair

typedef long long ll;
int T;

struct pt { 
	ll x, y;
	pt() { }
	pt(ll _x, ll _y) {
		x = _x;
		y = _y;
	}
};
const int N = 3005;
ll n;
pt p[N];

ll cross(const pt& a, const pt& b) {
	return a.x * b.y - a.y * b.x;
}
bool cmp_angle(const pt& a, const pt& b) {
	if (a.y < 0 && b.y >= 0) return true;
	if (a.y >= 0 && b.y < 0) return false;
	if (a.y == 0 && b.y == 0 && a.x * b.x < 0) return a.x > 0; //careful of overflow...
	return cross(a, b) > 0; //now guarantee they are < 180deg apart
}

bool mycmp(const pair<pt,int>& a, const pair<pt,int>& b) {
	bool x = cmp_angle(a.first, b.first);
	if (x) return true;
	x = cmp_angle(b.first, a.first);
	if (x) return false;
	return a.second < b.second;
}

int main() {
	cin >> T;
	REP(qqq,T) {
		cin >> n;
		REP(i,n) {
			cin >> p[i].x >> p[i].y;
		}

		cout << "Case #" << (qqq+1) << ":" << endl;
		REP(i,n) {
			ll ans = n-1;
			vector<pair<pt,int> > v;
			REP(j,n) if (i != j) {
				v.push_back(MP(pt(p[j].x - p[i].x,
					p[j].y - p[i].y), -1));
				v.push_back(MP(pt(-(p[j].x - p[i].x),
					-(p[j].y - p[i].y)), 1));
			}
			sort(v.begin(), v.end(), mycmp);

			ll cnt = 0;
			pt z; z.x = 1e6; z.y = 0;
			//cout << p[i].x << " " << p[i].y << endl;
			REP(j,n) {
				pt z2; z2.x = p[j].x - p[i].x;
				z2.y = p[j].y - p[i].y;
				if (i != j && !cmp_angle(z, z2)) {
					cnt++;
					//cout << z2.x << "." << z2.y << ", ";
				}
			}
			//cout << endl;
			//cout << "!" << i << " " << cnt << endl;
			int j = 0;
			while (j < v.size()) {
				bool cont;
				if (v[j].second == -1) {
					do {
						cnt += v[j].second;
						//cout << " " << cnt << " (" << v[j].first.x << " " << v[j].first.y << ")" << " " << v[j].second << endl;
						cont = j < v.size() && !cmp_angle(v[j].first,v[j+1].first) && v[j].second == v[j+1].second;
						j++;
					} while (j < v.size() && cont);
				}
				//cout << "ok" << endl;
				ans = min(ans, cnt);
				if (v[j].second == 1) {
					do {
						cnt += v[j].second;
						//cout << " " << cnt << " (" << v[j].first.x << " " << v[j].first.y << ")" << " " << v[j].second << endl;
						cont = j < v.size() && !cmp_angle(v[j].first,v[j+1].first) && v[j].second == v[j+1].second;
						j++;
					} while (j < v.size() && cont);
				}
				//cout << "ok2" << endl;
			}

			cout << ans << endl;
		}
	}
}
