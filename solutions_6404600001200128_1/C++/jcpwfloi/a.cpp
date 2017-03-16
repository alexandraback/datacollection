#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int const N = 2000;

int n, T;
int a[N];

inline void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	int temp1 = 0;
	for (int i = 1; i < n; ++ i)
		if (a[i] > a[i + 1])
			temp1 += a[i] - a[i + 1];
	printf("%d ", temp1);
	int delta = 0;
	for (int i = 1; i < n; ++ i)
		if (a[i] > a[i + 1])
			delta = max(delta, a[i] - a[i + 1]);
	int temp2 = 0;
	for (int i = 1; i < n; ++ i) temp2 += min(delta, a[i]);
	printf("%d\n", temp2);
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t) {
		printf("Case #%d: ", t);
		solve();
	}
    return 0;
}
