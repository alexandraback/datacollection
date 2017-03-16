#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <sstream>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<string> s(n), d(n);
		vector<vector<int> > v(n);
		bool win = true;
		for (int j = 0; j < n; ++j) {
			cin >> s[j];
			int prev = 0;
			for (int k = 0; k < s[j].length(); ++k) {
				if (k == 0 || s[j][k] != s[j][k - 1])
					d[j] += s[j][k];
				if (k != 0 && s[j][k] != s[j][k - 1]) {
					v[j].push_back(k - prev);
					prev = k;
				}
			}
			v[j].push_back(s[j].length() - prev);
			if (j > 0 && d[j] != d[j - 1]) {
				win = false;
			}
		}
		cout << "Case #" << i + 1 << ": ";
		if (!win)
			cout << "Fegla Won";
		else {
			int ans = 0;
			for (int j = 0; j < v[0].size(); ++j) {
				vector<int> t(n);
				for (int k = 0; k < n; ++k)
					t[k] = v[k][j];
				sort(t.begin(), t.end());
				int best = 0, sum = 0;
				for (int k = 0; k < n; ++k) {
					best += t[k] - t[0];
					sum += t[k];
				}
				int prev = 0;
				for (int k = 1; k < n; ++k)
					if (t[k] != t[k - 1]) {
						sum -= 2 * (k - prev) * t[prev];
						int cur = sum - (n - 2 * k) * t[k];
						best = min(best, cur);
						prev = k;
					}
				ans += best;
			}
			cout << ans;
		}
		cout << endl;
	}

	return 0;
}