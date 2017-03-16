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
vector <pair <char,int> > dp[110];
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
       		rep(i,u) dp[i].clear();
       		rep(i,u) {
       			cin >> a;
       			solve(a,i);
       		}
       		ans=0;
       		bool ok=true;
      		rep(i,u) if(sz(dp[i])!=sz(dp[0])) {ok = false; break;}	
      		if(!ok) { printf("Case #%d: Fegla Won\n",testit+1); continue; } 		
       		else {
       			int ans1=0, ans2=0, ans3=0;
       			rep(i,sz(dp[0])){
       					int sum1=0, avg;
       					rep(j,u){
       						if(dp[j][i].F!=dp[0][i].F) {ok=false; break;}	
       						sum1+=dp[j][i].S;			
       					}				
       					if(!ok){printf("Case #%d: Fegla Won\n",testit+1); break; }
       					avg=sum1/u;
       					rep(j,u){
       						ans1+=abs(dp[j][i].S-avg);			
       						ans2+=abs(dp[j][i].S-avg-1);
       						ans3+=abs(dp[j][i].S-avg+1);
       					}
       			}	
       			if(ok) printf("Case #%d: %d\n",testit+1,min(ans1,min(ans2,ans3)));
       		}
       }
       return 0;
}

