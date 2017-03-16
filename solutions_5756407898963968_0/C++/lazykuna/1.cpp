#include <stdio.h>
#include <string.h>


int c=0;
int arr[2][4][4];
int chk[20];

void write(FILE *fout, int mode) {
	char msg[32];
	if (mode > 0) {
		sprintf(msg, "%d", mode);
	} else if (mode == 0) {
		strcpy(msg, "Bad magician!");
	} else {
		strcpy(msg, "Volunteer cheated!");
	}

	c++;
	fprintf(fout, "Case #%d: %s\n", c, msg);
}

void process(FILE *fp, FILE *fout, int cnt) {
	if (cnt <= 0)
		return;

	int r[2];
	
	int i;
	for (i=0; i<2; i++) {
		fscanf(fp, "%d", &r[i]);
		for (int j=0; j<4; j++) {
			for (int k=0; k<4; k++) {
				fscanf(fp, "%d", &arr[i][j][k]);
			}
		}
	}

	memset(chk, 0, sizeof(chk));
	for (i=0; i<4; i++)
		chk[ arr[0][r[0]-1][i] ] = 1; 
	
	int ans = 0;
	int anscnt = 0;
	for (i=0; i<4; i++) {
		if (chk[ arr[1][r[1]-1][i] ]) {
			ans = arr[1][r[1]-1][i];
			anscnt++;
		}
	}

	if (anscnt == 0) ans = -1;
	if (anscnt > 1) ans = 0;
	write(fout, ans);

	process(fp, fout, cnt-1);
}

int main() {
	int cnt;
	FILE *fp = fopen("1.input", "r");
	fscanf(fp, "%d", &cnt);
	
	FILE *fout = fopen("1.output", "w");

	process(fp, fout, cnt);

	return 0;
}

