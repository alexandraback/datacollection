#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int solvation(FILE* f1, FILE* f2, int inum) {
	int n = 0;
	_int64 x[3001], y[3001];
	int ans[3001];
	fscanf_s(f1, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf_s(f1, "%I64d %I64d", &x[i], &y[i]);
		ans[i] = 5000;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int s1 = 0;
			int s2 = 0;
			__int64 s = 0;
			for (int k = 0; k < n; k++) {
				if (k == i || k == j) {
					continue;
				}
				s = (x[k] - x[i]) * (y[k] - y[j]) - (y[k] - y[i]) * (x[k] - x[j]);
				if (s > 0) {
					s1++;
				}
				if (s < 0) {
					s2++;
				}
			}
			if (s1 > s2) {
				s = s2;
			}
			else {
				s = s1;
			}
			if (ans[i] > s) {
				ans[i] = s;
			}
			if (ans[j] > s) {
				ans[j] = s;
			}
		}
	}
	fprintf_s(f2, "Case #%d:\n", inum + 1);
	if (n == 1) {
		fprintf_s(f2, "%d\n", 0);
	}
	else {
		for (int i = 0; i < n; i++) {
			fprintf_s(f2, "%d\n", ans[i]);
		}
	}
	return 0;
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
		ans = solvation(f1, f2, inum);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}

