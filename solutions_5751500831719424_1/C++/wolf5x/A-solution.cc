#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP(x,y) make_pair((x),(y))
#define FI(x) ((x).first)
#define SE(x) ((x).second)
#define SZ(x) ((x).size())
#define LEN(x) ((x).length())

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int T, N;
string S[110];

int cost(vector<int> &v) {
	sort(v.begin(), v.end());
	if (v[0] == 0)
		return -1;
	int c = 0, m = (v.size()-1)/2;
	REP(i, v.size()) {
		c += abs(v[i]-v[m]);
	}
	return c;
}

int main() {
	cin >> T;
	FOR(_, 1, T+1) {
		cin >> N;
		REP(i, N)
			cin >> S[i];
		vector<int> p(N, 0), v(N, 0);
		int ans = 0;
		while(true) {
			char ch;
			REP(i, N)
				if (p[i] < S[i].length()) 
					ch = S[i][p[i]];
			bool moved = false;
			REP(i, N) {
				v[i] = 0;
				while(p[i] < S[i].length() && S[i][p[i]] == ch)
					p[i]++, v[i]++, moved = true;
			}
			if (!moved)
				break;
			int tmp = cost(v);
			if (tmp < 0) {
				ans = -1;
				break;
			}
			ans += tmp;
		}
		cout << "Case #" << _ << ": ";
		if (ans >= 0)
			cout << ans << endl;
		else 
			cout << "Fegla Won" << endl;
	}
	return 0;
}

