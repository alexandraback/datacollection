#include <stdio.h>
#include <map>

using namespace std;

char infile[] = "B-small-attempt1 (1).in";
char outfile[] = "out.txt";

int BM[2000];
double S[2000];

int main() {
	FILE* fin = fopen(infile, "rb");

	if(!fin) {
		printf("file not found\n");
		return 0;
	}

	FILE* fout = fopen(outfile, "wb");

	int T, B, N;
	fscanf(fin, "%d", &T);

	for(int i = 0; i < T; ++ i) {
		printf("i%d\n", i);
		map<double, int> q;
		fscanf(fin, "%d%d", &B, &N);

		double sum = 0;
		for(int j = 0; j < B; ++ j) {
			fscanf(fin, "%d", BM + j);
			sum += (S[j] = 1.0/BM[j]);
		}

		double time = (N - B - 1)/sum - 0.001;

		if(time < 0) {
			time = 0;
		}

		int pos = 0;
		int cus = 0;

		for(int j = 0; j < B; ++ j) {
			int n = time / BM[j] + 1;
			cus += n;
			q[ BM[j]*(n) + (j / 100000.0)] = j;

			if(cus == N) {
				pos = j + 1;
			}
		}

		
		while(pos == 0) {
			map<double, int>::iterator b = q.begin();
			double tm = b->first;
			int bm = b->second;
			printf("%d/%d\n", cus, N);
			++cus;
			if(cus == N) {
				pos = bm + 1;
				break;
			}

			q.erase(b);
			q[tm + BM[bm]] = bm;
		}

		fprintf(fout, "Case #%d: %d\n", i + 1, pos );
	}


	fcloseall();
	return 0;
}