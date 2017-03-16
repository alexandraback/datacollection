#include <iostream>
#include <cassert>
#include <limits>
#include <vector>

using namespace std;

int B;
long long N;
long long M[1000];

bool served(long long t) {
	long long numServed = 0;
	for (int i = 0; i < B; i++) {
		numServed += 1 + (t / M[i]);
	}
	return numServed >= N;
}

int solve() {
	cin >> B >> N;
	assert(B >= 1 && B <= 1000);
	assert(N >= 1ll && N <= 1000000000ll);
	for (int i = 0; i < B; i++) {
		cin >> M[i];
		assert(M[i] >= 1 && M[i] <= 100000);
	}
	long long lo = -1;
	long long hi = 10000000000000000ll; // 10^16, which is plenty
	while (hi - lo > 1) {
		long long mid = (lo + hi) / 2;
		(served(mid) ? hi : lo) = mid;
	}
	assert(hi == lo + 1);
	//cerr << "  we get our hair cut after " << hi << " minutes." << endl;
	vector<int> available;
	for (int i = 0; i < B; i++) {
		N -= 1 + (lo / M[i]);
		if ((hi % M[i]) == 0) available.push_back(i);
	}
	assert(N > 0 && N <= (long long) available.size());
	return available[N - 1] + 1;
}

int main() {
	int T;
	cin >> T;
	assert(T >= 1 && T <= 100);
	for (int i = 1; i <= T; i++)
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
