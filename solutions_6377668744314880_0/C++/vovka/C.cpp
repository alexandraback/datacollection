#include <stdio.h>

char infile[] = "C-small-attempt1 (1).in";
char outfile[] = "out.txt";

int x[5000];
int y[5000];

int res[5000];

struct line {
	long long A;
	long long B;
	long long C;

	int more;
	int less;
	line(long long x1, long long y1, long long x2, long long y2) {
		A = y1 - y2;
		B = x2 - x1;
		C = (y2 - y1)*x2 + (x1 - x2)*y2;

		more = 0;
		less = 0;
	}

	long long val(int x, int y) {
		return A*x + B*y + C;
	}

	void add(int x, int y) {
		long long v = val(x, y);
		if(v > 0) {
			more += 1;
		} else if(v < 0) {
			less += 1;
		}
	}

	int get() {
		return more < less ? more : less;
	}

};

int main() {
	FILE* fin = fopen(infile, "rb");

	if(!fin) {
		printf("file not found\n");
		return 0;
	}

	FILE* fout = fopen(outfile, "wb");


	int T, N;
	fscanf(fin, "%d", &T);

	for(int i = 0; i < T; ++ i) {
		fscanf(fin, "%d", &N);

		for(int j = 0; j < N; ++ j) {
			fscanf(fin, "%d%d", x + j, y + j);
			res[j] = N;
		}

		for(int j = 0; j < N; ++ j) {
			int m = N;
			for(int k = j + 1; k < N; ++ k) {
				line ln(x[j], y[j], x[k], y[k]);

				for(int l = 0; l < N; ++ l) {
					ln.add(x[l], y[l]);
				}
				int val = ln.get();

				if(val < res[j]) {
					res[j] = val;
				}

				if(val < res[k]) {
					res[k] = val;
				}
			}
		}

		fprintf(fout, "Case #%d: \n", i + 1 );

		if(N > 3) {
			for(int j = 0; j < N; ++ j) {
				fprintf(fout, "%d\n", res[j]);		
			}
		} else {
			for(int j = 0; j < N; ++ j) {
				fprintf(fout, "0\n", res[j]);		
			}
		}
	}


	fcloseall();
	return 0;
}