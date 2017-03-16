#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <cstdint>
#include <cassert>

struct Party {
	char name;
	int number;

	Party() {}
	Party(char n, int num) : name(n), number(num) {}
};

bool operator < (const Party &lhs, const Party &rhs) {
	return lhs.number < rhs.number;
}

struct CodeJam {
	void conquer(std::istream &cin, std::ostream &cout) {
		int N;
		cin >> N;
		std::vector<Party> parties(N);
		for (int j = 0; j < N; ++j) {
			parties[j].name = 'A' + j;
			cin >> parties[j].number;
		}
		std::sort(parties.begin(), parties.end());

		std::priority_queue<Party> pq;
		for (int j = 2; j < N; ++j) {
			pq.push(parties[j]);
		}

		for (int j = parties[1].number - parties[0].number; j; --j) {
			Party p = pq.top();
			cout << parties[1].name << p.name << ' ';
			pq.pop();
			--p.number;
			pq.push(p);			
		}

		while (!pq.empty()) {
			Party p = pq.top();
			cout << p.name << ' ';
			pq.pop();			
			if (--p.number) {
				pq.push(p);
			}
		}

		for (int j = parties[0].number; j; --j) {
			cout << parties[0].name << parties[1].name << ' ';
		}
	}
private:
};

int main(int argc, char **argv) {
	std::ifstream ifstream;
	std::ofstream ofstream;
	if (argc > 1) {
		ifstream.open(argv[1]);
		std::string out(argv[1]);
		out.append(".out");
		ofstream.open(out.c_str());
		if (argc > 2) {
			ofstream.open(argv[2]);
		}
	}

	std::istream &cin(argc > 1 ? ifstream : std::cin);
	std::ostream &cout(argc > 1 ? ofstream : std::cout);

	int T;
	cin >> T;

	std::string line;
	std::getline(cin, line);

	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		CodeJam jam;
		jam.conquer(cin, cout);
		cout << std::endl;
	}
}
