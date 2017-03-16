#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

int main() {
	int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
	    int N; cin >> N;
		
		vector<vector<char>> chars(N);
	    vector<vector<int>> amt(N);
		for (int i = 0; i < N; ++i) {
			string s; cin >> s;
			int actChar = s[0];
			int actAmt = 1;
			for (int j = 1; j < s.length(); ++j) {
				if (actChar == s[j]) {
					++actAmt;
				} else {
					chars[i].push_back(actChar);
					amt[i].push_back(actAmt);
					actChar = s[j];
					actAmt = 1;
				}
			}
			chars[i].push_back(actChar);
			amt[i].push_back(actAmt);
        }

		bool preCheck = true;
		int len = amt[0].size();
		for (int i = 1; i < N && preCheck; ++i) {
			if (amt[i].size() != len) {
				preCheck = false;
			}
		}

		if (preCheck) {
			for (int i = 0; i < len && preCheck; ++i) {
				int actChar = chars[0][i];
				for (int j = 1; j < N && preCheck; ++j) {
					if (chars[j][i] != actChar) {
						preCheck = false;
					}
				}
			}
		}

		cout << "Case #" << t << ": ";
		if (!preCheck) {
			cout << "Fegla Won";
		} else {
			double steps = 0;
			vector<int> amtV(N);
			for (int i = 0; i < len; ++i) {
				int sum = 0;
				for (int j = 0; j < N; ++j) {
					amtV[j] = amt[j][i];
					sum += amt[j][i];
				}
				sort (amtV.begin(), amtV.end());

				double median;
				if (N % 2 == 0) {
					median = (amtV[N / 2 - 1] + amtV[N / 2]) / 2;
				} else {
					median = amtV[N / 2];
				}

				for (int j = 0; j < N; ++j) {
					if (amtV[j] < median) {
						steps += median - amtV[j];
					} else {
						steps += amtV[j] - median;
					}
				}
				
			}
			cout << (int)steps;
		}
		cout << endl;
    }
}