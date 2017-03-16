#include <stdio.h>

typedef unsigned long long ull;

int B, N, M[1000];

ull getHaircuts(ull time) {
	ull haircuts = 0;
	for (int i = 0; i < B; i++) {
		haircuts += time / M[i] + 1;
	}
	return haircuts;
}

int main() {
	int cases;
	scanf("%d", &cases);
	for (int cas = 1; cas <= cases; cas++) {
		scanf("%d%d", &B, &N);
		for (int i = 0; i < B; i++)
			scanf("%d", &M[i]);

		int sol;
		if (N <= B)
			sol = N;
		else {
			// binary search
			ull start = 0, end = ((ull) (M[0])) * N, haircuts_before_time = N,
					haircuts_at_time = N, time = end;
			while (start <= end) {
				ull mid = (start + end) / 2;
				ull haircuts = getHaircuts(mid);
				if (haircuts < N) {
					start = mid + 1;
					//haircuts_before_time = haircuts;
				} else {
					time = mid;
					end = mid - 1;
					haircuts_at_time = haircuts;
				}
			}

			for (int i = B - 1; i >= 0; i--)
				if (time % M[i] == 0) {
					haircuts_at_time--;
					if (haircuts_at_time < N) {
						sol = i + 1;
						break;
					}
				}
		}

		printf("Case #%d: %d\n", cas, sol);
	}
	return 0;
}
