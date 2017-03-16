#include <cstdio>

int main() {
	FILE * fin = fopen("B.in", "r"), * fout = fopen("B.out", "w");
	int t, T, B, N, M[1000], i, mincount;
	long long min, max, mid, count;
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d%d", &B, &N);
		for (i = 0; i < B; ++i) {
			fscanf(fin, "%d", M + i);
		}
		min = 0;
		mincount = 0;
		max = 100000000000000;
		while (min != max - 1) {
			mid = (max + min) / 2;
			count = 0;
			for (i = 0; i < B; ++i) {
				count += mid / M[i] + 1;
			}
			if (count < N) {
				min = mid;
				mincount = count;
			} else {
				max = mid;
			}
		}
		mincount = N - mincount;
		for (i = 0; i < B; ++i) {
			if (!(max % M[i])) {
				--mincount;
				if (!mincount) {
					break;
				}
			}
		}
		fprintf(fout, "Case #%d: %d\n", t, i + 1);
	}
	return 0;
}
