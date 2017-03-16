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

int main(void) {
	int T;
	cin >> T;
	int N, ar[10000];
	int first, diff, maxDiff, second;
	for (int t=1; t<=T; t++) {
		printf("Case #%d: ", t);
		cin >> N;
		for (int i=0; i<N; i++) cin >> ar[i];
		
		first = 0;
		maxDiff = 0;
		for (int i=1; i<N; i++) {
			if (ar[i] < ar[i-1]) {	//lost mushrooms, must have eaten
				diff = ar[i-1] - ar[i];
				first += diff;
				if (diff > maxDiff) maxDiff = diff;
			}
		}
		printf("%d ", first);
		
		second = 0;
		for (int i=0; i<N-1; i++) {
			if (ar[i] > maxDiff) second += maxDiff;	//ate at max rate, didn't finish all mushrooms
			else second += ar[i];	//ate all remaining
		}
		printf("%d", second);
		
		
		
		
	//	printf("%d", ans);
	//	printf("%s", str);
	//	printf("%s", str.c_str());
		printf("\n");
	}
	return 0;
}