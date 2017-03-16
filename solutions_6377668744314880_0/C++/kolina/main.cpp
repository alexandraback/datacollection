#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <sstream>
#include <cassert>

using namespace std;

struct point {
	long long x, y;
};

bool compare(const pair<int, point>& a, const pair<int, point>& b) {
	return a.second.x < b.second.x || (a.second.x == b.second.x && a.second.y < b.second.y);
}

bool cross(const point& a, const point& b, const point& c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0;
}

bool cross_counter(const point& a, const point& b, const point& c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) >= 0;
}

int convex_hull(vector<pair<int, point> >& a) {
	if (a.size() == 1)
		return (1 << a[0].first);
	sort(a.begin(), a.end(), compare);
	pair<int, point> p1 = a[0],  p2 = a.back();
	vector<pair<int, point> > up, down;
	up.push_back(p1);
	down.push_back(p1);
	for (size_t i = 1; i < a.size(); ++i) {
		if (i == a.size() - 1 || cross(p1.second, a[i].second, p2.second)) {
			while (up.size() >= 2 && !cross(up[up.size() - 2].second, up[up.size() - 1].second, a[i].second))
				up.pop_back();
			up.push_back(a[i]);
		}
		if (i == a.size() - 1 || cross_counter(p1.second, a[i].second, p2.second)) {
			while (down.size() >= 2 && !cross_counter(down[down.size() - 2].second, down[down.size() - 1].second, a[i].second))
				down.pop_back();
			down.push_back(a[i]);
		}
	}
	int res = 0;
	for (size_t i = 0; i < up.size(); ++i)
		res |= (1 << up[i].first);
	for (size_t i = down.size() - 2; i > 0; --i)
		res |= (1 << down[i].first);
	return res;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n;
		cin >> n;
		vector<point> p(n);
		for (int i = 0; i < n; ++i)
			cin >> p[i].x >> p[i].y;
		vector<int> res(1 << n);
		for (int mask = 1; mask < (1 << n); ++mask) {
			vector<pair<int, point> > v;
			for (int j = 0; j < n; ++j) {
				if ((1 << j) & mask)
					v.push_back(make_pair(j, p[j]));
			}
			res[mask] = convex_hull(v);
		}
		cout << "Case #" << t + 1 << ":\n";
		for (int i = 0; i < n; ++i) {
			int best = n - 1;
			for (int mask = 0; mask < (1 << n); ++mask) {
				if ((mask & (1 << i)) && (res[mask] & (1 << i))) {
					int k = 0;
					for (int l = 0; l < n; ++l) {
						if (mask & (1 << l))
							++k;
					}
					best = min(best, n - k);
				}
			}
			cout << best << "\n";
		}
	}
    return 0;
}