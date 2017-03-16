

#if 1

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;
typedef int64_t int64;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define mp make_pair
#define X first
#define Y second
#define pb push_back

static void solve();

int main() {
	freopen("C.in.txt","r",stdin);
	freopen("C.out.txt","w",stdout);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; ++t) {
		cout << "Case #" << t << ": ";
		solve();
		cout << '\n';
	}
	return 0;
}

static int64 gcd(int64 a, int64 b) {
	if (a < 0 || b < 0)
		return -1;
	while (b != 0) {
		int64 x = a % b;
		a = b;
		b = x;
	}
	return a;
}

static double angleDelta(double a, double b) {
	double delta = a - b;
	if (delta < 0)
		delta += 2 * M_PI;
	return delta;
}

static int minForHull(vector<pii> const & pts, int k) {
	int n = int(pts.size());
	if (n <= 3)
		return 0;
	vector<double> tan(n);
	vector<pii> dpts(n);
	vector<int> index;
	for (int i = 0; i < n; i++) {
		if (i != k) {
			index.pb(i);
			int dy = pts[i].Y - pts[k].Y;
			int dx = pts[i].X - pts[k].X;
			int g = int(gcd(abs(dx), abs(dy)));
			dpts[i] = mp(dx, dy);
			//cout << endl << dx <<  " " << dy << " " << g;
			tan[i] = atan2(dy / g, dx / g);
		}
	}
	sort(index.begin(), index.end(), [&](int a, int b) {
		return tan[a] < tan[b];
	});
	int b = 0;
	int best = n;
	int ni = int(index.size());
	for (int a = 0; a < ni; a++) {
		while ((b + 1) % ni != a && angleDelta(tan[index[(b + 1) % ni]], tan[index[a]]) < M_PI) {
			b = (b + 1) % ni;
		}
		int c = b;
		while ((c + 1) % ni != a && dpts[index[a]].X == -dpts[index[(c + 1) % ni]].X && dpts[index[a]].Y == -dpts[index[(c + 1) % ni]].Y) {
			c = (c + 1) % ni;
		}
		int neq = c - b;
		int nlt = (b - a + ni) % ni;
		int ngt = ni - 1 - neq - nlt;
		best = min(best, nlt);
		best = min(best, ngt);
		if (best == 0)
			break;
	}
	if (best == n)
		throw 1;
	return best;
}

static void solve() {

	int n;
	cin >> n;
	vector<pii> pts;
	vector<int> m(n, n);
	generate_n(back_inserter(pts), n, []() { int x, y; cin >> x >> y; return mp(x, y); });
	
	for (int i = 0; i < n; i++) {
		m[i] = minForHull(pts, i);
	}
	
	for (auto mm : m)
		cout << endl << mm;
}

#endif

