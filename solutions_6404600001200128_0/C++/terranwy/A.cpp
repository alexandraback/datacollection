#include <cstdio>

int casei, cases, n;
int m[1010];

int main() {
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", m + i);
		
		int ans1 = 0, ans2 = 0;
		int maxi = 0;
		for (int i = 1; i < n; ++i) {
			int tmp = m[i - 1] - m[i];
			if (tmp > maxi) maxi = tmp;
			if (tmp > 0) ans1 += tmp;
		}
		

		for (int i = 1; i < n; ++i) {
			if (m[i - 1] <= maxi) ans2 += m[i - 1];
			else {
				ans2 += maxi;
			}
		}
		
		printf("Case #%d: %d %d\n", casei, ans1, ans2);
	}
	
	return 0;
}