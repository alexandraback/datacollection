#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
void E(){}template<class A,class...B>void E(A _,B...$){cerr<<' '<<_;E($...);}
#define E($...) E(#$,'=',$,'\n')

void process() {
	int n;
	cin >> n;
	vector<vector<int>> inp(n);
	vector<vector<char>> let(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (char c: s) {
			if (let[i].empty() || let[i].back() != c) {
				let[i].push_back(c);
				inp[i].push_back(1);
			} else {
				++inp[i].back();
			}
		}
	}

	for (int i = 1; i < n; ++i) if (let[i] != let[0]) {
		puts("Fegla Won");
		return;
	}

	int ans = 0;
	int s = inp[0].size();
	for (int i = 0; i < s; ++i) {
		int best = 1e9;
		for (int to = 0; to < n; ++to) {
			int cur = 0;
			for (int j = 0; j < n; ++j)
				cur += abs(inp[j][i] - inp[to][i]);
			best = min(best, cur);
		}
		ans += best;
	}

	printf("%d\n", ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	int tcases;
	cin >> tcases;
	for (int tcase = 1; tcase <= tcases; ++tcase) {
		printf("Case #%d: ", tcase);
		process();
	}
	return 0;
}
