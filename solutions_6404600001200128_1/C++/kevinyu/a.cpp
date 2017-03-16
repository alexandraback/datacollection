#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int nTest,N,mushroom[1010];

int countWayOne() {
	int sum = 0;
	for (int i=0;i<N-1;i++) {
		if (mushroom[i+1]<mushroom[i]) sum += (mushroom[i]-mushroom[i+1]);
	}
	return sum;
}

int countWayTwo() {
	int max = -1;
	int sum = 0;
	for (int i=0;i<N-1;i++) {
		if (mushroom[i]-mushroom[i+1] > max) max = mushroom[i]-mushroom[i+1];
	}
	for (int i=0;i<N-1;i++) {
		sum += min(max,mushroom[i]);
	}
	return sum;
}

int main() {
	scanf("%d",&nTest);
	for (int tc = 1;tc<=nTest;tc++) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			scanf("%d",&(mushroom[i]));
		}
		printf("Case #%d: %d %d\n",tc,countWayOne(),countWayTwo());
	}
	return 0;
}