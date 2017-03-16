#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int inf = ~0u>>1;
int T, B, ans, n;
int m[1001], minm;
bool check(ll x) {
	ll cnt = 0;
	for (int i = 1; i <= B; i++) cnt += x / m[i] + 1;
	return (cnt >= 1LL * n);
}
int main() {
	freopen("large.in", "r", stdin);
	freopen("large.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		ans = 0;
		scanf("%d%d", &B, &n);
		minm = inf;
		for (int j = 1; j <= B; j++) {
			scanf("%d", &m[j]);
			if (m[j] < minm) minm = m[j];
		}
		ll l = 0, r = 1LL * minm * n, mid, rec;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check(mid)) {
				rec = mid; 
				r = mid - 1;
			} else l = mid + 1;
		}
		ll cnt = 0, res;
		for (int j = 1; j <= B; j++) cnt += rec / m[j] + 1;
		res = cnt - n;
		for (int j = B; j >= 1; j--) {
			if (rec % m[j] == 0) {
				if (res == 0) {ans = j; break;}
				res--;
			}
		}
		printf("Case #%d: %d\n", i, ans);
	}
}
