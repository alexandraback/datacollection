#include <iostream>
#include <vector>
#include <algorithm>

bool check(std::vector<int>& senators, int num) {
	int majority = num / 2 +1;
	for (auto element : senators) {
		if (element >= majority) {
			return false;
		}
	}
	return true;
}

int main () {

	int T;
	std::cin >> T;
	std::vector<int> senators; 
	for (int t = 1; t <= T; ++t) {
		int N;
		std::cin >> N;
		senators.clear();
		senators.resize(N);
		for (int n = 0; n < N; ++n) {
			std::cin >> senators[n];
		}
		int num = std::accumulate(senators.begin(),senators.end(),0);

		std::cout << "Case #" << t << ": ";
		while (num > 0) {
			auto first_pos = max_element(senators.begin(),senators.end()) - senators.begin();
			--senators[first_pos];
			--num;
			std::cout << (char) ('A' + first_pos);
			auto second_pos = max_element(senators.begin(),senators.end()) - senators.begin();
			--senators[second_pos];
			--num;
			if (!check(senators,num)) {
				++senators[second_pos];
				++num;
			} else {
				std::cout << (char) ('A' + second_pos);
			}
			std::cout << " ";
		}
		std::cout << std::endl;
		
	}
	return 0;
}