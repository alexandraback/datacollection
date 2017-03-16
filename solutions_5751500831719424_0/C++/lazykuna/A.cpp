#include <stdio.h>
#include <string.h>

char seq[150];
int seqcnt;
int arr[150][150];
int res[150];
int totres;
FILE *fp, *fout;

char str[150][150];
int ind;
int strcnt;

int abs(int x) {
	return (x<0)?(-x):(x);
}

bool process() {
	int i, j, k;
	// init
	for (i=0; i<150; i++)
		seq[i] = 0;
	for (i=0; i<150; i++)
		for (j=0; j<150; j++)
			arr[i][j] = 0;
	for (i=0; i<150; i++)
		res[i] = 0;
	//memset(seq, 0, sizeof(seq));

	//memset(arr, 0, sizeof(arr)*sizeof(in);
	//memset(validseq, 0, sizeof(validseq));
	totres = 0;
	seqcnt = 0;
	

	// create default sequence
	k=0;
	for (i=0; i<strlen(str[0]); i++) {
		if (seq[k] == 0) {
			seq[k] = str[0][i];
		} else if (seq[k] != str[0][i]) {
			seq[++k] = str[0][i];
		}
	}
	seqcnt = k+1;

	// store char cnt
	for (i=0; i<strcnt; i++) {
		k = 0;
		bool first = true;
		int l = 0;
		for (j=0; j<strlen(str[i]); j++) {
			if (seq[k] == str[i][j]) {
				arr[i][l]++;
			} else if (seq[k+1] == str[i][j] && !first) {
				arr[i][++l]++;
				k++;
			} else {
				// invalid sequence
				return false;
			}
			first = false;
		}
		if (k != seqcnt-1)
			return false;
	}
	
	// make strings to int arr
	for (int l =0; l<seqcnt; l++) {
		if (!arr[0][l]) break;

		res[l] = 0x7fffffff;
		for (i=0; i<=100; i++) {
				int sum = 0;
				for (k=0; k<strcnt; k++) {
					sum += abs(arr[k][l] - i);
				}
				if (sum < res[l])
					res[l] = sum;
				else
					break;
			}
	}

	for (i=0; i<seqcnt; i++)
		totres += res[i];

	return true;
}

int main() {
	fp = fopen("1.in", "r");
	fout = fopen("1.out", "w");
	
	int cnt;
	fscanf(fp, "%d", &cnt);
	for (ind=0; ind<cnt; ind++) {
		fscanf(fp, "%d", &strcnt);
		for (int i=0; i<strcnt; i++) {
			fscanf(fp, "%s", str[i]);
		}
		if (!process()) {
			fprintf(fout, "Case #%d: Fegla Won\n", ind+1);
		} else {
			fprintf(fout, "Case #%d: %d\n", ind+1, totres);
		}
	}

	fclose(fp);
	fclose(fout);

	return 0;
}
