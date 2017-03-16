#include <bits/stdc++.h>
using namespace std;
int A[1005];
int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int N, ans1 = 0, ans2 = 0, rate = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &A[i]);
			if (i && A[i] < A[i - 1]) {
				int diff = A[i - 1] - A[i];
				ans1 += diff;
				rate = max(rate, diff);
			}
		}
		for (int i = 1; i < N; ++i) {
			// Eat till zero
			ans2 += min(A[i - 1], rate);
		}
		printf("Case #%d: %d %d\n", cn, ans1, ans2);
	}
}

