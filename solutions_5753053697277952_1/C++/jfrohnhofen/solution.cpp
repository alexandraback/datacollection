#include <iostream>

#include <vector>

using namespace std;

void solve_testcase() {
	uint32_t N;
	cin >> N;

	vector<pair<char, uint32_t>> senators(N);

	for (uint32_t i = 0; i < N; ++i) {
		uint32_t S;
		cin >> S;
		senators.push_back(std::make_pair('A' + i, S));
	}

	std::sort(senators.begin(), senators.end(), [](pair<char, uint32_t> &a, pair<char, uint32_t> &b) {
		return a.second > b.second;
	});

	bool first = true;

	while(senators[0].second) {
		uint32_t max = senators[0].second;

		for (uint32_t i = 0; i < N; ++i) {
			if (senators[i].second < max) {
				break;
			}

			if (max == 1 && i == N-3) {
				cout << " " << senators[i].first << " " << senators[i+1].first << senators[i+2].first;
				return;
			}

			if (i == N-1 || senators[i+1].second < max) {
				cout << " " << senators[i].first;
				senators[i].second--;
			} else {
				cout << " " << senators[i].first << senators[i+1].first;
				senators[i].second--;
				i++;
				senators[i].second--;
			}
		}
	}
}

int main() {
	uint32_t T;
	cin >> T;
	
	for (auto t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ":";
		solve_testcase();
		cout << endl;
	}
}
