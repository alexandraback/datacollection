#include <bits/stdc++.h>
using namespace std;
int N, TC, A[10005];
int main () {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &TC);
	for (int t = 1; t <= TC; ++t) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
		int ans1 = 0, ans2 = 0, ans3 = 0;
		for (int i = 1; i < N; ++i) {
			ans2 = max(ans2, A[i-1] - A[i]);
			if (A[i] < A[i-1]) ans1 += A[i-1] - A[i];
		}
		for (int i = 0; i < N-1; ++i) {
			ans3 += min(ans2, A[i]);
		}
		printf("Case #%d: %d %d\n", t, ans1, ans3);
	}
}
