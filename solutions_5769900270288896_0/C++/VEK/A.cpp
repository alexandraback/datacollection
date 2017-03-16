#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
typedef long long unsigned lluint;

int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}

using namespace std;

unsigned int testNum, w, h, n, best;
bool grid[16][16];

unsigned getValue() {
	unsigned ret = 0;
	for (unsigned xx = 0; xx < w; xx++) {
		for (unsigned yy = 0; yy < h; yy++) {
			if (grid[xx][yy]) {
				if (xx+1 < w && grid[xx+1][yy]) ret++;
				if (yy+1 < h && grid[xx][yy+1]) ret++;
			}
		}
	}
	return ret;
}

int main(int argc, char **argv) {
	ifstream ifile("B-small-attempt0.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> testNum;
	for (unsigned i = 0; i < testNum; i++) {
		ifile >> w >> h >> n;
		lluint maxNum = 1 << (w*h);
		bool foundOne = false;
		for (lluint j = 0; j < maxNum; j++) {
			unsigned popCount = 0;
			lluint copyJ = j;
			for (unsigned xx = 0; xx < w; xx++) {
				for (unsigned yy = 0; yy < h; yy++) {
					popCount += copyJ&1;
					grid[xx][yy] = copyJ&1;
					copyJ >>= 1;
				}
			}
			if (popCount != n) continue;
			if (!foundOne) {
				foundOne = true;
				best = getValue();
			} else best = min(best, getValue());
		}
		printf("Case #%d: %d\n", i+1, best);
		fprintf(ofile, "Case #%d: %d\n", i+1, best);
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
