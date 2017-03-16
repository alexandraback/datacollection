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
		
		int n; cin >> n;
		int a = 0, b = 0, c = 0;
		vi v(n);
		rep(i, n) cin >> v[i];
		
		rep(i, n - 1){
			a += max(0, v[i] - v[i + 1]);
			c = max(c, v[i] - v[i + 1]);
		}
		rep(i, n - 1){
			b += min(c, v[i]);
		}
		
		
		printf("Case #%d: %d %d\n", CS + 1, a, b);
	}
	return 0;
}