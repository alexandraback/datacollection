// Vishal Gupta IIIT-H
// novice_3
#include <bits/stdc++.h>
using namespace std;

#define sz(a) int((a).size())
#define all(c) c.begin(),c.end() //all elements of a container
#define rall(c) c.rbegin(),c.rend() 
#define INF		INT_MAX
#define FOR(i,a,b) 	for(int  i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define FORAB(i,a,b)      for(int i=(int)a; i<=b; i++)
#define PB push_back
#define MP make_pair
#define fill(a,b) memset(a,b,sizeof(a))
#define mod (int)(1e9 + 7)
#define F first
#define S second
typedef long long int LL;
typedef vector <int> VI;
typedef pair < int ,int > PII;
vector <pair <char,int> > dp[2];
void solve(string s, int u){
	int n=sz(s),cnt=0;
	char prev=s[0];
	rep(i,n){
		if(s[i]==prev) cnt++;
		else{
			dp[u].PB(MP(prev,cnt));
			prev=s[i]; cnt=1;
		}
	}
	dp[u].PB(MP(prev,cnt));
	//rep(i,sz(dp[u])) cout << dp[u][i].F << " "<<  dp[u][i].S <<endl;
	//cout << "&&&&&&&&&&&&&" << endl;
}
int main()
{
       string a,b;
       int test,testit,ans=0,u;
       cin >> test; 	
       rep(testit,test){
       		cin >> u;
       		cin >> a >> b;
       		rep(i,2) dp[i].clear();
       		solve(a,0);
       		solve(b,1);
       		ans=0;
       		bool ok=true;
      		
      		if(sz(dp[0])!=sz(dp[1])) {printf("Case #%d: Fegla Won\n",testit+1); continue; } 		
       		else {
       			rep(i,sz(dp[0])){
       					if(dp[0][i].F!=dp[1][i].F) {ok = false; break;} 
       					ans+=abs(dp[0][i].S-dp[1][i].S);		
       			}	
       			if(ok) printf("Case #%d: %d\n",testit+1,ans);
       			else printf("Case #%d: Fegla Won\n",testit+1);
       		}
       }
       return 0;
}

