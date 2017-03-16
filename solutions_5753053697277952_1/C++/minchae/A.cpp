#include<stdio.h>
#include<string.h>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int A()
{
	int N,i,j,D[30],sum =0,max_i;
	fscanf(in,"%d", &N);

	for (i = 0; i < N; i++) {
		fscanf(in,"%d", &D[i]);
		sum += D[i];
	}

	while (sum!=0) {
		char Ans[3] = { 0, }, temp=0;
		max_i = 0;

		for (i = 1; i < N; i++) {
			if (D[i] > D[max_i]) max_i = i;
		}
		D[max_i]--; sum--;
		temp = 'A' + max_i;
		Ans[0] = temp;

		max_i = 0;
		for (i = 1; i < N; i++) {
			if (D[i] > D[max_i])max_i = i;
		}
		D[max_i]--; sum--;
		temp = 'A' + max_i;

		for (i = 0; i < N; i++) {
			if (((double)D[i] / sum)>0.5) break;
		}

		if (i == N) {
			Ans[1] = temp;
		}
		else {
			D[max_i]++; sum++;
		}

		fprintf(out,"%s ", Ans);

	}

	fprintf(out, "\n");
	return 0;
}

int main()
{
	int T,i=1; fscanf(in,"%d",&T);

	while (T--) {
		fprintf(out,"Case #%d: ",i++);
		A();
	}

	return 0;
}