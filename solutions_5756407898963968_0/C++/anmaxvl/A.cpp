#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	int t;
	FILE* fin;;
	FILE* fout;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d", &t);

	for (int i=0; i<t; i++) {
		int row1, row2;
		int cards1[4][4];
		int cards2[4][4];

		fscanf(fin, "%d", &row1);
		for (int ii=0; ii<4; ii++) {
			for (int jj=0; jj<4; jj++) {
				fscanf(fin, "%d", &cards1[ii][jj]);
			}
		}

		fscanf(fin, "%d", &row2);
		for (int ii=0; ii<4; ii++) {
			for (int jj=0; jj<4; jj++) {
				fscanf(fin, "%d", &cards2[ii][jj]);
			}
		}

		int ans = 0;
		int col;
		for (int ii=0; ii<4; ii++) {
			for (int jj=0; jj<4; jj++) {
				if (cards1[row1-1][ii] == cards2[row2-1][jj]){
					ans++;
					col = ii;
				}
			}
		}

		if (ans == 0) {
			fprintf(fout, "Case #%d: Volunteer cheated!\n", i+1);
		}
		else if (ans == 1) {
			fprintf(fout, "Case #%d: %d\n", i+1, cards1[row1-1][col]);
		}
		else {
			fprintf(fout, "Case #%d: Bad magician!\n", i+1);
		}
	}

	return 0;
}
