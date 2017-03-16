#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define MAXN 1010

typedef long long ll;

int B, M[MAXN];
ll n;

ll check(ll key) {
	ll res = 0;
	for (int i = 1; i <= B; ++i) {
		res += (key + M[i] - 1) / M[i];
	}
	return res;
}

int getAns(ll key) {
	ll num = n - check(key);
	for(int i = 1; i <= B; ++i) {
		if (key % M[i] == 0) {
			num -= 1;
			if (num == 0) {
				return i;
			}
		}
	}
}

int main() {
	int ncas, cnt = 0;
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B1.out", "w", stdout);
	scanf("%d", &ncas);
	while (ncas--) {
		scanf("%d %lld", &B, &n);
		for (int i = 1; i <= B; ++i) {
			scanf("%d", M + i);
		}
		ll l = 0, r = n * 100000;
		while (l < r) {
			ll mid = (l + r + 1) / 2;
			ll sum = check(mid);
			if (sum < n) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		printf("Case #%d: %d\n", ++cnt, getAns(l));
	}
	return 0;
}