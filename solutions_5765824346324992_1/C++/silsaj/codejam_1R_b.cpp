#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	int tmp;
	if (b > a) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0)
		return a;
	else {
		return gcd(b, a % b);
	}
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	freopen("A-small-practice.in", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int B;
		int N;
		cin >> B >> N;
		int M[1024];
		int maxB = 0;
		for (int i = 0; i < B; i++) {
			cin >> M[i];
			maxB = max(M[i], maxB);
		}

		int AtOnce = 0;
		int mod[1024] = { 0, };
		for (int i = 0; i < B; i++) {
			mod[i] = maxB % M[i];
			AtOnce += maxB / M[i];
		}

		int work[1024] = { 0, };
		int times = N / AtOnce;
		N -= AtOnce * times;

		for (int i = 0; i < B; i++) {
			work[i] = mod[i] * times;
			if (work[i] > M[i]) {
				N -= work[i] / M[i];
				work[i] %= M[i];
			}
		}
		if (N < 1)
			N %= AtOnce;
		if (N < 1)
			N += AtOnce;

		
		int res;
		while (1) {
			int mini = 12345678;
			int zero = -1;
			for (int j = 0; j < B; j++) {
				if (work[j] == 0) {
					zero = j;
					if (N == 1) {
						res = zero;
						goto end;
					}
					else {
						work[j] = M[j];
						N--;
					}
				}
				mini = min(work[j], mini);
			}
			
			
			for (int j = 0; j < B; j++) {
				work[j] -= mini;
			}
		}
		end:
		cout << "Case #" << tc << ": " << res + 1 << endl;
	}
}