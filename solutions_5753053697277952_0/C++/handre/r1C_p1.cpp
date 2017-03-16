#include <iostream>
#include <algorithm>
#include <cstdio>

int main(void) {
	int T, N;
	std::cin >> T;

	int cnt[3];

	for (int t = 0; t < T; t++) {
		std::cin >> N;

		cnt[0] = cnt[1] = cnt[2] = 0;
		for (int i = 0; i < N; i++) std::cin >> cnt[i];
		
		printf("Case #%i: ", t + 1);
		
		for (;;) {

			auto pickMax = [&]() {
				int maxIdx = -1;
				int maxVal = 0;
				for (int i = 0; i < N; i++) if (cnt[i] > maxVal) maxIdx = i, maxVal = cnt[i];
				return maxIdx;
			};

			int firstIdx = pickMax();
			if (firstIdx == -1) {
				printf("\n");
				break;
			}
			else cnt[firstIdx]--;

			printf("%c", 'A' + firstIdx);

			int secondIdx = pickMax();
			if (secondIdx == -1) {
				printf("\n");
				break;
			}
			else cnt[secondIdx]--;


			int totalVotes = 0;
			for (int i = 0; i < N; i++) totalVotes += cnt[i];
			for (int i = 0; i < N; i++) if (cnt[i] > totalVotes / 2) {
				cnt[secondIdx]++;
				secondIdx = -1;
			}
			if (secondIdx == -1) printf(" ");
			else printf("%c ", 'A' + secondIdx);
		}
	}
	return 0;
}