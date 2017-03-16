#include <cstdio>
#include <cstdlib>

int main() {
	FILE *fp = fopen("A-small-attempt1.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T, ans, r1, r2, num1[4][4], num2[4][4], hit[16];
	fscanf(fp, "%d", &T);
	for (int i = 0; i < T; ++i) {
		fscanf(fp, "%d", &r1);
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				fscanf(fp, "%d", &num1[j][k]);
		fscanf(fp, "%d", &r2);
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				fscanf(fp, "%d", &num2[j][k]);
		for (int j = 0; j < 16; ++j)
			hit[j] = 0;
		for (int j = 0; j < 4; ++j)
			hit[num1[r1 - 1][j] - 1] = 1;
		fprintf(fout, "Case #%d: ", i + 1);
		ans = 0;
		for (int j = 0; j < 4; ++j) {
			if (hit[num2[r2 - 1][j] - 1] == 0) continue;
			if (ans > 0) {
				fprintf(fout, "Bad magician!\n");
				ans = 99;
				break;
			}
			ans = num2[r2 - 1][j];
		}
		if (ans == 0) fprintf(fout, "Volunteer cheated!\n");
		else if (ans <= 16) fprintf(fout, "%d\n", ans);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}