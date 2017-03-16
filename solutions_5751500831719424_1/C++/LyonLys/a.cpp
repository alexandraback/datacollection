#include <bits/stdc++.h>
using namespace std;

typedef vector<string> VS;
typedef vector<int> VI;
VS record;

string convert(const string &a) {
	string temp;
	temp += a[0];
	for (int i = 1; i < a.length(); ++i) {
		if (a[i - 1] == a[i]) continue;
		temp += a[i];
	}
	return temp;
}

int proc(VI &a, int n) {
	sort(a.begin(), a.end());
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += abs(a[i] - a[n >> 1]);
	}
	return sum;
}

int solve(int n) {
	string abbr = convert(record[0]);
	for (int i = 0; i < n; ++i) {
		if (abbr != convert(record[i])) return -1;
	}
	VS temp = record;
	VI cnt(n);
	int sum = 0;
	for (int i = 0; i < abbr.length(); ++i) {
		for (int j = 0; j < n; ++j) {
			int c = 0;
			while (c < temp[j].length() && temp[j][c] == abbr[i]) ++c;
			cnt[j] = c;
			temp[j] = temp[j].substr(c, temp[j].length() - c);
		}
		sum += proc(cnt, n);
	}
	return sum;
}

int run() {
	int _, n;
	cin >> _;
	for (int cas = 1; cas <= _; ++cas) {
		cin >> n;
		record.resize(n);
		for (int i = 0; i < n; ++i) cin >> record[i];
		//for (int i = 0; i < n; ++i) cerr << abbr[i] << endl;
		cout << "Case #" << cas << ": ";
		int answer = solve(n);
		if (answer >= 0) cout << answer << endl;
		else cout << "Fegla Won" << endl;
	}
	return 0;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	ios::sync_with_stdio(0);
	return run();
}
