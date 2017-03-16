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

		if ((n * m + 1) / 2 >= k) {
			cout << 0 << endl;
			continue;
		}
		int ans = 1e9;

		for (int g = 0; g < 2; g++) {
			int c = 0;
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if ((i + j) % 2 == g) c++;

			vector<int> e;
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if ((i + j) % 2 != g) {
				int v = 0;
				if (i != 0) v++;
				if (i < n - 1) v++;
				if (j != 0) v++;
				if (j < m - 1) v++;
				e.pb(v);
			}
			sort(e.begin(), e.end());
			int s = 0;
			for (int i = 0; i < k - c; i++) s += e[i];

			ans = min(ans, s);
		}
		cout << ans << endl;

	}
	return 0;
}