#include <bits/stdc++.h>
using namespace std;
int M[1005], B;
long long count(long long t) {
	if (t < 0) return 0;
	long long num = 0;
	for (int i = 0; i < B; ++i)
		num += (t / M[i]) + 1;
	return num;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int N;
		scanf("%d%d", &B, &N);
		for (int i = 0; i < B; ++i) scanf("%d", &M[i]);
		long long lo = 0, hi = 100000000000000LL;
		while (lo < hi) {
			long long m = (lo + hi) / 2;
			if (count(m) >= N) hi = m;
			else lo = m + 1;
		}
		int pos = N - count(lo - 1);
		for (int i = 0; i < B; ++i)
			if (lo % M[i] == 0) {
				--pos;
				if (!pos) {
					printf("Case #%d: %d\n", cn, i + 1);
					break;
				}
			}
	}
}

