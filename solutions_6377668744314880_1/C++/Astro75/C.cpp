#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,pii> pp;

#define X second.first
#define Y second.second
#define A first

int n, x[3000], y[3000];
vector<pp> v;

void solve() {
	cin >> n;
	REP(i,n) {
		cin >> x[i] >> y[i];
	}
	if (n <= 3) {
		REP(i,n) {
			cout << 0 << endl;
		}
		return;
	}
	REP(i,n) {
		v.clear();
		REP(j,n) if (i != j) {
			int dx = x[j]-x[i];
			int dy = y[j]-y[i];
			v.push_back(pp(atan2(dy,dx),pii(dx,dy)));
		}
		if (i == 0) {
			bool good = false;
			FOR(j,1,n-2){
				ll dx = v[0].X;
				ll dy = v[0].Y;
				ll tmp = dx * (v[j].Y) - dy * (v[j].X);
				if (tmp != 0) {
					good = true;
					break;
				}
			}
			if (!good) {
				REP(i,n) {
					cout << 0 << endl;
				}
				return;
			}
		}
		sort(v.begin(), v.end());
		int r = 0;
		int tot = 0;
		int res = 100000;
		REP(l,n-1) {
			// if (r == l) {
			// 	r++;
			// 	tot++;
			// 	r %= n-1;
			// }
			ll dx = v[l].X;
			ll dy = v[l].Y;
			ll dx2 = v[(l+1)%(n-1)].X;
			ll dy2 = v[(l+1)%(n-1)].Y;
			ll tmpa = dx * dy2 - dy * dx2;
			ll tmpb = dx * dx2 + dy * dy2;
			bool good = true;
			if (tmpa == 0 && tmpb > 0) {
				// cout << "!!!!   ";
				good = false;
			}
			if (l == r) {
				r++;
				tot++;
				r %= n-1;
			}
			while (good && (r+1)%(n-1) != l) {
				ll tmp = dx * (v[r].Y) - dy * (v[r].X);
				if (tmp <= 0) break;
				// if (tmp == 0) {
				// 	ll tmp2 = dx * (v[r].X) + dy * (v[r].Y);
				// 	// cout << tmp2 << ' ' << l << ' ' << r << endl;
				// 	if (tmp2 < 0) break;
				// }
				r++;
				tot++;
				r %= n-1;
			}
			// cout << l << ' ' << r << 
			// " (" << v[l].X<<", "  << v[l].Y << ") "<< 
			// " (" << v[r].X<<", "  << v[r].Y << ") "<< 
			// ' ' << tot-l << endl;
			if (good) res = min(res, tot-l-1);
		}
		cout << res << endl;
	}
}

int main() {
	int t;
	scanf(" %d", &t);
	REP(i, t) {
		printf("Case #%d:\n", i+1);
		solve();
	}
}