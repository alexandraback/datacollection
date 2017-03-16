#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define CH(a) ((char)(a)+'A')

int N;
int TOT;
int P[26]; // A~Z

int main() {
	//FILE *fi = fopen("sample.in", "r");
	FILE *fi = fopen("A-large.in", "r");
	//FILE *fi = fopen("A-small-attempt0.in", "r");
	FILE *fo = fopen("output.txt", "w");
	int T;

	fscanf(fi, "%d", &T);
	for (int t = 1; t <= T; t++) {
		fscanf(fi, "%d", &N);
		int tmpN = N;
		TOT = 0;
		for (int n = 0; n < N; n++) {
			fscanf(fi, "%d", &P[n]);
			TOT += P[n];
		}
		fprintf(fo, "Case #%d:", t);
		while (TOT > 2 && tmpN > 2) {
			int max_party(-1), max_count(0);
			for (int i = 0; i < N; i++) {
				if (max_count < P[i]) {
					max_count = P[i];
					max_party = i;
				}
			}
			fprintf(fo, " %c", CH(max_party));
			TOT--;
			P[max_party]--;
			if (P[max_party] == 0) tmpN--;
		}
		bool balance(false);
		while (TOT > 0) {
			int i;
			int max_party(-1), max_count(0);
			for (i = 0; i < N; i++) {
				if (max_count < P[i]) {
					max_count = P[i];
					max_party = i;
				}
				else if (max_count != 0 && max_count == P[i]) {
					balance = true;
					break;
				}
			}
			if (balance) {
				fprintf(fo, " %c%c", CH(max_party), CH(i));
				TOT -= 2;
				P[i]--;
				P[max_party]--;
			}
			else {
				fprintf(fo, " %c", CH(max_party));
				TOT--;
				P[max_party]--;
			}
		}

		fprintf(fo, "\n");
	}

	fclose(fi);
	fclose(fo);
	return 0;
}
