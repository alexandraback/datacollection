#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int B, N;
	vector<int> M;
	Solver() {
		cin >> B >> N;
		M.resize(B);
		for (int& x : M) cin >> x;
	}
	int r;
	void run() {
		vector<long> a(B);
		for (int i = 0; i < N-1; ++ i) {
			int p = 0;
			for (int i = 1; i < B; ++ i) if (a[i] < a[p]) p = i;
			a[p] += M[p];
		}
		r = 0;
		for (int i = 1; i < B; ++ i) if (a[i] < a[r]) r = i;
		++ r;
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
		cout << r << endl;
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
