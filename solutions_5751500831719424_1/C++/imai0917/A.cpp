#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define ABS(x) (((x)>0)?(x):-(x))

using namespace std;

FILE *fin, *fout;
void process(void)
{
	int N;
	char str[110][110];
	char rep[110];
	vector<int> F[110];
	fscanf(fin, "%d", &N);
	int i;
	for (i=0;i<N;++i){
		fscanf(fin, "%s", str[i]);
	}

	int m, j;
	char t=str[0][0];
	int f=0;
	int M=0;
	m = strlen(str[0]);
	for (j=0;j<m;++j){
		if (t == str[0][j]) ++f;
		else {
			rep[M] = t;
			F[M].push_back(f);
			++M;
			t = str[0][j];
			f = 1;
		}
	}
	rep[M] = t;
	F[M].push_back(f);
	++M;

	for (i=1;i<N;++i){
		m = strlen(str[i]);
		f = 0;
		int k = 0;
		for (j=0;j<m;++j){
			if (rep[k] != str[i][j]) {
				if (f == 0) {
					fprintf(fout, "Fegla Won\n");
					return;
				}
				F[k].push_back(f);
				++k;
				f = 0;
			}
			if (rep[k] == str[i][j]) ++f;
			else {
				fprintf(fout, "Fegla Won\n");
				return;
			}
		}
		F[k].push_back(f);
		if (k!=M-1){
			fprintf(fout, "Fegla Won\n");
			return;
		}
	}

	int dab=0;
	m = N >> 1;
	for (i=0;i<M;++i){
		sort(F[i].begin(), F[i].end());
		int tmp;
		if ((N & 1) == 0) tmp = (F[i][m-1] + F[i][m]) >> 1;
		else tmp = F[i][m];
		for (j=0;j<N;++j){
			dab = dab + ABS(F[i][j] - tmp);
		}
	}
	fprintf(fout, "%d\n", dab);
}
int main(void)
{
	int T, t;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	fscanf(fin, "%d", &T);
	for (t=1;t<=T;++t){
		fprintf(fout, "Case #%d: ", t);
		process();
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
