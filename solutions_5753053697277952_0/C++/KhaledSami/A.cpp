#include <iostream>
#include <set>
#include <cstdio>
#include <map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);
	int t, n;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cin >> n;
		vector<pair<int,char> > v(n);
		int count = 0;
		for (int i = 0; i < n; i++) {
			cin>> v[i].first;
			v[i].second = (char)(65 + i);
			count += v[i].first;
		}
		cout << "Case #" << tt <<": ";
		while (count) {
			sort(v.rbegin(), v.rend());
			string cur = "";
			cur += v[0].second;
			v[0].first--;
			count--;
			if (v.size() == 2 ||(v.size() > 2 && v[1].first > v[2].first)) {
				cur += v[1].second;
				v[1].first--;
				count--;
			} else {
				if (v[0].first != 0) {
					cur += v[0].second;
					v[0].first--;
					count--;
				}
			}
			cout << cur;
			if (count) cout <<" ";
		}
		cout <<endl;
	}
	return 0;
}
