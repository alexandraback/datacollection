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
		for (int i = 0; i < B; i++) {
			cin >> M[i];
		}

		int clcm = 1;
		for (int i = 0; i < B; i++) {
			clcm = lcm(clcm, M[i]);
		}
		
		int commonEnd = 0;
		for (int i = 0; i < B; i++) {
			commonEnd += clcm / M[i];
		}

		N %= commonEnd;
		if (N == 0) {
			N = commonEnd;
		}

		int work[1024] = { 0, };
		
		int res;
		while (1) {
			int mini = 12345678;
			int zero;
			for (int j = 0; j < B; j++) {
				mini = min(work[j], mini);
				if (work[j] == 0) {
					zero = j;
					break;
				}
			}
			if (mini == 0) {
				if (N == 1) {
					res = zero;
					goto end;
				}
				else {
					work[zero] = M[zero];
					N--;
				}
			}
			else {
				for (int j = 0; j < B; j++) {
					work[j] -= mini;
				}
			}
		}
		end:
		cout << "Case #" << tc << ": " << res + 1 << endl;
	}
}