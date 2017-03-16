#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input("problem.in");
	ofstream output("problem.out");

	int t;
	input >> t >> ws;

	for (int i = 1; i <= t; ++i) {
		int n;
		input >> n;
		vector<vector<int> > counts(n);
		vector<string> strs(n);

		bool success = true;
		for (int j = 0; j < n; ++j) {
			string s;
			input >> s;
			char cur = 0;
			for (int k = 0; k < s.length(); ++k) {
				char c = s[k];
				if (c != cur) {
					strs[j] += c;
					counts[j].push_back(1);
					cur = c;
				} else {
					++counts[j].back();
				}
			}
		}

		bool equal = true;
		for (string s : strs)
		if (s != strs[0]) {
			equal = false;
			break;
		}

		output << "Case #" << i << ": ";
		if (equal) {
			int score = 0;
			for (int j = 0; j < counts[0].size(); ++j) {
				vector<int> cs(n);
				for (int k = 0; k < n; ++k)
					cs[k] = counts[k][j];
				sort(cs.begin(), cs.end());

				int median = cs[cs.size() / 2];
				for (int k = 0; k < n; ++k)
					score += abs(cs[k] - median);
			}
			output << score;
		} else {
			output << "Fegla Won";
		}
		output << endl;
	}


	return 0;
}

