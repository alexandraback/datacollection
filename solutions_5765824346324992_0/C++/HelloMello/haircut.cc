#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long gcd(long long a, long long b) {
	while (true) {
		if (a == 0) {
			return b;
		}
		b %= a;
		if (b == 0) {
			return a;
		}
		a %= b;
	}
	return 0;
}

long long lcm(long long a, long long b) {
	long long g = gcd(a, b);
	if (g <= 0) {
		return g;
	}
	g = a / g;
	a = g * b;
	if (b != 0 && a / b != g) {
		return -1;
	}
	return a;
}

int main() {
	int t;
	cin >> t;
	for (int l0 = 0; l0 < t; l0++) {
		int b, n;
		cin >> b >> n;
		n -= 1;
		vector<int> a(b);
		priority_queue<pair<long long, int>, vector<pair<long long, int> >, std::greater<pair<long long, int> > > q;
		long long cycle = 1;
		for (int l1 = 0; l1 < b; l1++) {
			cin >> a[l1];
			q.push(make_pair(0, l1));
			cycle = lcm(cycle, a[l1]);
		}
		if (cycle > 0) {
			long long cycles = 0;
			for (int l1 = 0; l1 < b; l1++) {
				cycles += cycle / a[l1];
			}
			//cout << cycle << ' ' << cycles << ' ' << n << ' ' << n % cycles << endl;
			n %= cycles;
		}

		for (int l1 = 0; l1 < n; l1++) {
			int c = q.top().second;
			q.push(make_pair(q.top().first + a[c], c));
			q.pop();
		}

		cout << "Case #" << l0 + 1 << ": " << q.top().second + 1 << endl;
	}
	return 0;
}