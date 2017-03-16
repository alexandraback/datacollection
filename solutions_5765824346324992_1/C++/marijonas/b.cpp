#include <bits/stdc++.h>

using namespace std;

int N, B;
int M[1000];

long long how_many(long long time) {
	long long ct = B;
	for (int i = 0; i < B; i++)
		ct += time / M[i];
	return ct;
}

int solve() {
	scanf("%d%d", &B, &N);
	for (int i = 0; i < B; i++) {
		scanf("%d", &M[i]);
	}
	long long low = -1, high = 1000000000000000LL;
	while (high - low > 1) {
		long long mid = (low + high) / 2;
		if (how_many(mid) >= N)
			high = mid;
		else
			low = mid;
	}
	//printf("%lld\n", high);
	long long ct = how_many(high);
	for (int i = B-1; i >= 0; i--) {
		if (high % M[i] == 0) {
			if (ct == N)
				return i + 1;
			else
				ct--;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: %d\n", i, solve());
	}
	return 0;
}
