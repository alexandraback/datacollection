#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long lint;
int t, n, ans[3005];
lint x[3005], y[3005];

int cal(lint x0, lint x1, lint y0, lint y1) {
	int ans0 = 0, ans1 = 0;
	lint tx = x1 - x0, ty = y1 - y0;

	for(int i = 0; i < n; i++) {
		lint tx1 = x[i] - x0, ty1 = y[i] - y0;
		lint tmp = tx1 * ty - ty1 * tx;
		if(tmp < 0) ans0++;
		if(tmp > 0) ans1++;
	}
	return min(ans0, ans1);
}

int solve(int id) {
	int ret = 1000000;
	for(int i = 0; i < n; i++) {
		if(i == id) continue;
		int tmp = cal(x[i], x[id], y[i], y[id]);
		ret = min(tmp, ret);
	}
	return ret;	
}

int main() {
	scanf("%d", &t);
	for(int cas = 1; cas <= t; cas++) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%lld%lld", &x[i], &y[i]);
		}
		memset(ans, 0, sizeof(ans));
		if(n > 1) {
			for(int i = 0; i < n; i++) {
				ans[i] = solve(i);
			}
		}
		printf("Case #%d:\n", cas);
		for(int i = 0; i < n; i++) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
