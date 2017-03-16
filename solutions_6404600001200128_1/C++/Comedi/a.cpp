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
int t, n, x[1005];

int main() {
	scanf("%d", &t);
	for(int cas = 1; cas <= t; cas++) {
		scanf("%d", &n);
		int ans0 = 0, ans1 = 0;
		int rate = 0;

		for(int i = 0; i < n; i++) {
			scanf("%d", &x[i]);
			if(i > 0 && x[i] <= x[i - 1]) {
				ans0 += x[i - 1] - x[i];
				rate = max(rate, x[i - 1] - x[i]);
			}
		}
		
		for(int i = 0; i < n - 1; i++) {
			ans1 += min(rate, x[i]);
		}
		
		printf("Case #%d: %d %d\n", cas, ans0, ans1);
	}
	return 0;
}
