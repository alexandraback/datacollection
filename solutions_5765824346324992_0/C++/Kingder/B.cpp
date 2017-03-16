#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;
int A[MAXN];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int get_lcm (int a, int b) {
	return a / gcd(a, b) * b;
}

int BB[MAXN];

int main () {
	int cases;
	cin >> cases;

	for (int tc = 1; tc <= cases; tc ++) {
		int B, N;
		cin >> B >> N;
		int lcm = 1;
		for (int i = 0; i < B; i ++) {
			cin >> A[i];
			lcm = get_lcm(lcm, A[i]);
		}
		
		int oneTurn = 0;
		for (int i = 0; i < B; i ++) {
			oneTurn += lcm / A[i];
		}

		N = N % oneTurn;

		if (N == 0) N = oneTurn;

		//cout << lcm << " " << N << " " << oneTurn << endl;
		fill (BB, BB+MAXN, 0);
		int ret = -1;
		for (int i = 0; i < N; i ++) {
			bool found = false;
			int m = INT_MAX;
			for (int j = 0; j < B; j ++) {
				if (BB[j] == 0) {
					BB[j] = A[j];
					found = true;
					ret = j + 1;
					break;
				}
				m = min(m, BB[j]);
			}
			if (found == false) {
				for (int j = 0; j < B; j ++) {
					BB[j] -= m;
					if (!found && BB[j] == 0) {
						found = true;
						BB[j] = A[j];
						ret = j + 1;
					}
				}
			}
		}

		cout << "Case #" << tc << ": " << ret << endl;
	}
}