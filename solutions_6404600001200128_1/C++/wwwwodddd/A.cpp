#include <stdio.h>
#include <iostream>
using namespace std;
int t, n, a[1020];
int z1, z2;
int main() {
	scanf("%d", &t);;
	for (int tt = 1; tt <= t; tt++) {
		z1 = z2 = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int mr = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				z1 += a[i - 1] - a[i];
			}
			mr = min(mr, a[i] - a[i - 1]);
		}
		for (int i = 0; i < n - 1; i++) {
			z2 += min(a[i], -mr);
		}
		printf("Case #%d: %d %d\n", tt, z1, z2);
	}
	return 0;
}