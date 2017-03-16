// Haircut

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

void calc() {
	vector<int>barber;
	int bbCount;
	int lineLength;
	int i;
	int gcder;
	int timer = 1;

	scanf("%d %d", &bbCount, &lineLength);
	barber.resize(bbCount);
	for (i = 0; i < bbCount; i++) {
		scanf("%d", &barber[i]);
		if (i == 0) {
			gcder = barber[0];
		} else {
			gcder = gcd(gcder, barber[i]);
		}
		timer *= barber[i];
	}

	for (i = 1; i < bbCount; i++) {
		timer /= gcder;
	}

	lineLength %= (timer * bbCount);

	priority_queue<pair<int, int> > times;
	for (i = 0; i < bbCount; i++) {
		times.push(make_pair(0, -i));
	}

	int answer = 0;
	for (i = 0; i < lineLength; i++) {
		answer = -(times.top().second);
		// printf("> %d\n", answer);

		int curTime = times.top().first;
		times.pop();
		times.push(make_pair(curTime - barber[answer], -answer));
	}

	printf("%d\n", answer + 1);
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
