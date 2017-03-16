#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 110;
const int INF = 1000000000;

int n;
char s[MAXN][MAXN];
vector< pair<char, int> > mask[MAXN];

vector < pair<char, int> > get_mask(string str) {
	vector < pair<char, int> > result;

	str += '#';
	int cnt = 1;
	for (int i = 1; i < str.size(); ++i) {
		if (str[i] != str[i - 1]) {
			result.push_back( make_pair(str[i - 1], cnt) );
			cnt = 1;
		}
		else {
			cnt++;
		}
	}

	return result;
}

int count_best(vector<int> t) {
	int result = INF;
	for (int i = 0; i < t.size(); ++i) {
		int cur = 0;
		for (int j = 0; j < t.size(); ++j)
			cur += abs(t[i] - t[j]);
		result = min(result, cur);
	}
	return result;
}

void solve(int test_id) {
	cout << "Case #" << test_id << ": ";
	memset(s, 0, sizeof(s));

	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		gets(s[i]);
	}

	for (int i = 0; i < n; ++i) {
		mask[i].clear();
		mask[i] = get_mask(string(s[i]));
	}

	for (int i = 1; i < n; ++i) {
		if (mask[0].size() != mask[i].size()) {
			cout << "Fegla Won" << endl;
			return;
		}
		for (int j = 0; j < mask[i].size(); ++j)
			if (mask[0][j].first != mask[i][j].first) {
				cout << "Fegla Won" << endl;
				return;
			}
	}

	int result = 0;

	vector<int> t(n);
	for (int j = 0; j < mask[0].size(); ++j) {
		for (int i = 0; i < n; ++i) {
			t[i] = mask[i][j].second;
		}
		result += count_best(t);
	}

	cout << result << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int test_id = 1; test_id <= t; ++test_id)
		solve(test_id);
	return 0;
}
