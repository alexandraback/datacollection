#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll b, n, m[1000];

int solve() {
	if (n <= b) return n;
	ll lo = 0, hi = (*max_element(m, m+b)) * n;
	while (lo<hi) {
		ll mid = (lo+hi)/2;
		ll cc = 0;
		for (int i=0; i<b; ++i)
			cc += mid/m[i] + 1;
		if (cc < n) lo = mid + 1;
		else hi = mid;
	}
	ll cc = 0;
	for (int i=0; i<b; ++i)
		cc += (lo+m[i]-1)/m[i];
	for (int i=0; i<b; ++i) {
		if (lo%m[i]) continue;
		if (++cc == n) return i+1;
	}
	return -1;
}

int main() {
	freopen("r1a\\B-large.in", "r", stdin);
	freopen("r1a\\B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		scanf("%lld%lld", &b, &n);
		for (int i=0; i<b; ++i)
			scanf("%lld", m+i);
		printf("Case #%d: ", N);
		printf("%d\n", solve());
	}
}