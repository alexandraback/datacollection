#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
typedef long long ll;
int mm[1011], B;
ll calc(ll h) {
	ll ans = 0;
	for(int i = 0; i < B; ++i) {
		ans += (h + mm[i] - 1) / mm[i];
	}
	return ans;
}
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int _;
	scanf("%d", &_);
	for(int cs = 1; cs <= _; ++cs) {
		int N;
		scanf("%d%d", &B, &N);
		int mmax = 0;
		for(int i = 0; i < B; ++i) {
			scanf("%d", &mm[i]);
			mmax = max(mmax, mm[i]);
		}
		ll L = 0, R = 1LL * N * mmax;
		while(L < R) {
			ll mid = (L + R) / 2LL;
			if(calc(mid) <= N - 1) 
				L = mid + 1;
			else R = mid;
			//printf("%I64d %I64d\n", L, R);
		}
		--L;
		int res = N - calc(L);
		int ans = -1, cnt = 0;
		for(int i = 0; i < B; ++i) {
			int k = L / mm[i];
			if(1LL * k * mm[i] == L) {
				cnt++;
				if(cnt == res) {
					ans = i + 1;
					break;
				}
			} 
		}
		printf("Case #%d: %d\n", cs, ans);
	}
	return 0;
}