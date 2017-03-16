#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int B, N, M[1020];

ll haircut(ll time) {
	ll ans = 0;

	int i;
	for (i = 0; i < B; i++) {
		ans += time/M[i] + 1;
	}
	return ans;
}

int main() {
	freopen("B.out", "w", stdout);

	int numCase, nowCase;
	scanf("%d", &numCase);
	for (nowCase = 1; nowCase <= numCase; nowCase++) {
		scanf("%d%d", &B, &N);

		int i;
		for (i = 0; i < B; i++)
			scanf("%d", &M[i]);

		//test time m
		ll p = 0, q = 1e14, m;
		while (p <= q) {
			m = (p+q) >> 1;
			if (haircut(m) >= N) {
				q = m-1;
			} else {
				p = m+1;
			}
		}

		//time q+1
		int remain = q == -1 ? N : N - haircut(q);
		for (i = 0; i < B; i++) {
			if ((q+1)%M[i] == 0) {
				if (!--remain) {
					printf("Case #%d: %d\n", nowCase, i+1);
					break;
				}
			}
		}
	}

	return 0;
}