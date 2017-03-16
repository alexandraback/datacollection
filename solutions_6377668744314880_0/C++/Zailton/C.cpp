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

const int INF = 1000000000LL;

const int MAXN = 200005;

ll x[MAXN], y[MAXN];

ll tang (pair<ll, ll> p1, pair<ll, ll> p2) {
	ll x1 = p1.first, y1 = p1.second, x2 = p2.first, y2	= p2.second;
	return y1*x2 < y2*x1;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	
	int T;
	cin>>T;
	FORR (ci, T) {
		
		ll N;
		cin>>N;
		cout << "Case #" << ci + 1 << ":" << endl;
		FORR (i, N) cin>>x[i]>>y[i];
		FORR (i, N) {
			vector<pair<ll, ll> > left, right;
			FORR (j, N) {
				if (j==i) continue;
				ll nx = x[j]-x[i], ny = y[j]-y[i];
				if (nx<0LL || (nx==0LL && ny>0LL)) left.push_back (pair<ll, ll> (nx, ny));
				else right.push_back (pair<ll, ll>(nx, ny));
			}
			sort (all(left), tang);
			sort (all(right), tang);
			int res = INF;

			int it2 = 0, it1 = 0;
			
			//cout << sz(right) << endl;
			//FORR (i, sz(right)) cout << "(" << right[i].first << ", " << right[i].second << "), "; cout << endl;
			//cout << sz(left) << endl;
			//FORR (i, sz(left)) cout << "(" << left[i].first << ", " << left[i].second << "), "; cout << endl;
			//if (it1==sz(right)) res = 0LL;
			for (; it1 < sz(right); ) {
				int it1r = it1;
				while (it1r<sz(right) && !tang(right[it1],right[it1r]) && !tang(right[it1r],right[it1])) it1r++;
				while (it2<sz(left) && tang(right[it1], left[it2])) it2++;
				int it2r = it2;
				while (it2r<sz(left) && !tang(right[it1], left[it2r]) && !tang(left[it2r], right[it1])) it2r++;
				int cima = sz(right) - it1r + it2, baixo = it1 + sz(left) - it2r;
				res = min (res, min(cima, baixo));
				//cout << it1 << " " << baixo << " " << cima << endl;
				it2 = it2r;
				it1 = it1r;
				
			}

			swap (left, right);
			it2 = 0, it1 = 0;
			for (; it1 < sz(right); ) {
				int it1r = it1;
				while (it1r<sz(right) && !tang(right[it1],right[it1r]) && !tang(right[it1r],right[it1])) it1r++;
				while (it2<sz(left) && tang(right[it1], left[it2])) it2++;
				int it2r = it2;
				while (it2r<sz(left) && !tang(right[it1], left[it2r]) && !tang(left[it2r], right[it1])) it2r++;
				int cima = sz(right) - it1r + it2, baixo = it1 + sz(left) - it2r;
				res = min (res, min(cima, baixo));
				//cout << it1 << " " << baixo << " " << cima << endl;
				it2 = it2r;
				it1 = it1r;
				
			}
			if (N==1) res = 0LL;
			cout << res << endl;

		}
	
	}
}
