#include <stdio.h>
#include <algorithm>
using namespace std;

int v[1010];
int N;

int first() {
	int tot = 0;
	for (int i = 0; i < N-1; i++) {
		if (v[i] > v[i+1]) {
			tot += v[i] - v[i+1];
		}
	}
	return tot;
}

int second() {
	for (int i = 0; i <= 10000; i++) {
		int tot = 0;
		bool eat = true;
		for (int j = 0; j < N-1; j++) {
			if (v[j] > v[j+1] && v[j] - v[j+1] > i) {
				eat = false;
				break;
			}
			tot += min(v[j], i);
		}
		if (eat) return tot;
	}
	return 0;
}

int main() {
	int T, _42=1;
	scanf(" %d", &T);
	while (T--) {
		scanf(" %d ", &N);
		for (int i = 0; i < N; i++) {
			scanf(" %d ", &v[i]);
		}
		printf("Case #%d: %d %d\n", _42++, first(), second());
	}
	return 0;
}
