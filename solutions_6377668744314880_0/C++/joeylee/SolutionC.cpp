#include <iostream>
#include <fstream>
using namespace std;

struct Point {
	__int64 x;
	__int64 y;
};

__int64 testBoundary(__int64 j, __int64 N, Point point[3000]) {
	if (N <= 3) {
		return 0;
	}
	__int64 smallest = INT_MAX;
	for (__int64 k = 0; k < N; k++) {
		if (k == j) {
			continue;
		}
		__int64 dir_x = point[k].x - point[j].x;
		__int64 dir_y = point[k].y - point[j].y;
		__int64 positive = 0;
		__int64 negative = 0;
		for (__int64 l = 0; l < N; l++) {
			if (l == j || l == k) {
				continue;
			}
			__int64 dir2_x = point[l].x - point[j].x;
			__int64 dir2_y = point[l].y - point[j].y;
			__int64 product = dir_x * dir2_y - dir2_x * dir_y;
			if (product > 0) {
				positive++;
			}
			if (product < 0) {
				negative++;
			}
		}
		if (positive < smallest) {
			smallest = positive;
		}
		if (negative < smallest) {
			smallest = negative;
		}
	}
	return smallest;
}

int main() {
	ifstream fin("E:\\C-small-attempt1.in");
	// ifstream fin("E:\\temp.txt");
	ofstream fout("E:\\C-small.out");
	__int64 T;
	fin >> T;
	for (__int64 i = 1; i <= T; i++) {
		__int64 N;
		__int64 X;
		__int64 Y;
		Point point[3000];
		fin >> N;
		for (__int64 j = 0; j < N; j++) {
			fin >> X;
			fin >> Y;
			point[j].x = X;
			point[j].y = Y;
		}
		fout << "Case #" << i << ":" << endl;
		for (__int64 j = 0; j < N; j++) {
			__int64 numCut = testBoundary(j, N, point);
			fout << numCut << endl;
		}

	}
	return 0;
}
