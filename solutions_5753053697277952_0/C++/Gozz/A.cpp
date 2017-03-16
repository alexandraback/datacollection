#include <bits/stdc++.h>

using namespace std;

string dfs(vector<int>& P, int total) {
	if (total == 0) return string(" ");
	for (int p : P) {
		if (2 * p > total) return string("");
	}
	for (int i = 0; i < P.size(); ++i) {
		if (P[i] <= 0) continue;
		for (int j = i+1; j <= P.size(); ++j) {
			if (j < P.size() && P[j] <= 0) continue;
			--P[i];
			if (j < P.size()) --P[j];
			string res = dfs(P, total - (j < P.size() ? 2 : 1));
			if (!res.empty()) {
				if (j < P.size()) res.push_back('A' + (char) j);
				res.push_back('A' + (char) i);
				res.push_back(' ');
				return res;
			}
			++P[i];
			if (j < P.size()) ++P[j];
		}
	}
	return string("");
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		vector<int> P(N);
		int total = 0;
		for (int& p : P) {
			cin >> p;
			total += p;
		}
		string res = dfs(P, total);
		reverse(res.begin(), res.end());
		cout << "Case #" << t << ":" << res << endl;
	}
	return 0;
}