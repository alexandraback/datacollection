#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int solvation(FILE* f1, FILE* f2, int inum, int &ans1, int &ans2) {
	int n, m, mins = 0;
	int ma[1001];
	fscanf_s(f1, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf_s(f1, "%d", &m);
		ma[i] = m;
		if (i > 0 && ma[i] < ma[i - 1]) {
			ans1 += ma[i - 1] - ma[i];
			if (mins < ma[i - 1] - ma[i]) {
				mins = ma[i - 1] - ma[i];
			}
		}
	}
	for (int i = 0; i < n-1; i++) {
		if (ma[i] < mins) {
			ans2 += ma[i];
		}
		else {
			ans2 += mins;
		}
	}

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int tnum;
	int ans1, ans2;
	FILE* f1;
	FILE* f2;
	fopen_s(&f1, "in.txt", "r");
	fopen_s(&f2, "out.txt", "w");
	fscanf_s(f1, "%d", &tnum);
	for (int inum = 0; inum < tnum; inum++) {
		ans1 = 0;
		ans2 = 0;
		solvation(f1, f2, inum, ans1, ans2);
		fprintf_s(f2, "Case #%d: %d %d\n", inum + 1, ans1, ans2);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}

