#include <cstdio>
#include <vector>

using namespace std;

int R, C, N;

int test(vector<int> &house, int tens, int pos, int conflicts) {
	if (tens == 0) {
		return conflicts;
	} else {
		int best = -1;

		tens--;
		for (int i=pos ; i<N ; i++) {
			int c = conflicts;
			if (i-C>=0) c+=house[i-C];
			if ((i%C)-1>=0) c+=house[i-1];
			house[i] = 1;

			int x = test(house, tens, i+1, c);
			if (best < 0 || (x>=0 && x<best)) best = x;

			house[i] = 0;
		}

		return best;
	}
}

void run() {
	int t;
	scanf("%d %d %d", &R, &C, &t);

	N = R*C;
	vector<int> house(N, 0);

	int min = test(house, t, 0, 0);
	printf("%d\n", min);
}

int main() {
	int T;
	scanf("%d", &T);

	for (int TC=1 ; TC<=T ; TC++) {
		printf("Case #%d: ", TC);

		run();
	}
}