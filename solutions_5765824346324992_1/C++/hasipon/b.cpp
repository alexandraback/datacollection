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
	long f(long t) {
		long rr = 0;
		for (int x : M) rr += (t+x-1) / x;
		return rr;
	}
	void run() {
		long L = 0, R = 1L<<60;
		while (R-L >= 2) {
			long M = (L+R)/2;
			if (N <= f(M)) R = M; else L = M;
		}
		long c = N - f(R-1);
		for (int i = 0; i < B; ++ i) {
			if ((R-1) % M[i] == 0) {
				if (c == 1) {
					r = i + 1;
					break;
				} else -- c;
			}
		}
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
