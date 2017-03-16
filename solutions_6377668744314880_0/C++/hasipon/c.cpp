#include <bits/stdc++.h>
using namespace std;
typedef complex<long> P;
long dot(const P& x, const P& y) {
	return (conj(x) * y).real();
}
long cross(const P& x, const P& y) {
	return (conj(x) * y).imag();
}
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if (cross(b, c) > 0)   return +1;       // counter clockwise
	if (cross(b, c) < 0)   return -1;       // clockwise
	if (dot(b, c) < 0)     return +2;       // c--a--b on line
	if (norm(b) < norm(c)) return -2;       // a--b--c on line
	return 0;
}
vector<P> convex_hull(vector<P> ps) {
	int n = ps.size(), k = 0;
	sort(ps.begin(), ps.end());
	vector<P> ch(2*n);
	for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
		while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
	for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
		while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
	ch.resize(k-1);
	return ch;
}

struct Solver {
	int N;
	vector<P> pp;
	Solver() {
		cin >> N;
		pp.resize(N);
		for (int i = 0; i < N; ++ i) {
			int x, y;
			cin >> x >> y;
			pp[i] = P(x, y);
		}
	}
	int f(int x) {
		if (N <= 3) return 0;
		int r = 1<<30;
		for (int p = 0; p < (1<<N); ++ p) if (!((p>>x)&1)) {
			int c = __builtin_popcount(p);
			if (c >= r) continue;
			if (N - c > 3) {
				vector<P> a;
				for (int i = 0; i < N; ++ i) if (i != x) if (!((p>>i)&1)) a.push_back(pp[i]);
				vector<P> b = convex_hull(a);
				bool f1 = true, f2 = true;
				for (unsigned i = 0; i < b.size(); ++ i) {
					const P& p0 = b[i];
					const P& p1 = b[(i+1)%b.size()];
					long c = cross(pp[x]-p0, pp[x]-p1);
					if (c >= 0) f1 = false;
					if (c <= 0) f2 = false;
				}
				if (f1 || f2) goto next;
			}
			r = c;
			next:;
		}
		return r;
	}
	vector<int> res;
	void run() {
		res.resize(N);
		for (int i = 0; i < N; ++ i) {
			res[i] = f(i);
		}
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ":" << endl;
		for (int x : res) cout << x << endl;
	}
};

int main() {
	int T;
	cin >> T;
	vector<future<Solver*>> results;
	for (int tt = 1; tt <= T; ++ tt) {
		auto a = new Solver;
		a->tt_ = tt;
		results.push_back(async(
			launch::async, // async or deferred
			[](Solver* solver) {
				solver->run();
				return solver;
			},
			a
		));
	}
	for (auto& x : results) {
		auto a = x.get();
		a->output();
		delete a;
	}
}
