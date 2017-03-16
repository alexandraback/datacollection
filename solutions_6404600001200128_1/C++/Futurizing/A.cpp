// Mushroom Monster

#include <cstdio>

void calc() {
	int mushroom[1000];
	int time;

	int i;
	int maxSlope = 0;

	scanf("%d", &time);
	for (i = 0; i < time; i++) {
		scanf("%d", &mushroom[i]);
		if (i > 0 && mushroom[i-1] - mushroom[i] > maxSlope) {
			maxSlope = mushroom[i-1] - mushroom[i];
		}
	}

	int ans1 = 0;
	for (i = 1; i < time; i++) {
		if (mushroom[i-1] > mushroom[i]) {
			ans1 += mushroom[i-1] - mushroom[i];
		}
	}

	int ans2 = 0;
	for (i = 0; i < time - 1; i++) {
		if (mushroom[i] > maxSlope) {
			ans2 += maxSlope;
		} else {
			ans2 += mushroom[i];
		}
	}

	printf("%d %d\n", ans1, ans2);
}

int main() {
	int testcase;
	int t;

	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		printf("Case #%d: ", t);
		calc();
	}

	return 0;	
}
