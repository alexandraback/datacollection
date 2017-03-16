//Aditya Shah

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

#define vi vector<int>
#define vs vector<string>
#define vpii vector<pii>
#define all(v) v.begin(), v.end()

#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)
#define fio fr; fw

#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++)
#define forup(i,a,b) for(int i=(a); i<(b); ++i)
#define fordn(i,a,b) for(int i=(a); i>(b); --i)
#define rep(i,a) for(int i=0; i<(a); ++i)

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf(" %s",x)

#define F first
#define S second

#define pb push_back
#define pf push_front
#define mp make_pair

#define wait system("pause")

const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();

int dp[17][17][17], grid[20][20];

int main() {
    fio;
    int n, r, c, test;
    gi (test);
    memset(dp, 255, sizeof dp);
    rep (t, test) {
        gi(r);
        gi(c);
        gi (n);
        printf ("Case #%d: ", t + 1);
        int &res = dp[r][c][n];
        if(res != -1){
        	printf("%d\n",res);
        	continue;
        }
        res = inf;
        int tot = r*c;
        rep(mask,(1<<tot)){

        	if(__builtin_popcount(mask) == n){
        		int idx = 0, ans = 0;

        		rep(i,20){
        			rep(j,20){
        				grid[i][j] = 0;
        			}
        		}

        		forup(i,1,r+1){
        			forup(j,1,c+1){
        				if(mask & (1 << idx)){
        					grid[i][j] = 1;
        					ans += (grid[i-1][j] + grid[i][j-1]);
        				}
        				++idx;
        			}
        		}
        		res = min(res, ans);
        	}
        }
        printf("%d\n", res);
    }
    return 0;
}
