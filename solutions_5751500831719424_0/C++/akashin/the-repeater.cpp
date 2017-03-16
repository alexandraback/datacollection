#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

const char* inputFile = "A-small-attempt1.in";
const char* outputFile = "A-small-attempt1.out";

class Solver {
public:
	Solver() {
	}

	int getMovesNumber(int median, int position, const vector<vector< pair<int, char> > > &values) {
		int movesNumber = 0;
		for(size_t i = 0; i < values.size(); ++i) {
			movesNumber += abs(values[i][position].first - median);
		}
		return movesNumber;
	}

	string solveTest() {
		size_t N;
		cin >> N;

		vector< vector< pair<int, char> > > blocks(N);

		for (size_t i = 0; i < N; ++i) {
			string s;
			cin >> s;

			char previousChar = s[0];
			int seriesLength = 1;
			for (size_t j = 1; j <= s.length(); ++j) {
				if ((j == s.length()) || (s[j] != previousChar)) {
					blocks[i].push_back(make_pair(seriesLength, previousChar));
					if (j == s.length())
						break;
					seriesLength = 1;
					previousChar = s[j];
				} else {
					++seriesLength;
				}
			}
		}

		vector<int> sums(blocks[0].size(), 0);

		for (size_t i = 0; i < N; ++i) {
			if (blocks[i].size() != blocks[0].size()) {
				return "Fegla Won";
			}

			for (size_t j = 0; j < blocks[0].size(); ++j) {
				if (blocks[i][j].second != blocks[0][j].second) {
					return "Fegla Won";
				}
				sums[j] += blocks[i][j].first;
			}
		}

		int movesNumber = 0;
		for (size_t i = 0; i < blocks[0].size(); ++i) {
			int best = getMovesNumber(sums[i] / N, i, blocks);
			for (int k = -30; k <= 30; ++k) {
				best = min(best, getMovesNumber(sums[i] / N + k, i, blocks));
			}
			movesNumber += best;
		}

		return std::to_string(movesNumber);
	}
};

int main() {
	freopen(inputFile, "r", stdin);
	freopen(outputFile, "w", stdout);
	int T;
	scanf("%d", &T);

	for (int testNumber = 1; testNumber <= T; ++testNumber) {
		Solver solver;
		string verdict = solver.solveTest();
		printf("Case #%d: %s\n", testNumber, verdict.c_str());
	}
	return 0;
}
