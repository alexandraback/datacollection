#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int t, n;
int r[3000];
vector<pair<ll,ll>> v;
ll x, y;

int risti(ll x1, ll y1,ll x2, ll y2, ll x3, ll y3) {
	ll tmp = (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
	if (tmp < 0) return -1;
	if (tmp > 0) return 1;
	return 0;
}

int main() {
	cin >> t;
	for (int i=1; i<= t; i++) {
		cout << "Case #" << i << ":\n";
		cin >> n;
		for (int j=0;j<n;j++) {
			cin >> x >> y;
			v.push_back(make_pair(x,y));
		}
		for (int l=0;l<n;l++) {
			int parsa = n/2;
			for (int j=0;j<n;j++) {
				if (j==l) continue;
				int vas = 0;
				int oik = 0;
				for (int k=0;k<n;k++) {
					if (k == l || k == j) continue;
					int apu =
		risti(v[l].first,v[l].second,v[j].first,v[j].second,
		v[k].first, v[k].second);
					if (apu == -1) vas++;
					else if (apu == 1) oik++;
				}
				vas = min(vas, oik);
				if (vas < parsa) parsa = vas;
			}
			r[l] = parsa;
		}


		for (int j=0;j<n;j++) {
			cout << r[j] << "\n";
		}
		v.clear();
	}
}
