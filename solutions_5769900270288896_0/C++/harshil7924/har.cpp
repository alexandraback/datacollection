#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define f first
#define s second
#define mod 1000000007
#define inf 1e8

#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define mp make_pair
#define s second
#define rep(i,n) for(int i=0;i<n;i++)
#define M 360360
int dp[17][17][17];
int g[17][17];
int un(int mask,int r,int c){
	int it=0;
	int ans=0;
	memset(g,0,sizeof(g));
	for(int i=0;i<r*c;i++){
		if(i%r==0) it++;
		g[i%r+1][it]=(mask%2);
		mask/=2;
	}
	if(mask) return inf;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(g[i-1][j]==1 and g[i][j]==1) ans++;
			if(g[i][j-1]==1 and g[i][j]==1) ans++;
		}
	}
	return ans;
}
void calc(){
	for(int i=0;i<=16;i++){
		for(int j=0;j<=16;j++){
			for(int k=0;k<=16;k++)
				dp[i][j][k]=inf;
		}
	}
	for(int mask=0;mask<(1<<16);mask++){
		int b=__builtin_popcount(mask);
		for(int r=1;r<=16;r++){
			for(int c=1;c<=16  and r*c<=16 ;c++){
				if(r*c>=b){
					int ans=un(mask,r,c);
					dp[r][c][b]=min(dp[r][c][b],ans);
				}
			}
		}
	}
}
int main(){
freopen("B-small-attempt0.in","r",stdin);
freopen("output.txt","w",stdout);
int t,n,r,c;
calc();
cin>>t;
int cnt=0;
while(t--){
	cnt++;
	cin>>r>>c>>n;
//	if(n==0)
	//dp[r][c][n]=0;
	n=dp[r][c][n];
	cout<<"Case #"<<cnt<<": "<<n<<"\n";
}
}
