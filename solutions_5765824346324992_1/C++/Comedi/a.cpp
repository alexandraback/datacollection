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
int t, n, B, ans;
lint m[1005];

bool check(int id) {
	lint l = 0, r = n;
	while(l < r - 1) {
		lint mid = l + r >> 1;
		lint t = mid * m[id];
		lint tans = 0;
		for(int i = 1; i <= id; i++) {
			tans += 1 + t / m[i];
		}
		for(int i = id + 1; i <= B; i++) {
			tans += 1 + (t - 1) / m[i];
		}
		if(tans == n) return true;
		if(tans < n) l = mid;
		else r = mid;
	}
	return false;
}

int main() {
	scanf("%d", &t);
	for(int cas = 1; cas <= t; cas++) {
		scanf("%d%d", &B, &n);
		for(int i = 1; i <= B; i++) {
			scanf("%lld", &m[i]);
		}

		if(n <= B) {
			ans = n;
		}
		else {
			for(int i = 1; i <= B; i++) {
				if(check(i)) {
					ans = i;
					break;
				}
			}
		}

		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
