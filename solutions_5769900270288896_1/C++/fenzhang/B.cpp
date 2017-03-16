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
	if(dp[r][c][n]!=-1)return dp[r][c][n];
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
int sol3(int r,int c,int n){
	if(r>c)swap(r,c);
	if(r==1)return 1<<30;
	int rc=r*c,src=(r-2)*(c-2),all=r*(c-1)+c*(r-1);
	n=rc-n;
	int a[10];
	a[4]=(src+1)/2;
	a[0]=a[1]=0;
	if(r%2&&c%2){
		a[2]=4;
		a[3]=(r/2-1+c/2-1)*2;
	}
	else if(r%2==0&&c%2==0){
		a[2]=2;
		a[3]=(r/2-1+c/2-1)*2;
	}
	else{
		if(r%2)swap(r,c);
		a[2]=2;
		a[3]=c-2+(r/2-1)*2;
	}
	int ans=all;
	for(int i=4;i;i--){
		int d=min(n,a[i]);
		ans-=d*i;
		n-=d;
	}
	return ans;
}
int sol2(int r,int c,int n){
	if(r>c)swap(r,c);
	int rc=r*c,src=(r-2)*(c-2);
	int a[10];
	a[0]=(rc+1)/2;
	a[1]=0;
	if(r==1){
		a[1]=1-(c%2);
		a[2]=rc-a[0]-a[1];
		a[3]=0;
		a[4]=0;
	}
	else if(r%2&&c%2){
		a[2]=0;
		a[3]=r/2*2+c/2*2;
		a[4]=(r-2)*(c-2)/2;
	}
	else if(r%2==0&&c%2==0){
		a[2]=2;
		a[3]=(r/2-1+c/2-1)*2;
		a[4]=(r-2)*(c-2)/2;
	}
	else{
		if(r%2)swap(r,c);
		a[2]=2;
		a[4]=(r-2)*(c-2)/2;
		a[3]=rc-a[0]-a[2]-a[4];
	}
	int ans=0,tn=n;;
	for(int i=0;i<=4;i++){
		int d=min(n,a[i]);
		ans+=d*i;
		n-=d;
	}
	return min(ans,sol3(r,c,tn));
}
int main(){
	freopen("B-large.in","r",stdin);
	freopen("Bl.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	int t;RI(t);
	for(int ti=1;ti<=t;ti++){
		int r,c,n;
		RII(r,c);
		RI(n);
		//printf("Case #%d: %d\n",ti,sol(r,c,n));
		printf("Case #%d: %d\n",ti,sol2(r,c,n));
	}
	return 0;
}

