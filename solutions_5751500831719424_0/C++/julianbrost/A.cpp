#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		vector<string> words(N);
		for (string& w : words) {
			cin >> w;
#if DEBUG
			cerr << w << endl;
#endif
		}
		vector<char> chars;
		for (char c : words[0]) {
			if (chars.empty() || chars.back() != c) {
				chars.push_back(c);
			}
		}
		int C = chars.size();
		vector<vector<int>> counts(C, vector<int>(N));
		for (int w = 0; w < N; ++w) {
			int i = 0;
			for (char c : words[w]) {
				if (chars[i] != c) i++;
				if (i == C || chars[i] != c) goto impossible;
				counts[i][w]++;
			}
		}
		for (int i = 0; i < C; ++i) for (int j = 0; j < N; ++j) {
			if (!counts[i][j]) goto impossible;
		}
		{
			long long moves = 0;
			for (int i = 0; i < C; ++i) {
				auto &v = counts[i];
				//nth_element(v.begin(), v.begin()+(N/2), v.end());
				sort(v.begin(), v.end());
				int med = v[N/2];
				int add = 0;
				for (int x : v) add += abs(x - med);
				moves += add;
#if DEBUG
				cerr << chars[i];
				for (int j = 0; j < N; ++j) {
					cerr << '\t' << counts[i][j];
				}
				cerr << "\tmed: " << med << "\tadd: " << add << endl;
#endif
			}
			cout << "Case #" << t << ": " << moves << endl;
			continue;
		}
impossible:
		cout << "Case #" << t << ": " << "Fegla Won" << endl;
	}
}
