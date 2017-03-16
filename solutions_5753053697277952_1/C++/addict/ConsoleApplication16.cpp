#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solvation(FILE* f1, FILE* f2, int inum) {
	int ans = 0, n, i;
	int a[26];
	int max1 = 0, max2 = 0;
	int ind1 = -1, ind2 = -1;
	fscanf_s(f1, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf_s(f1, "%d", &a[i]);
		if (a[i] > max1) {
			if (max1 > 0) {
				max2 = max1;
				ind2 = ind1;
			}
			max1 = a[i];
			ind1 = i;
		}
		else if (a[i] > max2) {
			max2 = a[i];
			ind2 = i;
		}
	}
	while (a[ind1] > a[ind2]) {
		fprintf_s(f2, " %c", 65 + ind1);
		a[ind1]--;
	}
	for (i = 0; i < n; i++){
		if (i == ind1 || i == ind2) {
			continue;
		}
		for (int j = 0; j < a[i]; j++) {
			fprintf_s(f2, " %c", 65 + i);
		}
	}
	for (i = 0; i < a[ind1]; i++){
		fprintf_s(f2, " %c%c", 65 + ind1, 65 + ind2);
	}
	return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int tnum;
	int ans = 0;
	FILE* f1;
	FILE* f2;
	fopen_s(&f1, "in.txt", "r");
	fopen_s(&f2, "out.txt", "w");
	fscanf_s(f1, "%d", &tnum);
	for (int inum = 0; inum < tnum; inum++) {
		fprintf_s(f2, "Case #%d:", inum + 1);
		ans = solvation(f1, f2, inum);
		fprintf_s(f2, "\n");
	}
	fclose(f1);
	fclose(f2);
	return 0;
}