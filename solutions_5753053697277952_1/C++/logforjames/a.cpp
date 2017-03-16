#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

#define forsn(i,s,n) for (int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for (int i = (n - 1);i >= (int)(s);i--)
#define dforn(i,n) dforsn(i,0,n)
#define all(v) (v).begin(), (v).end()

int main() {
	int T; cin >> T;
	forn(caso, T) {
		cout << "Case #" << caso + 1 << ": ";
		
		int n; cin >> n;
		map<int, set<int> > senators;
		forn(i, n) {
			int t; cin >> t;
			senators[t].insert(i);
		}
		while (!senators.empty()) {
			int greatest = senators.rbegin()->first;
			vector<int> toRemove;
			if (senators[greatest].size() > 2) {
				toRemove.push_back(*senators[greatest].begin());
			} else if (senators[greatest].size() == 2) {
				auto it = senators[greatest].begin();
				toRemove.push_back(*it);
				it++;
				toRemove.push_back(*it);
			} else {
				toRemove.push_back(*senators[greatest].begin());
			}
			
			for (int r : toRemove) {
				cout << ((char)('A' + r));
				senators[greatest].erase(r);
				if (senators[greatest].empty()) senators.erase(greatest);
				if (greatest - 1 > 0) senators[greatest - 1].insert(r);
			}
			
			if (!senators.empty()) cout << " ";
		}
		cout << endl;
	}
}
