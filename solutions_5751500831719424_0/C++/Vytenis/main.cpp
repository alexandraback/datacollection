#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
 
using namespace std;
 
 
#define REP(a,b) for (int a=0; a<(int)(b); ++a)
#define FOR(a,b,c) for (int a=(b); a<(int)(c); ++a)
 
char s[100][128];
vector <pair<char,int> > m[100];

int main() {
	int t, n;

	cin >> t;

	REP(tc,t) {
		cin >> n;

		bool ok = true;
		REP(i,n) {
			cin >> s[i];
			m[i].clear();
			int pos = 0, last = 0;
			while (s[i][pos]) {
				while (s[i][pos] && s[i][pos] == s[i][pos+1]) ++pos;
				m[i].push_back(make_pair(s[i][pos], pos-last+1));
				++pos;
				last = pos;
			}
			if (i > 0) {
				if (m[i].size() != m[i-1].size()) ok = false;
				else {
					REP(j,m[i].size()) if (m[i][j].first != m[i-1][j].first) ok = false;
				}
			}
		}

		cout << "Case #" << tc+1 << ": ";

		if (!ok) cout << "Fegla Won" << endl;
		else {
			int res = 0;
			REP(i,m[0].size()) {
				int best = 9999999, cur;
				REP(j,n) {
					cur = 0;
					REP(k,n) cur += abs(m[j][i].second-m[k][i].second);
					best = min(best,cur);
				}
				res += best;
			}
			cout << res << endl;
		}

	}

	return 0;
} 