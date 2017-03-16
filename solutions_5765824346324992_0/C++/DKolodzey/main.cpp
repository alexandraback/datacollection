#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
	while (a % b != 0) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return b;
}

const int MAX_B = 1050;
long long m[MAX_B];
long long s[MAX_B];

int main() {
	/*
	long long a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	*/
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int B;
		long long N;
		cin >> B >> N;
		for (int i = 1; i <= B; ++i) {
			cin >> m[i];
		}
		long long lcm = m[1];
		for (int i = 2; i <= B; ++i) {
			lcm /= gcd(lcm, m[i]);
			lcm *= m[i];
		}
		int clients_to_lcm = 0;
		for (int i = 1; i <= B; ++i) {
			clients_to_lcm += lcm / m[i];
		}
		N = (N - 1) % clients_to_lcm;
		for (int i = 1; i <= B; ++i) {
			s[i] = 0;
		}
		int ans = 1;
		for (int i = 0; i <= N; ++i) {
			ans = 1;
			for (int j = 1; j <= B; ++j) {
				//cout << s[j] << " ";
				ans = (s[j] < s[ans]) ? j : ans;
			}
			//cout << endl;
			s[ans] += m[ans];
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	
	return 0;
}