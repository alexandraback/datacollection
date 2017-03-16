#include <stdio.h>
#include <iostream>

using namespace std;

int v[1000];

int main (void) {
	int t, c, n, i;
	scanf ("%d", &t);
	for (c = 1; c <= t; c++) {
		scanf ("%d", &n);
		for (i = 0; i < n; i++) {
			scanf ("%d", &v[i]);
		}
		long long ans1 = 0, ans2 = 0;
		int maxd = 0;
		for (i = 1; i < n; i++) {
			if (v[i] < v[i-1]) {
				ans1 += v[i-1]-v[i];
				maxd = max(maxd, v[i-1]-v[i]);
			}
		}
		for (i = 0; i < n-1; i++) {
			ans2 += min(maxd, v[i]);
		}
		printf ("Case #%d: %lld %lld\n", c, ans1, ans2);
	}
}
