/* Code Jam Template */
#include <bits/stdc++.h>
using namespace std;
#define MOD 					1000000007
#define pb(x) 					push_back(x)
#define mp(x,y)                 make_pair(x,y)
#define FF 						first
#define SS 						second
#define s(n) 					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
//special macro for reading a character of input
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
/*
Use these macros when comparing variables of different data types.
For e.g. comparing int and long long will give error when used with std::max, use maX instead.
*/
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
typedef long long ll;
typedef unsigned long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<ll> vl;
typedef vector<PII> VII;
typedef vector<TRI> VT;

/*Main code begins now*/

void precompute() {
    /*
    Code that is common to all test cases and should be run before solving for any case, like Prime-NUmber Generation :)
    */


}
int r,c,n,ans=INT_MAX;
void read() {
    /*
    Read Global variables here
    */
    cin>>r>>c>>n;

}

int dp[1<<20];
int func(int k,int mask,int un)
{
    //cout<<r<<endl;
    if(k==n) {
        //cout<<un<<endl;
        //if(un==6) cout<<mask<<endl;
        ans=min(ans,un);
        return un;
    }
    int i ;
    if(dp[mask]!=-1) return dp[mask];
    dp[mask]=INT_MAX;
    for(i=1;i<=r*c;i++)
    {
        //cout<<i;
        int nun=un;
        if(((1<<i)&mask)==0)
        {

            if((i-1)%c&&((1<<(i-1))&mask)) nun++;
            if(i%c&&((1<<(i+1))&mask)) nun++;
            if(i>c&&((1<<(i-c))&mask)) nun++;
            if(i+c<=r*c&&((1<<(i+c))&mask)) nun++;
            //cout<<mask<<' '<<i<<' '<<nun<<endl;
             dp[mask]=min(dp[mask],func(k+1,(mask|(1<<i)),nun));

        }
    }
}
void solve() {

    /*
    Main logic goes here
    */
    ans=INT_MAX;
    memset(dp,-1,sizeof(dp));
    func(0,0,0);
    cout<<ans<<endl;
}


int main(){
   freopen("A.in", "r", stdin);
	freopen("output.in", "w", stdout);
	precompute();

	int t;
	s(t);

	for(int T = 1; T <= t; T++) {
	    read();
	    printf("Case #%d: ",T);
        solve();
  	}
	return 0;
}
