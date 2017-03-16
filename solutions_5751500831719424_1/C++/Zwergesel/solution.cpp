#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int casenum=1; casenum<=t; casenum++) {
		int n;
		cin >> n;
		string s[n];
		size_t p[n], g[n];
		for (int i=0; i<n; i++) cin >> s[i];
		fill_n(p, n, 0);
		fill_n(g, n, 0);
		
		bool possible = true;
		int moves = 0;
		while (true) {
			int ends = 0;
			for (int i=0; i<n; i++) {
				if (g[i] >= s[i].length()) ends++;
			}
			if (ends == n) break;
			if (ends > 0) {
				possible = false;
				break;
			}
			
			char c = s[0][g[0]];
			vector<int> lns;
			for (int i=0; i<n; i++) {
				if (s[i][g[i]] != c) {
					possible = false;
					break;
				}
				while (p[i] < s[i].length() && s[i][p[i]] == c) p[i]++;
				lns.push_back(p[i] - g[i]);
				g[i] = p[i];
			}
			if (!possible) break;
			
			sort(lns.begin(), lns.end());
			
			int target = lns[n / 2];
			for (int i=0; i<n; i++) {
				moves += abs(target - lns[i]);
			}
		}
		
		// Print solution
		if (!possible) {
			cout << "Case #" << casenum << ": Fegla Won\n";
			continue;
		} else {
			cout << "Case #" << casenum << ": " << moves << "\n";
		}
	}
	return 0;
}