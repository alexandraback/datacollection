#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

std::string convert_to_minimal(const std::string &input, std::vector<std::vector<int> > &counts) {
	std::string unique;

	int size = input.size();
	int unique_s = 0;
	int count = 1;
	char last = input[0];
	unique += last;
	for (int i = 1; i < size; ++i) {
		if (input[i] == last)
			++count;
		else {
			int new_last = unique_s + 1;
			if (counts.size() < new_last)
				counts.resize(new_last);
			counts[unique_s++].push_back(count);
			count = 1;
			last = input[i];
			unique += last;
		}
	}
	int new_last = unique_s + 1;
	if (counts.size() < new_last)
		counts.resize(new_last);
	counts[unique_s].push_back(count);

	return unique;
}

int abs(int x) {
	return (x > 0) ? x : -x;
}

int sum_dist(std::vector<int> &pos) {
	std::sort(pos.begin(), pos.end());
	int loc = pos[pos.size() / 2];
	int ret = 0;
	for (int i = 0; i < pos.size(); ++i)
		ret += abs(pos[i] - loc);
	return ret;
}

void solve(int case_num) {
	std::string input;
	std::string minimal;
	std::vector<std::vector<int> > counts;

	std::cout << "Case #" << case_num << ": ";
	int n;
	std::cin >> n;
	std::cin >> input;
	minimal = convert_to_minimal(input, counts);
	for (int i = 1; i < n; ++i) {
		std::cin >> input;
		if (minimal != convert_to_minimal(input, counts)) {
			std::cout << "Fegla Won\n";
			return;
		}
	}

	int unique_size = minimal.size();
	int ret = 0;
	for (int i = 0; i < unique_size; ++i)
		ret += sum_dist(counts[i]);
	std::cout << ret << '\n';
}

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		solve(i + 1);
	}
}
