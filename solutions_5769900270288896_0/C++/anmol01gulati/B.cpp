#include <bits/stdc++.h>
using namespace std;

#define s(n)            scanf("%d",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define ss(n)           scanf("%s",n)
#define pls(x)          cout << x << " "
#define pln(x)          cout << x << "\n"
#define pis(x)          printf("%d ", x)
#define pin(x)          printf("%d\n", x)
#define pnl             printf("\n")
#define dbn             cerr << "\n"
#define dbg(x)          cerr << #x << " : " << x << " "
#define dbs(x)          cerr << x << " "
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define rep(i,n)        FOR(i,0,n-1)
#define foreach(c,v)    for(__typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp              make_pair
#define FF              first
#define SS              second
#define pb              push_back
#define fill(a,v)       memset(a,v,sizeof(a))
#define all(x)          x.begin(),x.end()
#define sz(v)           ((int)(v.size()))
#define INF             (int)1e9
#define LINF            (long long)1e18
#define EPS             1e-9
#define INDEX(arr,ind)  (lower_bound(all(arr),ind)-arr.begin())

typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<pii> vii;

const int MAXN = 200015;
const int MOD  = 1000000007;
/*Main code begins now */
int r,c;
bool valid(int i,int j){
	return i>=0 and j>=0 and i<r and j<c;
}
int dx[] = {1,0};
int dy[] = {0,1};
int G[20][20];
int main(){
	int t;
	s(t);
	int n,m;
	rep(z,t){
		printf("Case #%d: ",z+1);
		s(r),s(c),s(n);
		m = r*c;
		int M = (1<<m);
		int ans = INF;
		for(int mask = 0;mask < M;mask++){
			if(__builtin_popcount(mask) == n){
				int ret = 0;
				rep(i,r)rep(j,c) G[i][j] = false;
				for(int ind = 0;ind<m;ind++) {
					if(mask&(1<<ind)) {
						int i = ind/c;
						int j = ind%c;
						G[i][j] = true;
					}
				}
				rep(i,r){
					rep(j,c){
						if(G[i][j] == true){
							rep(k,2){
								int u = i + dx[k];
								int v = j + dy[k];
								if(valid(u,v) and G[u][v] == true) ret++;
							}
						}
					}
				}
				ans = min(ans,ret);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}