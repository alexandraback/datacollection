#include <cstdio>
#include <cstdlib>
#include <cctype>

long long x[3000], y[3000];

int main() {
	FILE *fp = fopen("C-small-attempt1.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T, N;
	fscanf(fp, "%d", &T);
	for (int i = 0; i < T; ++i) {
		fscanf(fp, "%d", &N);
		for (int j = 0; j < N; ++j)
			fscanf(fp, "%lld %lld", &x[j], &y[j]);
		fprintf(fout, "Case #%d:\n", i + 1);
		for (int j = 0; j < N; ++j) {
			int min = N - 1;
			for (int k = 0; k < N; ++k) {
				if (j == k) continue;
				int left = 0, right = 0;
				for (int l = 0; l < N; ++l) {
					if (l == j || l == k) continue;
					long long t = (y[l] - y[j]) * (x[k] - x[j]) - (x[l] - x[j]) * (y[k] - y[j]);
					if (t > 0) ++left;
					if (t < 0) ++ right;
				}
				if (left < min) min = left;
				if (right < min) min = right;
			}
			fprintf(fout, "%d\n", min);
		}
	}
	fclose(fp);
	fclose(fout);
	return 0;
}