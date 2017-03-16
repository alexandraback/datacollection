/* attention to overflow */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <queue>
#include <sstream>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <tuple>
#include <iomanip>
#include <complex>

#define dump(x) cerr<< #x << " = " << x <<endl
#define ALL(container) (container).begin(),(container).end()

using namespace std;
const int INF = 1 << 25;
void io() { cin.tie(0); ios::sync_with_stdio(false);}
template <class S, class T> ostream& operator<<(ostream& os, const pair <S, T> &s) {return os << '(' << s.first << ',' << s.second << ')';}
/*printf("%.9Lf\n",cf);*/
const int MOD = 1000000007;
const double EPS = 1e-8;

using point = complex <double>;

namespace std {
bool operator < (const point& a, const point& b) {
	return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
}

double cross(const point& a, const point& b) {
	return imag(conj(a) * b);
}
double dot(const point& a, const point& b) {
	return real(conj(a) * b);
}


int ccw(point a, point b, point c) {
	b -= a; c -= a;
	if (cross(b, c) > 0)   return +1;       // counter clockwise
	if (cross(b, c) < 0)   return -1;       // clockwise
	if (dot(b, c) < 0)     return +2;       // c--a--b on line
	if (norm(b) < norm(c)) return -2;       // a--b--c on line
	return 0;
}

vector<point> convex_hull(vector<point> ps) {
	int n = ps.size(), k = 0;
	sort(ps.begin(), ps.end());
	vector<point> ch(2 * n);
	for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0 && ccw(ch[k - 2], ch[k - 1], ps[i]) > -2) --k;
	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) // upper-hull
		while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0 && ccw(ch[k - 2], ch[k - 1], ps[i]) > -2) --k;
	ch.resize(k - 1);
	return ch;
}

int nisin(int a) {
	while (a > 0) {
		cerr << (a & 1) << ' ';
		a /= 2;
	}
	cerr << endl;
}

int main() {
	io();
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		vector <point> tree(N);
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			tree[i] = point(1.0 * x, 1.0 * y);
		}
		vector <int> ans(N, INF);
		for (int i = 0; i < (1 << N); i++) {
			int cnt = __builtin_popcount(i);
			if (cnt < 3) continue;
			//nisin(i);
			vector <point> nw;
			for (int j = 0; j < N; j++) {
				if ((i >> j) & 1) {
					nw.push_back(tree[j]);
				}
			}
			vector <point> result = convex_hull(nw);
			/*for(int j=0;j<result.size();j++){
				cerr<<result[j]<<' ';
			}
			cerr<<endl;*/
			for (int j = 0; j < result.size(); j++) {
				for (int k = 0; k < N; k++) {
					if (result[j] == tree[k]) {
						ans[k] = min(ans[k], N - cnt);
					}
				}
			}
		}

		cout << "Case #" << t + 1 << ':' << endl;
		for (int i = 0; i < N; i++) {
			cout << ans[i] << endl;
		}
	}

	return 0;
}