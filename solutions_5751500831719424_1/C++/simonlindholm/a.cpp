#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

pair<vector<char>, vector<int>> cons(const string& s) {
	vector<char> chs;
	vector<int> counts;
	char prev = 0;
	int count = 0;
	for (char c : s) {
		if (c != prev) {
			if (count)
				counts.push_back(count);
			count = 0;
			prev = c;
			chs.push_back(c);
		}
		++count;
	}
	counts.push_back(count);
	return make_pair(chs, counts);
}

void solve() {
	int N;
	cin >> N;
	vector<char> chars;
	vector<vector<int> > parts(N);
	bool fail = false;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		auto pa = cons(s);
		if (chars.empty()) {
			chars = pa.first;
		}
		else if (chars != pa.first) {
			fail = true;
		}
		parts[i] = pa.second;
	}
	if (fail) {
		cout << "Fegla Won" << endl;
		return;
	}
	int M = (int)parts.front().size();
	long long res = 0;
	for (int i = 0; i < M; ++i) {
		vector<int> v(N);
		for (int j = 0; j < N; ++j)
			v[j] = parts[j][i];
		auto mid = v.begin() + (N / 2);
		nth_element(v.begin(), mid, v.end());
		int x = *mid;
		for (int y : v)
			res += abs(x - y);
		
	}
	cout << res << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
