#include <bits/stdc++.h>
using namespace std;
typedef complex<long> P;
long cross(const P& x, const P& y) {
	return (conj(x) * y).imag();
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
	vector<int> res;
	void run() {
		if (N <= 3) {
			res.resize(N, 0);
			return;
		}
		res.resize(N, 1<<30);
		for (int i = 0; i < N; ++ i) {
			for (int j = i+1; j < N; ++ j) {
				vector<int> a;
				int n1 = 0, n2 = 0;
				for (int k = 0; k < N; ++ k) {
					if (k == i || k == j) {
						a.push_back(k);
					} else {
						long c = cross(pp[k]-pp[i], pp[j]-pp[i]);
						if (c == 0) a.push_back(k); else if (c < 0) ++ n1; else ++ n2;
					}
				}
				int rr = min(n1, n2);
				for (int k : a) res[k] = min(res[k], rr);
			}
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
