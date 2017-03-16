#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int gao(vector<vector<pair<char, int> > > &v) {
	for (int i = 1; i < v.size(); ++i) {
		if (v[i].size() != v[0].size()) {
			return -1;
		}
		for (int j = 0; j < v[0].size(); ++j) {
			if (v[i][j].first != v[0][j].first) return -1;
		}
	}

	int ret = 0;
	for (int j = 0; j < v[0].size(); ++j) {
		vector<int> count;
		for (int i = 0; i < v.size(); ++i) {
			count.push_back(v[i][j].second);
		}
		sort(count.begin(), count.end());
		int min_ans = 1000000;
		for (int mid = count[0]; mid <= count.back(); ++mid) {
			int ans = 0;
			for (int i = 0; i < v.size(); ++i) {
				ans += abs(v[i][j].second - mid);
			}
			min_ans = min(min_ans, ans);
		}
		ret += min_ans;
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	string s;
	int n;
	vector<vector<pair<char, int> > > v;
	for (int re = 1; re <= T; ++re) {
		cin >> n;
		v.resize(n);
		for (int i = 0; i < n; ++i) {
			v[i].clear();
			cin >> s;
			char cur_char = 0;
			int count = 0;
			for (int j = 0; j < s.length(); ++j) {
				if (s[j] != cur_char) {
					if (count > 0) {
						v[i].push_back(make_pair(cur_char, count));
					}
					count = 1;
					cur_char = s[j];
				} else {
					++count;
				}
			}
			if (count > 0) {
				v[i].push_back(make_pair(cur_char, count));
			}
		}

		int ans = gao(v);
		cout << "Case #" << re << ": ";
		if (ans == -1) {
			cout << "Fegla Won" << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}