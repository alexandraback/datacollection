#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <map>
#include <string>
#include <cassert>

using namespace std;
//#define int long long


signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		int n;
		cin >> n;
		set <pair <int, char> > sss;
		for (int i = 0; i < n; ++i) {
			int k;
			cin >> k;
			sss.insert(make_pair(k, 'A' + i));
		}
		vector <string> ans;
		while (sss.size()) {
			pair <int, char> last = *(--sss.end());
			sss.erase(--sss.end());
			pair <int, char> lastt = *(--sss.end());
			sss.erase(--sss.end());
			if (sss.size() != 0) {
				--last.first;
				ans.push_back(string("") + last.second);
				if (last.first) sss.insert(last);
				if (lastt.first) sss.insert(lastt);
			}
			else {
				ans.push_back(string("") + last.second + lastt.second);
				--last.first;
				--lastt.first;
				if (last.first) sss.insert(last);
				if (lastt.first) sss.insert(lastt);
			}
		}
		printf("Case #%d: ", tt);
		for (auto it : ans) {
			cout << it << ' ';
		}
		cout << endl;
	}
}
