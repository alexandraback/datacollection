#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100100];
struct Node {
	ll v; int idx;
	friend bool operator < (Node a, Node b) {
		if (a.v == b.v) return a.idx < b.idx;
		else return a.v > b.v;
	}
} p[1010];

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-ans.out", "w", stdout);
	int T, ca = 1;
	int b; ll n;	
	for (scanf("%d", &T); T--; ) {
		cin >> b >> n;
		for (int i = 0; i < b; ++i) cin >> a[i];
		if (n == 1) {
			printf("Case #%d: 1\n", ca++);
			continue;
		}
		ll low = 1, high = n * 100000, mid;
		ll ret = 0;
		while (low <= high) {
			mid = (low + high) >> 1;
			ll x = 0; int t = -1;
			for (int i = 0; i < b; ++i) {
				x += mid / a[i] + 1;
				if (mid % a[i] == 0) {
					if (t == -1) t = i + 1;
				}
			}
			if (x >= n) {
				ret = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		for (int i = 0; i < b; ++i) {
			p[i].v = ret % a[i];
			p[i].idx = i + 1;
			n -= ret / a[i];
		}
		sort(p, p + b);
		printf("Case #%d: %d\n", ca++, p[(n + b - 1) % b].idx);
	}
	return 0;
}

