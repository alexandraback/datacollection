#include <cstdio>
#include <cstdlib>
#include <cctype>

int data[1000];

int main() {
	FILE *fp = fopen("A-small-attempt0.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T, N, ans1, ans2, r2;
	fscanf(fp, "%d", &T);
	for (int i = 0; i < T; ++i) {
		fscanf(fp, "%d", &N);
		for (int j = 0; j < N; ++j)
			fscanf(fp, "%d", &data[j]);
		ans1 = 0;
		ans2 = 0;
		r2 = 0;
		for (int j = 1; j < N; ++j) {
			if (data[j] < data[j - 1]) ans1 += data[j - 1] - data[j];
			if (data[j - 1] - data[j] > r2) r2 = data[j - 1] - data[j];
		}
		for (int j = 0; j < N - 1; ++j) {
			if (data[j] >= r2) ans2 += r2;
			else ans2 += data[j];
		}
		fprintf(fout, "Case #%d: %d %d\n", i + 1, ans1, ans2);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}