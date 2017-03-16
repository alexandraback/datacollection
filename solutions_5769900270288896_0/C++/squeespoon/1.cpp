#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

const int INF=1e9;

int r,c,n;
int tmp,ans;
bool mp[18][18];
int curn;

void dfs(int rr,int cc){
	if(!ans)return;
	if(curn>n)return;
	if(rr>r)return;
	
	//if( (rr-1)*c+cc + n - curn > r*c )return;
	//cout<<"dfsing "<<rr<<" "<<cc<<endl;
	//cout<<"curn="<<curn<<endl;
	
	int nextc=cc+1;
	int nextr=rr;
	if(nextc>c){
		nextc=1;
		nextr++;
	}
	
	if(mp[rr][cc]){
		if(mp[rr-1][cc])tmp++;
		if(mp[rr][cc-1])tmp++;
	}
	
	if(curn==n){
		ans=min(ans,tmp);
	}
	
	curn++;
	mp[nextr][nextc]=1;
	dfs(nextr,nextc);
	mp[nextr][nextc]=0;
	curn--;
	
	dfs(nextr,nextc);
	
	if(mp[rr][cc]){
		if(mp[rr-1][cc])tmp--;
		if(mp[rr][cc-1])tmp--;
	}
}

int main(){
	
	freopen("B-small-attempt0.in","r",stdin);
	
	freopen("B-small-attempt0.out","w",stdout);
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		cas++;
		cin>>r>>c>>n;
		memset(mp,0,sizeof(mp));
		tmp=0;
		ans=INF;
		curn=0;
		
		dfs(1,0);
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}

/*
const int INF=1e9;

#define ll long long


ll inv(ll x){
	ll tmp[10];
	ll m=0;
	ll last=0;
	while(x){
		tmp[m++]=x%10;
		if(x%10){
			last=m;
		}
		x/=10;
	}
	ll re=0;
	for(ll i=0;i<m;i++){
		re+=tmp[i];
		re*=10;
	}
	re/=10;
	return re;
}

ll wei(ll x){
	int re=0;
	while(x){
		x/=10;
		re++;
	}
	return re;
}

ll fun(ll x){
	if(x<=20)return x;
	
	int weishu=wei(x);
	ll invx=inv(x);
	int weishu2=wei(invx);
	if(invx<x&&weishu==weishu2){
		return fun(invx)+1;
	}else{
		return fun(x-1)+1;
	}

}

int main(){
	
	freopen("A-small-attempt0.in","r",stdin);
	
	freopen("cmp.out","w",stdout);
	
	
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		cas++;
		ll n;
		cin>>n;
		
		ll re=fun(n);
		
		printf("Case #%d: %I64d\n",cas,re);
		
	}
	return 0;
}*/
