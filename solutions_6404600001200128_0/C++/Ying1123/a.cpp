#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[2000];

void work() {
	scanf("%d", &n);
	
	int ans1 = 0;
	int spd = 0;
	scanf("%d", &a[0]);
	for (int i = 1; i < n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] < a[i - 1]) {
			ans1 += a[i - 1] - a[i];
			spd = max(spd, a[i - 1] - a[i]);
		}
	}
	printf("%d ", ans1);
	
	int ans2 = 0;
	for (int i = 0; i < n - 1; ++i) {
		ans2 += min(spd, a[i]);
	}
	printf("%d\n", ans2);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
