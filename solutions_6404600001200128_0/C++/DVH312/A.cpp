#include <bits/stdc++.h>
using namespace std;
int nTest;
int n, a[1111];
int solve1(){
	int ans = 0;
	for (int i = 2; i <= n; i++){
		if (a[i - 1] - a[i] > 0) ans += a[i - 1] - a[i];
	}
	return ans;
}
int solve2(){
	int ans = 0;
	int rate = 0;
	for (int i = 2; i <= n; i++){
		rate = max(rate, a[i - 1] - a[i]);
	}

	for (int i = 2; i <= n; i++){
		ans += min(a[i - 1], rate);
	}
	return ans;
}
int main(){
	freopen("A.inp", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &nTest);
	for (int test = 1; test <= nTest; test++){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		printf("Case #%d: %d %d\n", test, solve1(), solve2());
	}
	return 0;
}