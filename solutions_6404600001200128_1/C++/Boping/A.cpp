#include <cstdio>

int main() {
	FILE * fin = fopen("A.in", "r"), * fout = fopen("A.out", "w");
	int t, T, i, N, m[1000], x, y, r;
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d%d", &N, m);
		x = 0;
		r = 0;
		y = 0;
		for (i = 1; i < N; ++i) {
			fscanf(fin, "%d", m + i);
			if (m[i - 1] > m[i]) {
				x += m[i - 1] - m[i];
				if (r < m[i - 1] - m[i]) {
					r = m[i - 1] - m[i];
				}
			}
		}
		for (i = 0; i < N - 1; ++i) {
			if (m[i] < r) {
				y += m[i];
			} else {
				y += r;
			}
		}
		fprintf(fout, "Case #%d: %d %d\n", t, x, y);
	}
	return 0;
}
