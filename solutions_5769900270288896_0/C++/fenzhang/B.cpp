#include<bits/stdc++.h>
using namespace std;
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define pritnf printf
#define N 1000514
#define MAP(x,y) ((x)*c+(y))
using namespace std;
typedef long long int lnt;
typedef double dou;
int dp[17][17][17*17];
int sol(int r,int c,int n){
	if(r>c)swap(r,c);
	//if(dp[r][c][n]!=-1)return dp[r][n][c];
	int rc=r*c;
	int nn=1<<rc;
	int ans=1<<30;
	for(int i=0;i<nn;i++){
		int th=0,cnt=0;
		for(int j=0;j<rc;j++){
			cnt+=(i>>j)%2;
		}
		if(cnt!=n)continue;
		for(int j=0;j<r;j++){
			for(int k=0;k<c;k++){
				if((i>>MAP(j,k))%2==0)continue;
				if(j>0&&(i>>MAP(j-1,k))%2)th++;
				if(k>0&&(i>>MAP(j,k-1))%2)th++;
			}
		}
		ans=min(ans,th);
	}
	return dp[r][c][n]=ans;
}
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("Bs.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	int t;RI(t);
	for(int ti=1;ti<=t;ti++){
		int r,c,n;
		RII(r,c);
		RI(n);
		printf("Case #%d: %d\n",ti,sol(r,c,n));
	}
	return 0;
}

