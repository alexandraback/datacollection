#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int const N = 1e4;

int B, n, T, ans;

int a[N];

inline bool check(long long x, int n) {
	long long temp = 0;
	for (int i = 1; i <= B; ++ i) {
		temp += x / a[i] + 1;
	}
	return temp > n - 1;
}

inline void work() {
	vector<int> vt;
	long long l = -1, r = 1ll * (int)1e5 * (int)2e9;
	while (l + 1 < r) {
		long long mid = (l + r) >> 1;
		if (check(mid, n)) r = mid; else l = mid;
	}
	long long backup = r, cnt = 0;
	for (int i = 1; i <= B; ++ i) {
		if (r % a[i] == 0) {
			vt.push_back(i);
		}
	}
	for (int i = 1; i < min(B, n); ++ i) {
		l = -1, r = 1ll * (int)1e5 * (int)2e9;
		while (l + 1 < r) {
			long long mid = (l + r) >> 1;
			if (check(mid, n - i)) r = mid; else l = mid;
		}
		if (r == backup) ++ cnt; else break;
	}
	ans = vt[cnt];
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t) {
		scanf("%d%d", &B, &n);
		for (int i = 1; i <= B; ++ i) {
			scanf("%d", &a[i]);
		}
		work();
		printf("Case #%d: %d\n", t, ans);
	}
    return 0;
}

