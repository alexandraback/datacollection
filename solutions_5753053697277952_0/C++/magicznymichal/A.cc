#include <iostream>
#include <set>
#include <vector>

int main() {
	
	int t;
	std::cin >> t;

	for (int test = 0; test < t; ++test) {
		std::cout << "Case #" << (test + 1) << ": ";

		int N;
		std::cin >> N;

		std::vector<int> senators(N, 0);
		for (int i = 0; i < N; ++i)
			std::cin >> senators[i];

		int highest = 0;
		int counter = 1;
		for (int i = 1; i < N; ++i)
			if (senators[i] > senators[highest]) {
				highest = i;
				counter = 1;
			} else if (senators[i] == senators[highest])
				counter++;

		int almost;
		if (counter == 1) {
			almost = 0;
			if (highest == 0)
				almost = 1;
			for (int i = 1; i < N; ++i) {
				if (i == highest)
					continue;
				if (senators[i] > senators[almost])
					almost = i;
			}
		} else {
			almost = 0;
			if (highest == 0)
				almost = 1;
			for (int i = 0; i < N; ++i) {
				if (i == highest)
					continue;
				if (senators[i] == senators[highest]) {
					almost = i;
					break;
				}
			}
		}


		while (senators[highest] > senators[almost]) {
			senators[highest] -= 1;
			std::cout << (char)('A' + highest) << " ";
		}


		for (int i = 0; i < N; ++i) {
			if (i == highest || i == almost)
				continue;

			int ile = senators[i];
			while (ile > 0) {
				if (ile == 1) {
					ile -= 1;
					std::cout << (char)('A' + i) << " ";
				} else {
					ile -= 2;
					std::cout << (char)('A'+i) << (char)('A'+i) << " ";
				}
			}
		}

		for (int i = 0; i < senators[highest]; ++i) {
			std::cout << (char)('A' + highest) << (char)('A'+almost) << " ";
		}

		std::cout << std::endl;
	}

}