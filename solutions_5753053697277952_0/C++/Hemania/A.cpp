
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <map>
#include <vector>

int64_t N, T;

int64_t max(std::map<int64_t, int64_t> &sen) {
	int64_t index = -1;
	int64_t max = 0;
	for (auto &party : sen) {
		if (party.second > max) {
			max = party.second;
			index = party.first;
		}
	}

	return index;
}

int main() {
	auto in = std::ifstream("input.in");
	auto out = std::ofstream("output.out");

	in >> N;

	for (auto case_i = 0; case_i < N; case_i++) {
		in >> T;

		auto senators = std::map<int64_t, int64_t>();
		auto num = 0;
		for (auto sen_i = 0; sen_i < T; sen_i++) {
			in >> senators[sen_i];
			num += senators[sen_i];
		}

		std::vector<std::string> orders;
		while (num > 0) {
			if (num > 3 || num == 2) {
				char buffer[3];

				buffer[2] = 0;

				auto index = max(senators);
				senators[index]--;
				num--;
				buffer[0] = index + 'A';

				index = max(senators);
				senators[index]--;
				num--;
				buffer[1] = index + 'A';

				orders.push_back(std::string(buffer));
			} else if (num == 3) {
				char buffer[2];

				buffer[1] = 0;

				auto index = max(senators);
				senators[index]--;
				num--;
				buffer[0] = index + 'A';

				orders.push_back(std::string(buffer));
			}
		}

		out << "Case #" << case_i + 1 << ":";

		for (auto &order : orders) {
			out << " ";
			out << order.c_str();
		}
		out << std::endl;
	}

}