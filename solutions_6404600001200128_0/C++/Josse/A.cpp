#include <iostream>
#include <cassert>

using namespace std;

struct answer_t {
	long long a, b;
	friend ostream& operator<<(ostream& os, const answer_t& ans) {
		os << ans.a << " " << ans.b;
		return os;
	}
};

long long sample[1000];

answer_t solve() {
	int N;
	cin >> N;
	assert(N >= 2 && N <= 1000);
	long long totaldiff = 0;
	long long maxdiff = 0;
	for (int i = 0; i < N; i++) {
		cin >> sample[i];
		assert(sample[i] >= 0 && sample[i] <= 10000);
		if (i) {
			long long curdiff = sample[i - 1] - sample[i];
			maxdiff = max(maxdiff, curdiff);
			totaldiff += max(0ll, curdiff);
		}
	}
	long long eatWhenAvailable = 0;
	for (int i = 0; i < N - 1; i++) {
		eatWhenAvailable += min(sample[i], maxdiff);
	}
	return (answer_t) {totaldiff, eatWhenAvailable};
}

int main() {
	int T;
	cin >> T;
	assert(T >= 1 && T <= 100);
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}
