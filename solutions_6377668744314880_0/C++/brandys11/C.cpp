#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int sucin(pll a, pll b, pll c) {
	b.first -= a.first;
	b.second -= a.second;
	c.first -= a.first;
	c.second -= a.second;

	ll ss = b.first * c.second - b.second * c.first;

	if(ss > 0) return 1;
	if(ss < 0) return -1;
	return 0;
}

vector<pll> points;
vector<bool> active;

set<pll> obal() {
	set<pll> A;
	vector<pll> P;
	for(int i =0; i < points.size(); i++) 
		if(active[i]) P.push_back(points[i]);

	sort(P.begin(), P.end());
	if(P.size() < 3) {
		for(auto a: P) A.insert(a);
		return A;
	}

	vector<pll> ob;
	ob.push_back(P[0]);
	ob.push_back(P[1]);


	for(int i=2; i < P.size(); i++) {
      auto next = P[i];
      int siz = ob.size();
      while(ob.size() >= 2 && sucin(ob[siz-2], ob[siz-1], next) > 0) {
        ob.pop_back();
        siz--;
      }
      ob.push_back(next);
    }

    for(int i=P.size() - 2; i >= 0; i--) {
      auto next = P[i];
      int siz = ob.size();
      while(ob.size() >= 2 && sucin(ob[siz-2], ob[siz-1], next) > 0) {
        ob.pop_back();
        siz--;
      }
      ob.push_back(next);
    }

	for(auto a: ob) A.insert(a);

	return A;
}

int solve() {
	int n;
	cin >> n;
	points.resize(n);
	active.resize(n);
	for(auto &a: points) cin >> a.first >> a.second;

	vector<int> best(n, 0);
	for(int i=1; i < (1 << n); i++) {
		for(int j = 0; j < n; j++) {
			if(!(i & (1 << j))) active[j] = 0;
			else active[j] = 1;
		}

		set<pll> O = obal();
		for(int j=0; j < n; j++) 
			if(O.count(points[j]) != 0) best[j] = max(best[j], __builtin_popcount(i));
	}

	for(auto a: best) cout << n - a << endl;
	return 0;
}

int main(void) {
	int t;
	cin >> t;
	for(int i=1; i <= t; i++) {
		cout << "Case #" << i << ":" << endl;
		solve();
	}	
}