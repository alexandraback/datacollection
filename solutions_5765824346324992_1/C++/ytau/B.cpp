#include <cstdio>
#include <algorithm>
using namespace std;

bool check(long long N, long long B, long long M[], long long mid) {
	long long ret = 0;
	for (long long i = 0; i < B; ++i) {
		ret += mid / M[i] + 1;
	}
	return ret >= N;
}

int main() {
	long long T, N, B, M[1005];
	scanf("%lld", &T);
	for (long long tc = 1; tc <= T; ++tc) {
		scanf("%lld%lld", &B, &N);
		for (long long i = 0; i < B; ++i) {
			scanf("%lld", &M[i]);
		}
		long long mi = 0, mid, ma = 0;
		for (long long i = 0; i < B; ++i) {
			ma = max(ma, (long long)M[i]);
		}
		ma++;
		ma *= N;
		while (mi < ma) {
			mid = (mi + ma) / 2;
			if (check(N, B, M, mid)) {
				ma = mid;
			}
			else mi = mid + 1;
		}
		long long n = N, q[1005], qw = 0;
		for (long long i = 0; i < B; ++i) {
			n -= mi / M[i] + 1;
			if (mi % M[i] == 0) {
				n++;
				q[qw++] = i;
			}
		}
		//prlong longf("%lld %lld %lld\n", mi, n, qw);
		printf("Case #%lld: %lld\n", tc, q[n - 1] + 1);
	}
	return 0;
}