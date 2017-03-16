#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1010];

int main() {
	// your code goes here
	int T;
	scanf("%d", &T);
	for (int re = 1; re <= T; re++) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", a + i);
		}
		int ans1 = 0, ans2 = 0, gap = 0;
		for (int i = 1; i < N; i++) {
			int t = a[i-1] - a[i];
			if (t > 0) {
				ans1 += t;
				if (t > gap) gap = t;
			}
		}
		for (int i = 0; i < N - 1; i++) {
			ans2 += min(a[i], gap);
		}
		printf("Case #%d: %d %d\n", re, ans1, ans2);
	}
	return 0;
}