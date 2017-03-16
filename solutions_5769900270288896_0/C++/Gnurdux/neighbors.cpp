#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int R, C, N;
		cin >> R >> C >> N;
		int best = 2 * R * C;
		for (int s = 0; s < (1<<(R*C)); s++) {
			bool placed[R][C];

			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					placed[i][j] = false;
				}
			}

			int number = 0;
			int cost = 0;
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (s & (1<<(C*i+j))) {
						placed[i][j] = true;
						number++;
						if (i > 0 && placed[i-1][j]) cost++;
						if (j > 0 && placed[i][j-1]) cost++;
					}
				}
			}
			if (number == N && cost < best) best = cost;
		}
		cout << "Case #" << t << ": " << best << '\n';
	}

	return 0;
}
