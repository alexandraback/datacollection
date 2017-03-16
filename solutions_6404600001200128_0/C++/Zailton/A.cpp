#include<bits/stdc++.h>
 
using namespace std;
 
// Typedefs
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
 
// Macros
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, a) FOR(i, 0, a)
#define sz(e) (int)e.size()
#define all(e) e.begin(), e.end()
#define pb(e) push_back(e)

const int INF = 1000000000;

const int MAXN = 200005;

ll v[MAXN];

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	
	int T;
	cin>>T;
	FORR (ci, T) {
		int n;
		cin>>n;
		ll r1 = 0;
		FORR (i, n) cin>>v[i];
		FOR (i, 1, n) r1 += max (0LL, v[i-1]-v[i]);
		ll maior = 0;
		FOR (i, 1, n) maior = max(maior, v[i-1]-v[i]);
		ll r2 = 0;
		FOR (i, 1, n) r2 += min (maior, v[i-1]);
		cout << "Case #" << ci + 1 << ": " << r1 << " " << r2 << endl;
	}
}
