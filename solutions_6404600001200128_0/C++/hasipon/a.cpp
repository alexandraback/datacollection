#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int N;
	vector<int> m;
	Solver() {
		cin >> N;
		m.resize(N);
		for (int& x : m) cin >> x;
	}
	int r1, r2;
	void run() {
		r1 = r2 = 0;
		int d = 0;
		for (int i = 1; i < N; ++ i) {
			r1 += max(0, m[i-1] - m[i]);
			d = max(d, m[i-1] - m[i]);
		}
		for (int i = 0; i < N-1; ++ i) {
			r2 += min(m[i], d);
		}
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
		cout << r1 << " " << r2 << endl;
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
