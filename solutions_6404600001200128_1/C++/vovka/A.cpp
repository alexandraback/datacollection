#include <stdio.h>

char infile[] = "A-large (1).in";
char outfile[] = "out.txt";

int M[20000];

int main() {
	FILE* fin = fopen(infile, "rb");

	if(!fin) {
		printf("file not found\n");
		return 0;
	}

	FILE* fout = fopen(outfile, "wb");

	int T, SM;
	fscanf(fin, "%d", &T);

	for(int i = 0; i < T; ++ i) {
		int s1 = 0, s2 = 0;
		int prev = 0;
		int a = 0;
		int rate = 0;

		fscanf(fin, "%d", &a);

		for(int j = 0; j < a; ++ j) {
			fscanf(fin, "%d", M + j);

			if(M[j] < prev && j > 0) {
				s1 += prev - M[j];
			}

			if(j > 0 && prev - M[j] > rate) {
				rate = prev - M[j];
			}

			prev = M[j];
		}

		for(int j = 0; j < a - 1; ++ j) {
			s2 += (( M[j] > rate ) ? rate : M[j]);
		}

		fprintf(fout, "Case #%d: %d %d\n", i + 1, s1, s2 );
	}


	fcloseall();
	return 0;
}