#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int C, R, T, N;

void buildGrid(int *pos, int **grid) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			grid[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		grid[pos[i] / C][pos[i] % C] = 1;
	}
}

int evaluateGrid(int **grid) {
	int res = 0;
	for (int i = 0; i < R - 1; i++) {
		for (int j = 0; j < C - 1; j++) {
			if (grid[i][j] == 1 && grid[i][j + 1] == 1) res++;
			if (grid[i][j] == 1 && grid[i + 1][j] == 1) res++;
		}
		if (grid[i][C - 1] == 1 && grid[i + 1][C - 1] == 1) res++;
	}
	for (int i = 0; i < C - 1; i++) {
		if (grid[R - 1][i] == 1 && grid[R - 1][i + 1] == 1) res++;
	}
	return res;
}

int setpos(int x, int y, int *pos, int **grid) { //last pos, num, max
	int min = N * 4;
	int tmp;
	if (y == N - 1) {
		for (int i = x + 1; i < R * C; i++) {
			pos[y] = i;
			buildGrid(pos, grid);
			tmp = evaluateGrid(grid);
			if (tmp < min) min = tmp;
		}
		return min;
	}
	else {
		for (int i = x + 1; i < R * C - (N - 1 - y); i++) {
			pos[y] = i;
			tmp = setpos(i, y + 1, pos, grid);
			if (tmp < min) min = tmp;
		}
		return min;
	}
}

int main(void) {
	FILE *in = fopen("input.in", "rt");
	FILE *out = fopen("output.out", "wt");
	fscanf(in, "%d", &T);
	for (int i = 0; i < T; i++) {
		fscanf(in, "%d", &R);
		fscanf(in, "%d", &C);
		fscanf(in, "%d", &N);
		int *pos = new int[N];
		int **grid = new int*[R];
		for (int j = 0; j < R; j++) {
			grid[j] = new int[C];
		}
		if (N != 0) fprintf(out, "Case #%d: %d", i + 1, setpos(-1, 0, pos, grid));
		else fprintf(out, "Case #%d: %d", i + 1, 0);
		if (i != T - 1) fprintf(out, "\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}