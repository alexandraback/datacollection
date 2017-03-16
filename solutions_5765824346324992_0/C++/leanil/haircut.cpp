#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <utility>
#include <functional>
#include <numeric>

using namespace std;

long long gcd(long long a, long long b) {
	for (;;) {
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}

long long lcm(long long a, long long b) {
	long long temp = gcd(a, b);
	return temp ? (a / temp * b) : 0;
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int T;
	in >> T;
	for (int test = 1; test <= T; test++) {
		int B, N;
		in >> B >> N;
		vector<int> M(B);
		copy_n(istream_iterator<int>(in), B, M.begin());
		long long result = accumulate(M.begin(), M.end(), 1LL, lcm);
		long long sum = 0;
		for (int i = 0; i < B; i++) {
			sum += result / M[i];
		}

		using next_free = pair < long long, int > ;
		priority_queue<next_free, vector<next_free>, greater<next_free >> ready;
		for (int i = 0; i < B; i++) {
			ready.push({ 0, i });
		}
		for (int i = 0; i < (N -1) % sum; i++) {
			auto top = ready.top();
			ready.pop();
			ready.push({ top.first + M[top.second], top.second });
		}

		out << "Case #" << test << ": " << ready.top().second + 1 << endl;
	}
	return 0;
}