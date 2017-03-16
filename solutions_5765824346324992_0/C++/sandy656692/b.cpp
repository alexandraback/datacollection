#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int a[1010];

struct rec {
	int pos;
	long long t, dur;
	bool operator < (const rec &r) const {
		return t > r.t || t == r.t && pos > r.pos;
	}
} tmp;

int main() {
	int T;
	scanf("%d", &T);
	for (int ttt = 1; ttt <= T; ++ttt) {
		int n, b;
		scanf("%d%d", &b, &n);
		for (int i = 0; i < b; ++i) scanf("%d", &a[i]);
		long long R = 100000;
		R = R * n;
		long long L = -1;
		while (R - L > 1) {
			long long mid = (L + R) / 2;
			long long can = 0;
			for (int i = 0; i < b; ++i)
				can += mid / a[i] + 1;
			if (can >= n) R = mid;
			else L = mid;
		}
		long long Lcan = 0;
		for (int i = 0; i < b; ++i) {
			if (L >= 0)
				Lcan += L / a[i] + 1;
		}
		n -= Lcan;
		for (int i = 0; i < b; ++i) {
			if (R % a[i] == 0) {
				--n;
			}
			if (n == 0) {
				printf("Case #%d: %d\n", ttt, i + 1);
				break;
			}
		}
		
	}
	return 0;
}