#include <bits/stdc++.h>

using namespace std;

#define fillchar(a, s) memset((a), (s), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define rep(it, v) for (auto it = (v).begin(); it != (v).end(); it++)

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<ll> point;
const int MAXN = 3010;

ll cross (point a, point b) {
	return a.real() * b.imag() - a.imag() * b.real();
}

ll cross (point a, point b, point c) {
	//a is the "origin"
	return cross(b - a, c - a);
}

bool sortx (point a, point b) {
	return a.real() < b.real() || (a.real() == b.real() && a.imag() < b.imag());
}

point cmpt;

bool cmpang (point a, point b) {
	//well let's do it
	ll c = cross(cmpt, a, b);
	return c ? c > 0 : norm(a - cmpt) < norm(b - cmpt);
}

int N;
bool dbg;

vector<point> convexhull (vector<point> v) {
	auto it = min_element(all(v), sortx);
	iter_swap(it, v.begin());
	cmpt = v[0];
	sort(v.begin() + 1, v.end(), cmpang);
	vector<point> hull;
	for (point cur : v) {
		while (hull.size() >= 2) {
			point last = hull.back(), last2 = hull[hull.size() - 2];
			if (cross(last2, last, cur) <= 0) {
				hull.pop_back();
			} else {
				break;
			}
		}
		hull.push_back(cur);
	}
	return hull;
}

ll hsh (ll x, ll y) {
	return 2e6 * (x + 2e6) + (y + 2e6);
}

ll hsh (point p) {
	return hsh(p.real(), p.imag());
}

point P[MAXN];
int ans[MAXN];
unordered_map<ll, int> mp;

void go (int tt) {
	printf("Case #%d:\n", tt);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		P[i].real(x);
		P[i].imag(y);
		mp[hsh(x, y)] = i;
		ans[i] = N;
	}
	//try every single set
	for (int i = 1; i < (1 << N); i++) {
		//these remain
		int cut = N - __builtin_popcount(i);
		vector<point> v;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				v.push_back(P[j]);
			}
		}
		v = convexhull(v);
		for (int i = 0; i < 15; i++) {
			point p = P[i];
			bool found = false;
			if (find(all(v), p) != v.end()) {
				//then break
				found = true;
			}
			//else check if it's on the damn boundary
			for (int j = 0, sz = v.size(); j < sz; j++) {
				point p1 = v[j], p2 = v[(j + 1) % sz];
				int xmin = min(p1.real(), p2.real()), xmax = max(p1.real(), p2.real());
				int ymin = min(p1.imag(), p2.imag()), ymax = max(p1.imag(), p2.imag());
				if (xmin <= p.real() && p.real() <= xmax) {
					if (ymin <= p.imag() && p.imag() <= ymax) {
						if (cross(p, p1, p2) == 0) {
							//then it still orks
							found = true;
							break;
						}
					}
				}
			}
			if (found) {
				int h = mp[hsh(p)];
				ans[h] = min(ans[h], cut);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", ans[i]);
	}
}

int main() {
	if (fopen("logging_small.in", "r")) {
		freopen("logging_small.in", "r", stdin);
		freopen("logging_small.out", "w", stdout);
	}
	int tt;
	scanf("%d", &tt);
	for (int i = 1; i <= tt; i++) {
		go(i);
	}
}