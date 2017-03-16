#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	freopen(	"A-small-attempt0.in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T, N;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		int a[N], sum = 0;
		for (int i = 0; i < N; i++)
			cin >> a[i];

		for (int i = 0; i + 1 < N; i++) sum += max(0, a[i] - a[i + 1]);
		printf("Case #%d: %d ", t, sum);

		int maxd = 0;
		for (int i = 0; i + 1 < N; i++) maxd = max(maxd, a[i] - a[i + 1]);

		sum = 0;
		for (int i = 0; i + 1 < N; i++) {
			sum += min(a[i], maxd);
		}

		printf("%d\n", sum);
	}
	return 0;
}
