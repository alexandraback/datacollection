// ================================================================================================
//  Written by Luis Garcia, 2014
// ================================================================================================

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <iostream>

using namespace std;

#if defined _OJ_PROJECT
_BEGIN_PROBLEM(_GCJ14_03A, "GCJ14 03A")
#endif // _OJ_PROJECT

#define infinite_loop for (;;)

int main(
	) {
		int T, N;
		cin >> T;

		for (int _T = 1; _T <= T; ++_T) {
			cin >> N;

			set<string> keys;

			vector<string> v;
			for (int i = 0; i < N; ++i) {
				string s;
				cin >> s;
				v.push_back(s);

				keys.insert(string(s.begin(), unique(s.begin(), s.end())));
			}

			if (keys.size() > 1) {
				cout << "Case #" << _T << ": Fegla Won" << endl;
				continue;
			}

			vector<vector<int>> sections;
			for (int i = 0; i < N; ++i) {
				vector<int> parts;
				for (int j = 0; j < v[i].length();) {
					int k = j + 1;
					while (k < v[i].length() && v[i][j] == v[i][k]) ++k;
					parts.push_back(k - j);
					j = k;
				}
				sections.push_back(parts);
			}

			int numberParts = sections[0].size(), answer = 0;
			for (int j = 0; j < numberParts; ++j) {
				int maxLength = 0;
				for (int i = 0; i < N; ++i)
					maxLength = max(maxLength, sections[i][j]);

				int best = 0x7fffffff;
				for (int k = 0; k <= maxLength; ++k) {
					int op = 0;
					for (int i = 0; i < N; ++i) op += abs(sections[i][j] - k);
					best = min(best, op);
				}

				answer += best;
			}

			cout << "Case #" << _T << ": " << answer << endl;
		}

		return 0;
	}

#if defined _OJ_PROJECT
_END_PROBLEM
#endif // _OJ_PROJECT

// ================================================================================================
//  End of file.
// ================================================================================================
