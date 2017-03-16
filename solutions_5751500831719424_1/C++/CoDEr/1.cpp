#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//*
int list[120][120][2];
int len = 0;

void trans(char * str) {
	int strl = strlen(str);
	int counter = 0;
	int ptr = 1;
	int i = 0;

	list[len][ptr][0] = (int)(str[0] - 'a');
	list[len][ptr][1] = 0;
	counter = 1;
	for (i = 1; i < strl; i++) {
		if (str[i] != str[i - 1]) {
			list[len][ptr][1] = counter;

			ptr++;
			list[len][ptr][0] = (int)(str[i] - 'a');
			list[len][ptr][1] = 0;
			counter = 1;
		}
		else counter++;
	}

	list[len][ptr][1] = counter;
	list[len][0][1] = ptr;

	len++;
}

int valid(int s, int t) {
	if (list[s][0][1] != list[t][0][1]) return 0;

	for (int i = 1; i <= list[s][0][1]; i++) {
		if (list[s][i][0] != list[t][i][0]) return 0;
	}

	return 1;
}

int modify() {
	// Check possibility
	for (int i = 1; i < len; i++) {
		if (!valid(i - 1, i)) return -1;
	}

	// Calculate move
	int move = 0;
	int min = INT_MAX;
	for (int ptr = 1; ptr <= list[0][0][1]; ptr++) {
		min = INT_MAX;
		for (int i = 0; i < len; i++) {
			int counter = 0;
			for (int j = 0; j < len; j++) {
				if (i == j) continue;
				if (i > j && list[j][ptr][1] == list[i][ptr][1]) {
					counter = INT_MAX;
					break;
				}
				counter += abs(list[i][ptr][1] - list[j][ptr][1]);
			}
			if (counter < min) min = counter;
		}
		move += min;
	}

	return move;
}

int main(void) {
	FILE * fp = NULL;
	FILE * fout = NULL;
	int t = 0;
	int n = 0;
	int move = 0;
	char str[120];

	if (fopen_s(&fp, "A-large.in", "r") != NULL) return -1;
	if (fopen_s(&fout, "A-large.out", "w") != NULL) return -1;

	fscanf(fp, "%d", &t);
	for (int caseIndex = 1; caseIndex <= t; caseIndex++) {
		move = -1;
		len = 0;
		fscanf(fp, "%d", &n);
		for (int i = 0; i < n; i++) {
			fscanf(fp, "%s", str);
			trans(str);
		}

		move = modify();

		if (move == -1) fprintf(fout, "Case #%d: Fegla Won\n", caseIndex);
		else fprintf(fout, "Case #%d: %d\n", caseIndex, move);
		
	}

	fclose(fout);
	fclose(fp);

	return 0;
}
//*/