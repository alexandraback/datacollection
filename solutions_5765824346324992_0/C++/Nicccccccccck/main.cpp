#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000+10;
int T, B;
long long N, M[maxn];
long long count(long long t) {
	long long res = 0;
	for (int i = 1; i <= B; i++) {
		res += t/M[i]+1;
	}
	return res;
}
int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	scanf("%d", &T);
	int cnt = 0;
	while(T--) {
		scanf("%d%lld", &B, &N);
		for (int i = 1; i <= B; i++)
			scanf("%lld", &M[i]);
		long long l = 0, r = (long long)1e15, x = l;
		while (l < r) {
			long long mid = (l+r)>>1;
			if (count(mid) >= N) {
				x = mid;
				r = mid;
			} else {
				l = mid+1;
			}
		}
		int ans = 0;
		long long n = N;
		if (x)
			n -= count(x-1);
		for (int i = 1; i <= B; i++) if (!(x%M[i])) {
			n--;
			ans = i;
			if (!n)
				break;
		}
		printf("case #%d: %d\n", ++cnt, ans);
	}
	return 0;
}