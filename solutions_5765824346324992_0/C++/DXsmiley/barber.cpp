#include <bits/stdc++.h>

int T, B, N, M[1024];

int main() {
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cerr << t << '\n';
		std::cin >> B >> N;
		std::priority_queue<std::pair<int, int> > q; // {0 - time, 0 - barber}
		int lcm = 1;
		int jump = 0;
		for (int i = 0; i < B; ++i) {
			std::cin >> M[i];
			lcm *= M[i];
			q.push({0, 0 - i});
		}
		for (int i = 0; i < B; ++i) {
			jump += lcm / M[i];
		}
		while (N > jump) {
			N -= jump;
		}
		for (int i = 0; i < N - 1; ++i) {
			int b = 0 - q.top().second;
			int x = 0 - q.top().first;
			// std::cout << b << ' ' << x << '\n';
			q.pop();
			q.push({0 - x - M[b], 0 - b});
		}
		std::cout << "Case #" << t + 1 << ": " << 1 - q.top().second << '\n';
	}
}