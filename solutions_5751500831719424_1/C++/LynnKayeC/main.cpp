/*
 * main.cpp
 *
 *  Created on: May 3, 2014
 *      Author: blding
 */


#include <cstdio>
#include <algorithm>

const int MAXN = 100;
const int MAXL = 100 + 10;

int caseNum;
int n;
char str[MAXN][MAXL];
char chrs[MAXN][MAXL];
char len[MAXN][MAXL];
char cnt[MAXN];

void read(FILE * fin)
{
	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; ++i) {
		fscanf(fin, "%s ", str[i]);
	}

	for (int i = 0; i < n; ++i) {
		cnt[i] = 0;
		int ptr = 0;
		while (str[i][ptr] != 0) {
			len[i][cnt[i]] = 0;
			chrs[i][cnt[i]] = str[i][ptr];
			char chr = str[i][ptr];
			while (str[i][ptr] != 0 && str[i][ptr] == chr) {
				++ptr;
				++len[i][cnt[i]];
			}
			++cnt[i];
		}
//		fprintf(stdout, "%s %d: ", str[i], cnt[i]);
//		for (int j = 0; j < cnt[i]; ++j) {
//			fprintf(stdout, "%c %d ", chrs[i][j], len[i][j]);
//		}
//		fprintf(stdout, "\n");
	}
}

bool isValid()
{
	for (int i = 1; i < n; ++i) {
		if (cnt[i] != cnt[0])
			return false;
		for (int j = 0; j < cnt[0]; ++j) {
			if (chrs[i][j] != chrs[0][j])
				return false;
		}
	}
	return true;
}

int getMin(int idx)
{
	int minL = 100000000;
	int maxL = 0;
	for (int i = 0; i < n; ++i) {
		if (len[i][idx] > maxL)
			maxL = len[i][idx];
		if (len[i][idx] < minL)
			minL = len[i][idx];
	}
	int min = 100000000;
	for (int i = minL; i <= maxL; ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += abs(len[j][idx] - i);
		}
		if (sum < min)
			min = sum;
	}
	//fprintf(stdout, "idx %d min %d max %d ");
	return min;
}

int calculate()
{
	int sum = 0;
	for (int j = 0; j < cnt[0]; ++j) {
		sum += getMin(j);
	}
	return sum;
}

void work(int caseId, FILE * fout)
{
	if (isValid()) {
		fprintf(fout, "Case #%d: %d\n", caseId, calculate());
	} else {
		fprintf(fout, "Case #%d: Fegla Won\n", caseId);
	}
}

int main()
{
	FILE * fin = fopen("../input", "r");
	FILE * fout = fopen("../output", "w");
	fscanf(fin, "%d", &caseNum);
	for (int caseId = 1; caseId <= caseNum; ++caseId) {
		read(fin);
		work(caseId, fout);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

