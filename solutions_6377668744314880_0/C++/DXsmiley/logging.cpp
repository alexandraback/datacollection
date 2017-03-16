#include <iostream>

int T, N;

typedef long long int INT;

struct Point {
	INT x, y;
} points[5000];

int best[5000];

int main() {
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		// input
		std::cin >> N;
		for (int i = 0; i < N; ++i) {
			std::cin >> points[i].x >> points[i].y;
			best[i] = 1 << 30;
		}
		// processing
		if (N <= 3) {
			best[0] = best[1] = best[2] = 0;
		} else {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (i != j) {
						INT a = points[i].y - points[j].y;
						INT b = points[j].x - points[i].x;
						INT c = (points[i].x * points[j].y) - (points[i].y * points[j].x);
						int p_below = 0;
						int p_on = 0;
						int p_above = 0;
						for (int k = 0; k < N; ++k) {
							INT v = (a * points[k].x) + (b * points[k].y) + c;
							if (v == 0) ++p_on;
							if (v < 0) ++p_below;
							if (v > 0) ++p_above;
						}
						int score = N - p_on - std::max(p_below, p_above);
						best[i] = std::min(best[i], score);
						best[j] = std::min(best[j], score);
					}
				}
			}
		}
		// output
		std::cout << "Case #" << t + 1 << ":\n";
		for (int i = 0; i < N; ++i) {
			std::cout << best[i] << '\n';
		}
	}
}