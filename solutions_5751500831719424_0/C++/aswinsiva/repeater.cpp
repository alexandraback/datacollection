// /Google-Code-Jam/2014/1/B/TEST/REPEATER

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main() {
	int n_tc = 0;
	cin >> n_tc;

	for (int tc = 1; tc <= n_tc; tc++) {
		int n_strings = 0;
		cin >> n_strings;

		vector<string> instrings(n_strings);
		for (int i = 0; i < n_strings; i++)
			cin >> instrings[i];

		bool isSegmented = true;
		string refstr;
		refstr += instrings[0][0];
		for (int i = 1; i < instrings[0].length(); i++)
			if (instrings[0][i] != instrings[0][i - 1])
				refstr += instrings[0][i];

		for (int j = 1; j < n_strings; j++) {
			string refstr2;
			refstr2 += instrings[j][0];
			for (int i = 1; i < instrings[j].length(); i++)
				if (instrings[j][i] != instrings[j][i - 1])
					refstr2 += instrings[j][i];

			if (refstr2.compare(refstr) != 0) {
				cout << "Case #" << tc << ": " << "Fegla Won" << endl;
				isSegmented = false;
				break;
			}
		}

		if (isSegmented) {
			vector<vector<int> > segmentsize(n_strings, vector<int>(refstr.length(), 0));
			for (int i = 0; i < n_strings; i++) {
				int seg_id = 0;
				segmentsize[i][0] = 1;
				for (int j = 1; j < instrings[i].length(); j++) {
					if (instrings[i][j] != instrings[i][j - 1])
						seg_id += 1;
					segmentsize[i][seg_id] += 1;
				}
			}

			int n_operations = 0;
			for (int i = 0; i < refstr.length(); i++) {
				vector<int> segsize(101, 0);
				int max_segsize = 0;
				for (int j = 0; j < n_strings; j++)
					segsize[segmentsize[j][i]] += 1, max_segsize = max(max_segsize, segmentsize[j][i]);
				int min_operations = INT_MAX;
				for (int final_size = 0; final_size <= max_segsize; final_size++) {
					int ops = 0;
					for (int size = 0; size <= max_segsize; size++)
						ops += segsize[size] * abs(size - final_size);
					min_operations = min(min_operations, ops);
				}
				n_operations += min_operations;
			}
			cout << "Case #" << tc << ": " << n_operations << endl;
		}
	}
	return 0;
}