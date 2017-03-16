#include <set>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int T, N;
std::string s[105];
std::string t[105];
std::vector<int> v[105];
int calc(std::string &r) {
	for (int i = 0; i < N; ++i) v[i].clear();
	for (int l = 0; l < N; ++l) {
		for (int i = 0, j = 0; i < (int)r.size(); ++i) {
			int cnts = 0;
			while (j < s[l].size() && s[l][j] == r[i]) j ++, cnts ++;
			v[l].push_back(cnts);
		}
	}
	int res = 0;
	for (int i = 0; i < (int)r.size(); ++i) {
		int min = 0x3fffffff;
		for (int j = 1; j <= 100; ++j) {
			int cnt = 0;
			for (int k = 0; k < N; ++k) {
				cnt += abs(j - v[k][i]);
			}
			min = std::min(min, cnt);
		}
		res += min;
	}
	return res;
}
void solve() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) std::cin >> s[i];
	std::set<std::string> h;
	for (int i = 0; i < N; ++i) {
		t[i] = s[i];
		std::string::iterator it = std::unique(t[i].begin(), t[i].end());
		t[i].resize(std::distance(t[i].begin(), it));
		h.insert(t[i]);
	}
	if (h.size() != 1) {
		std::cout << "Fegla Won" << std::endl;
		return;
	}
	std::string x = *h.begin();
	std::cout << calc(x) << std::endl;
}
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	std::cin >> T;
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d: ", _);
		solve();
	}
	return 0;
}