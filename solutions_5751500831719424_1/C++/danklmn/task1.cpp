#include <iostream>
#include <ostream>
#include <vector>
#include <string>
using namespace std;

#define ABS(x)	((x) < 0) ? -(x) : (x);

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; ++t) {
		int n; cin >> n;
		int res = 0;

		vector<string>	original_strings(n);
		for (int i = 0; i < n; ++i) {
			cin >> original_strings[i];
		}

		vector<string>	unique_strings(n);
		vector< vector<int> >	char_counts(n);		

		string	etalon;
		for (int i = 0; i < n; ++i) {
			string&			ors = original_strings[i];
			string&			us = unique_strings[i];
			vector<int>&	cc = char_counts[i];

			us.push_back(ors.front());
			cc.push_back(1);
			for (auto it = ors.begin() + 1; it != ors.end(); ++it) {
				if (*it == us.back()) {
					++cc.back();
				} else {
					us.push_back(*it);
					cc.push_back(1);
				}
			}

			if (!i) {
				etalon = us;
			} else if (us != etalon) {
				res = -1;
				break;
			}
		}
		if (res == -1) {
			cout << "Case #" << t << ": " << "Fegla Won" << endl;
			continue;
		}

		vector<int>	avg_counts(char_counts.front().size());
		for (auto it = char_counts.begin(); it != char_counts.end(); ++it) {
			for (int i = 0; i < avg_counts.size(); ++i) {
				avg_counts[i] += it->at(i);
			}
		}
		for (int i = 0; i < avg_counts.size(); ++i) {
			avg_counts[i] = (int)((double)avg_counts[i] / n + 0.5);
		}

		for (auto it = char_counts.begin(); it != char_counts.end(); ++it) {
			for (int i = 0; i < avg_counts.size(); ++i) {
				res += ABS(avg_counts[i] - it->at(i));
			}
		}

		cout << "Case #" << t << ": " << res << endl;
	}

	return 0;
}