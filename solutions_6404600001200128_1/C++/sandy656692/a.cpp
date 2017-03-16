#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int a[1010];

int main() {
	int T;
	scanf("%d", &T);
	for (int ttt = 1; ttt <= T; ++ttt) {
		int n;
		scanf("%d", &n);
		int A = 0, B = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			if (i == 0) continue;
			if (a[i] < a[i-1]) {
				A += a[i-1] - a[i];
				B = max(B, a[i-1] - a[i]);
			}
		}
		int C = 0;
		for (int i = 0; i + 1 < n; ++i) {
			C += min(B, a[i]);
		}
		printf("Case #%d: %d %d\n", ttt, A, C);
	}
	return 0;
}