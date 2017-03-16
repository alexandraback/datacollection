#include <iostream>
using namespace std;

long long m[1010];
long long n, b;

bool check(long long t) {
	long long cnt = 0;
	for (int i = 0; i < b; i ++)
		cnt += (t / m[i]) + 1;
	return cnt >= n;
}

int solve() {
	cin >> b >> n;
	for (int i = 0; i < b; i ++)
		cin >> m[i];
	long long l = -1, r = 1000000000;
	r *= 1000000;
	while (l + 1 < r) {
		long long t = (l + r) >> 1;
		if (check(t)) r = t;
		else l = t;
	}
	long long cnt = 0;
	for (int i = 0; i < b; i ++)
		if (r % m[i] == 0) cnt += (r / m[i]);
		else cnt += (r / m[i] + 1);
	for (int i = 0; i < b; i ++)
		if (r % m[i] == 0) {
			cnt ++;
			if (cnt == n) return i + 1;
		}
	return -1;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i ++)
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
