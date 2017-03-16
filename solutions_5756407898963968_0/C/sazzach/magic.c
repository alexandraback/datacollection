#include <stdio.h>

FILE *in, *out;
int grid[4][4], posibilities[4];

void parsegrid() {
	int i;
	for(i = 0; i < 4; i++)
		fscanf(in, "%i %i %i %i", &grid[i][0], &grid[i][1], &grid[i][2], &grid[i][3]);
}

int inpos(int n) {
	int i;
	for(i = 0; i < 4; i++)
		if(posibilities[i] == n)
			return 1;
	return 0;
}

void runtestcase(int caseno) {
	int i;
	int row, col;
	fscanf(in, "%i", &row);
	parsegrid();
	for(col = 0; col < 4; col++) {
		posibilities[col] = grid[row-1][col];
		printf("col1 possibility %i\n", posibilities[col]);
	}
	fscanf(in, "%i", &row);
	int index = -1;
	parsegrid();
	for(col = 0; col < 4; col++) {
		printf("col2 possibility %i\n", grid[row-1][col]);
		if(inpos(grid[row-1][col])) {
			printf("hello\n");
			if(index == -1) {
				index = col;
			}
			else {
				fprintf(out, "Case #%i: Bad magician!\n", caseno);
				return;
			}	
		}
	}
	if(index == -1) {
		fprintf(out, "Case #%i: Volunteer cheated!\n", caseno);
		return;
	}
	else {
		fprintf(out, "Case #%i: %i\n", caseno, posibilities[index]);
	}
}

void main(int argc, char *argv[]) {
	in = fopen(argv[1], "r");
	out = fopen("magic.out", "w");
	int n;
	fscanf(in, "%i", &n);
	int i;
	for(i = 0; i < n; i++) {
		runtestcase(i+1);
		printf("\n");
	}
}