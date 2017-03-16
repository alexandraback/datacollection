//venk13
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <cassert>

using namespace std;

#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int ab(int a) {return a < 0 ? -a : a;}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, cas = 1; cin >> t;
	while(t--) {
		cout << "Case #" << cas++ << ": ";
		int n; cin >> n;
		vector <string> lst(n);
		for(int i = 0; i < n; i++)
			cin >> lst[i];
		bool bad = 0;
		string last = ""; last += lst[0][0];
		for(int j = 1; j < len(lst[0]); j++) {
			if(lst[0][j] != lst[0][j - 1])
				last += lst[0][j];
		}
		for(int i = 1; i < n; i++) {
			string ret = ""; ret += lst[i][0];
			for(int j = 1; j < len(lst[i]); j++) {
				if(lst[i][j] != lst[i][j - 1])
					ret += lst[i][j];
			}
			if(ret != last) {
				bad = 1;
				break;
			}
		}
		if(bad) {
			cout << "Fegla Won" << '\n';
			continue;
		}
		int minMoves = 0, our = len(last);
		vector <int> vals(n), hptrs(n, 0);
		for(int k = 0; k < our; k++) {
			for(int i = 0; i < n; i++) {
				int measure = 0;
				while(hptrs[i] < len(lst[i]) && lst[i][hptrs[i]] == last[k]) {
					++hptrs[i]; ++measure;
				}
				vals[i] = measure;
			}
			int minChoice = 1 << 30;
			for(int i = 0; i < n; i++) {
				int nowMoves = 0;
				for(int j = 0; j < n; j++)
					nowMoves += ab(vals[j] - vals[i]);
				minChoice = min(minChoice, nowMoves);
			}
			minMoves += minChoice;
		}
		cout << minMoves << '\n';
	}
	return 0;
}