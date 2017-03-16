#include <bits/stdc++.h>
using namespace std;

const int mn = 1010;

int a[mn];
int n;

int main() {
	int Tc;
	scanf("%d", &Tc);
	for (int Tn = 1; Tn <= Tc; ++Tn) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		int ans1 = 0;
		int minrate = -1;
		for (int i = 1; i < n; ++i)
			if (a[i] <= a[i - 1]) {
				ans1 += a[i - 1] - a[i];
				if (minrate == -1 || a[i - 1] - a[i] >= minrate)
					minrate = a[i - 1] - a[i];
			}
//		printf("minrate = %d\n", minrate);
		int ans2 = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (a[i] <= minrate)
				ans2 += a[i];
			else {
				ans2 += minrate;
			}
		}
		printf("Case #%d: ", Tn);
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
