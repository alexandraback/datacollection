#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 111111
using namespace std;
typedef pair<int,int> pt;

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cout << "Case #" << tt << ": ";

		int n, m, k;
		cin >> n >> m >> k;

		int ans = 1e9;
		vector<pair<int, int> > e;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) e.pb(mp(i, j));
		for (int o = 0; o < pw(e.size()); o++) {
			int t = 0;
			for (int i = 0; i < e.size(); i++) if (o & pw(i)) t++;
			if (t != k) continue;
		
			int s = 0;
			for (int i = 0; i < e.size(); i++) if (o & pw(i)) {
				for (int j = i + 1; j < e.size(); j++) if (o & pw(j)) {
					if (abs(e[i].F - e[j].F) + abs(e[i].S - e[j].S) == 1) s++;
				}
			}				
			ans = min(ans, s);
		}

		cout << ans << endl;

	}
	return 0;
}