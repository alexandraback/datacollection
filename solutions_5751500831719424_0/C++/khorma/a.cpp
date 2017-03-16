//In the name of God
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
const int N = 100 + 10, oo = 1e9 + 9;

int n, m, ans, l[N];
string s[N], t[N];
vector<int> a[N];

int mn(vector<int> &a) {
	for (int i = 1; i <= n; i++)
		l[i] = l[i - 1] + a[i - 1];
	int ans = oo;
	for (int i = 1; i <= n; i++)
		ans = min(ans, (a[i - 1] * i - l[i]) + ((l[n] - l[i]) - a[i - 1] * (n - i)));
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	for (int tes = 1; tes <= test; tes++) {
		cout << "Case #" << tes << ": ";
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> s[i], t[i] = s[i];
		for (int i = 0; i < n; i++)
			t[i].resize(unique(t[i].begin(), t[i].end()) - t[i].begin());
		m = t[0].size();
		if (count(t, t + n, t[0]) != n) {
			cout << "Fegla Won\n";
			continue;
		}
		for (int i = 0; i < N; i++)
			a[i].clear();
		for (int i = 0; i < n; i++) {
			vector<int> v(1, -1);
			for (int j = 0; j < s[i].size(); j++)
				if (j == s[i].size() - 1 || s[i][j] != s[i][j + 1]) {
					a[v.size()].push_back(j - v.back());
					v.push_back(j);
				}
		}
		ans = 0;
		for (int i = 1; i <= m; i++) {
			sort(a[i].begin(), a[i].end());
			ans += mn(a[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
