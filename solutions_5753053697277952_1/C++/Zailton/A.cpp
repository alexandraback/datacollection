#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORR(i,b) FOR(i, 0, b)
#define sz(e) (int)e.size()
#define CLR(x,v) memset (x, v, sizeof x)
#define pb push_back
#define all(e) e.begin(), e.end()

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 102;
const int INF = 1000000000;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin>>T;
	FORR (c, T) {
		cout << "Case #" << c+1 << ": ";
		int N; cin>>N;
		vector<ii> mvec;
		FORR (i, N) {
			int x; cin>>x;
			mvec.pb (ii(x, i));
			//cout << "aqui" << endl;
		}
		sort (all(mvec));
		vector<char> order;
		//cout << "-> " << N << " " << sz(mvec) << endl;
		while (!mvec.empty()) {
			//FORR (i, sz(mvec)) cout << mvec[i].first << " "; cout << endl;
			order.pb (mvec.back().second+'A');
			mvec.back().first--;
			if (mvec.back().first==0) mvec.pop_back();
			sort (all(mvec));			
		}
		if (sz(order)&1) {
			cout << order[0] << " ";
			order.erase (order.begin());	
		}
		FORR (i, sz(order)) {
			cout << order[i]; i++;
			cout << order[i] << " ";
		} cout << endl;
	}
}
