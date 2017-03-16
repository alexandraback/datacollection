#include <bits/stdc++.h>

using namespace std;

#define fillchar(a, s) memset((a), (s), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define rep(it, v) for (auto it = (v).begin(); it != (v).end(); it++)

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1010;

int B;
ll N, R[MAXN];

ll get (ll g) {
	//how many barbers BEFORE this second
	ll res = 0;
	for (int i = 1; i <= B; i++) {
		res += (g + R[i] - 1) / R[i];
	}
	return res;
}

void go (int tt) {
	printf("Case #%d: ", tt);
	scanf("%d %lld", &B, &N);
	for (int i = 1; i <= B; i++) {
		scanf("%lld", &R[i]);
	}
	//binary search
	ll lo = 0, hi = 1ll << 60;
	while (hi - lo > 1) {
		ll mid = (lo + hi) / 2;
		if (get(mid) >= N) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	//hi = first one ok
	ll nu = N - get(hi - 1);
	//ok N - nu are going to serve this kid now
	for (int i = 1; i <= B; i++) {
		if ((hi + R[i] - 1) % R[i] == 0) {
			nu--;
			if (nu == 0) {
				printf("%d\n", i);
				return;
			}
		}
	}
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int tt;
	scanf("%d", &tt);
	for (int i = 1; i <= tt; i++) {
		go(i);
	}
}