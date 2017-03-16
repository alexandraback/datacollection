#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

double angle(int dx, int dy) {
	return atan2(dy,dx) * 180.0 / M_PI;
}


int main(void) {
	int T;
	cin >> T;
	int N;
	int x[3000], y[3000];
	int dx, dy;
	double ang[6000], endAng;
	int bestCount;
	for (int t=1; t<=T; t++) {
		printf("Case #%d:\n", t);
		cin >> N;
	//	printf("N %d\n", N);
		for (int i=0; i<N; i++) cin >> x[i] >> y[i];
		
		int k;
		for (int i=0; i<N; i++) {
			if (N <= 3) bestCount = 0;
			else {
				k = 0;
				for (int j=0; j<N; j++) if (i != j) {
					dx = x[j] - x[i];
					dy = y[j] - y[i];
					ang[k++] = angle(dx, dy);
				}
				sort(&ang[0], &ang[N-1]);
				for (int j=0; j<N-1; j++) ang[j+N-1] = ang[j] + 360.0;
			//	printf("point %d: %d %d\n", i, x[i], y[i]); for (int j=0; j<2*N-2; j++) printf(" %.1lf", ang[j]); printf("\n");
				bestCount = N;
				for (int j=0; j<N-1; j++) {
					endAng = ang[j] + 180.0;
					k = 0;
					while (ang[k+j+1] < endAng && k < bestCount) k++;
					if (k < bestCount) {
						bestCount = k;
					//	printf("bestCount %d at index %d, endAng %.1lf\n", bestCount, j, endAng);
					}
				}
			}
			printf("%d\n", bestCount);
		}
	}
	return 0;
}