#include <stdio.h>
#include <algorithm>

#define N 1010

using namespace std;

int arr[N];
int n;

int main() {
	freopen("Alarge.in", "r", stdin);
	freopen("Alarge.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int C = 1;C <= t;C++) {
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) {
			scanf("%d", &arr[i]);
		}
		int ans1 = 0, ans2 = 0;
		double mx = 0;
		for(int i = 2;i <= n;i++) {
			ans1 += max(0, arr[i-1] - arr[i]);
			mx = max(mx, (double) arr[i-1] - arr[i]);
		}
		mx /= 10;
		for(int i = 1;i < n;i++) {
			ans2 += min(arr[i], (int) (10 * mx));
		}
		printf("Case #%d: %d %d\n", C, ans1, ans2);
	}
	return 0;
}

