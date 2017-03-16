#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;
long long a[MAX_N];

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		long long max_diff = 0;
		cin >> a[0];
		long long ans_1 = 0;
		for (int i = 1; i < N; ++i) {
			cin >> a[i];
			ans_1 +=  max((long long) 0, a[i - 1] - a[i]);
			max_diff = max(a[i - 1] - a[i], max_diff);
		}
		long long ans_2 = 0;
		for (int i = 0; i < N - 1; ++i) {
			ans_2 += min(max_diff, a[i]);
		}
		cout << "Case #" << t << ": " << ans_1 << " " << ans_2 << endl;
	}
	return 0;
}