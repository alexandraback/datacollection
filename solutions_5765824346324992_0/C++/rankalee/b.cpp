#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int main(){
	int cs; cin >> cs;
	rep(CS, cs){
		
		int m, n; cin >> m >> n;
		
		vi v(m);
		rep(i, m) cin >> v[i];
		
		ll lo = -1, hi = 1e15, mid;
		while(lo + 1 < hi){
			mid = (lo + hi) / 2;
			ll cnt = 0;
			
			rep(i, m){
				cnt += mid / v[i] + 1;
			}
			if(cnt >= n) hi = mid;
			else lo = mid;
		}
		
		int ans = -1;
		if(hi > 0) rep(i, m) n -= (hi - 1) / v[i] + 1;
		rep(i, m){
			if(hi % v[i]) continue;
			if(--n == 0){
				ans = i + 1;
				break;
			}
		}
		
		printf("Case #%d: %d\n", CS + 1, ans);
	}
	return 0;
}
