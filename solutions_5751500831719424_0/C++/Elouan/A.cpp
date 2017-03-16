#include <algorithm>
#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>

using namespace std;

#define rep(a, b, e) for(int a = (int) b; a < (int) e; ++a)
#define clr(a, val) memset(a, val, sizeof(a))
#define debug(a) cerr << #a << ": " << a << endl;
#define debugv(b, t) cerr << #b << ":\n"; rep(countvec, 0, t) { cerr << b[countvec] << '\t'; } cerr << endl;
#define debugm(c, t, u) cerr << #c << ":\n"; rep(countmat, 0, t) { rep(countbb, 0, u) { cerr << c[countmat][countbb] << '\t'; } cerr << endl; }
string tos(int a) { ostringstream os(""); os << a; return os.str(); }

#define MAXN 100
#define SIZE(x) ((int)(x).size())
#define INF (1<<30)

vector< pair<char, int> > fixos[MAXN];
int t, n;

bool ok() {
	int sz = SIZE(fixos[0]);
	rep(i, 1, n) if(SIZE(fixos[i]) != sz) return 0;
	rep(i, 0, sz) {
		char c = fixos[0][i].first;
		rep(j, 1, n) {
			char cur = fixos[j][i].first;
			if(cur != c) return 0;
		}
	}
	return 1;
}

void solve(int tc) {
	cin >> n;
	rep(i, 0, n) fixos[i].clear();
	string s;
	rep(i, 0, n) {
		cin >> s;
		int len = s.length();
		char prev = s[0];
		int cant = 1;
		rep(j, 1, len) {
			char c = s[j];
			if(c != prev) {
				fixos[i].push_back( make_pair(prev, cant) );
				prev = c;
				cant = 1;
			} else ++cant;
		}
		fixos[i].push_back( make_pair(prev, cant) );
	}
	if(ok()) {
		int min_cost = 0;
		int sz = SIZE(fixos[0]);
		rep(i, 0, sz) {
			int mini = INF;
			rep(j, 1, 101) {
				int sum = 0;
				rep(k, 0, n) sum += abs(fixos[k][i].second - j);
				mini = min(mini, sum);
			}
			min_cost += mini;
		}
		cout << "Case #" << tc << ": " << min_cost << endl;
	} else {
		cout << "Case #" << tc << ": " << "Fegla Won" << endl;
	}
}

int main() {
	#ifndef ONLINE_JUDGE 
		freopen("D:/in.txt","r",stdin); 
		freopen("D:/out.txt","w",stdout); 
		clock_t start = clock(); 
	#endif
	
	cin >> t;
	rep(tc, 1, t + 1)
		solve(tc);
	
	#ifndef ONLINE_JUDGE 
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start)); 
	#endif 
	return 0;
}
