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

int T;
map<int,int> u;

int main() {
	cin >> T;
	REP(_, T) {
		u.clear();
		REP(k, 2) {
			int r, m;
			cin >> r;
			--r;
			REP(i, 4) REP(j, 4) {
				cin >> m;
				if (i == r)
					++u[m];
			}
		}
		int cnt = 0, ans;
		FORIT(it, u) {
			if(it->second > 1)
				++cnt, ans = it->first;
		}
		cout << "Case #" << _+1 << ": ";
		if (cnt == 1)
			cout << ans << endl;
		else if (cnt == 0)
			cout << "Volunteer cheated!" << endl;
		else
			cout << "Bad magician!" << endl;
	}
	return 0;
}

