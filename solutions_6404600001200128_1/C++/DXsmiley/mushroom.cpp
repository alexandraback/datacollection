#include <bits/stdc++.h>

int T, N, a[1024];

int main() {
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cin >> N;
		int w1 = 0, w2 = 0, r = 0;
		for (int i = 0; i < N; ++i) {
			std::cin >> a[i];
		}
		for (int i = 1; i < N; ++i) {
			w1 += std::max(a[i - 1] - a[i], 0);
			r = std::max(r, a[i - 1] - a[i]);
		}
		for (int i = 1; i < N; ++i) {
			w2 += std::min(r, a[i - 1]);
		}
		std::cout << "Case #" << t + 1 << ": " << w1 << ' ' << w2 << '\n';
	}
}