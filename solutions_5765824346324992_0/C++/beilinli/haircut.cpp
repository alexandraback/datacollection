#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long

int main(void) {
	freopen(	"B-small-attempt0.in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T, N, B;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> B >> N;
		int M[B];
		for (int i = 0; i < B; i++) cin >> M[i];

		if (N <= B) {
			printf("Case #%d: %d\n", t, N);
			continue;
		}

		LL a = 0;
		LL b = 1LL << 60;

		bool found = false;
		while (a <= b) {
			LL m = a + (b - a)/2;
			//cout << "Debug: " << a << ' ' << b << ' ' << ' ' << m << '\n';

			LL cut = 0;
			bool tooMany = false;
			for (int i = 0; i < B; i++) {
				cut += (m + M[i] - 1)/M[i];
				if (cut >= N) {
					tooMany = true;
					break;
				}
			}

			if (tooMany) {
				b = m - 1;
				continue;
			}

			for (int i = 0; i < B; i++) {
				if (m % M[i] == 0) {
					cut++;
					if (cut == N) {
						found = true;
						printf("Case #%d: %d\n", t, i + 1);
					}
				}
			}

			if (found) break;
			a = m + 1;
		}
	}

	return 0;
}
