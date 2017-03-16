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

ll M[MAXN];

ll B, N;

ll atendidos (ll time){
	ll res = 0LL;
	FORR (i, B) res += time/M[i] + 1;
	return res;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	
	int T;
	cin>>T;
	FORR (ci, T) {
		
		cin>>B>>N;
		FORR (i, B) cin>>M[i];
		ll lo = 0, hi = (ll) INF * 10000LL;
		while (lo<hi) {
			ll mid = (lo+hi)>>1;
			if (atendidos(mid)<N) {
				lo = mid+1;
			} else {
				hi = mid;
			}
		}
		
		ll jafoi = 0LL;
		FORR (i, B) jafoi += lo / M[i];
		ll X = N - ((lo==0) ? 0 : atendidos(lo-1));
		//cout << lo << " " << atendidos(lo) << " " << atendidos(lo-1) << endl;
		ll res = -1;
		FORR (i, B) {
			//cout << lo << " " << lo/M[i] << " " << tmp/M[i] << endl;
			if ( (lo % M[i]) == 0) {
				if (X==1){
					res = i+1;
					break;
				} else {
					X--;
				}
			}
		}
		cout << "Case #" << ci + 1 << ": " << res << endl;
	}
}
