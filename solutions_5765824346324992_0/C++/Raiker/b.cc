#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

long long num_served(long long t, vector<int> &m_k);

int gcd(int a, int b) {
	if (a < b) {
		return gcd(b, a);
	}

	if (b == 0) {
		return a;
	}

	return gcd(b, a - b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main() {
	int ncases;

	cin >> ncases;

	for (int c = 1; c <= ncases; c++) {
		int b;
		long long n;

		cin >> b >> n;

		vector<int> m_k;

		//int lcm_cur = 1;

		for (int i = 0; i < b; i++) {
			int m;

			cin >> m;

			m_k.push_back(m);

			//lcm_cur = lcm(m, lcm_cur);
		}

		long long lower = -1, upper = LLONG_MAX/10000000;

		if (num_served(upper, m_k) < n) {
			cerr << "Problem" << endl;
			return -1;
		}

		/*if (num_served(lower, m_k) >= n) {
			upper = lower;
		}*/

		while (upper - lower > 1) {
			long long test = (upper + lower) / 2;
			if (num_served(test, m_k) >= n) {
				upper = test;
			} else {
				lower = test;
			}
			//cout << upper << " " << lower << endl;
		}


		//cout << num_served(upper, m_k) << " " << num_served(lower, m_k) << endl;

		long long n2 = n - num_served(lower, m_k);

		//cout << n2 << endl;

		for (int i = 0; i < m_k.size(); i++) {
			int m = m_k[i];
			if (upper % m == 0) {
				n2--;
				if (n2 == 0) {
					cout << "Case #" << c << ": " << (i + 1) << endl;
					break;
				}
			}
			//cout << i << " " << m << " " << n2 << endl;
		}

		/*int per_lcm = 0;

		for (int m : m_k) {
			per_lcm += (lcm_cur / m);
		}

		n = n % per_lcm;



		cout << "Case #" << c << ": " << 0 << endl;*/
	}

	return 0;
}

long long num_served(long long t, vector<int> &m_k) {
	if (t < 0) return 0;

	long long sum = 0;
	for (int m : m_k) {
		sum += (t / m) + 1;
	}
	return sum;
}