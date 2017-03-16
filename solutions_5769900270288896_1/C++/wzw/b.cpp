#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define LL long long
#define inf (1<<30)
using namespace std;

int r,c,n,ans,a1[11111],a2[11111];

int fill(int cnt,int b){
	int ret=0;
	memset(a1,0,sizeof(a1));
	memset(a2,0,sizeof(a2));
	if (b==0){
		if (r==1 || c==1) ret++; else ret+=2;
		if (--cnt==0) return ret;
		a1[0]=1;
	}
	if (c>1 && (c-1)%2==b){
		if (r==1 || c==1) ret++; else ret+=2;
		if (--cnt==0) return ret;
		a1[c-1]=1;
	}
	if (r>1 && (r-1)%2==b){
		if (r==1 || c==1) ret++; else ret+=2;
		if (--cnt==0) return ret;
		a2[0]=1;
	}
	if (r>1 && c>1 && (r+c-2)%2==b){
		if (r==1 || c==1) ret++; else ret+=2;
		if (--cnt==0) return ret;
		a2[c-1]=1;
	}
	for (int i=0;i<c;i++) if (i%2==b && !a1[i]){
		if (r==1 || c==1) ret+=2; else ret+=3;
		if (--cnt==0) return ret;
	}
	for (int i=0;i<c;i++) if ((r-1+i)%2==b && !a2[i]){
		if (r==1 || c==1) ret+=2; else ret+=3;
		if (--cnt==0) return ret;
	}
	for (int i=1;i<r-1;i++) if (i%2==b){
		if (r==1 || c==1) ret+=2; else ret+=3;
		if (--cnt==0) return ret;
	}
	for (int i=1;i<r-1;i++) if ((i+c-1)%2==b){
		if (r==1 || c==1) ret+=2; else ret+=3;
		if (--cnt==0) return ret;
	}
	return ret+cnt*4;
}

int main(){
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	cin>>T;
	for (int _=1;_<=T;_++){
		cin>>r>>c>>n;
		printf("Case #%d: ",_);
		if (n<=(r*c+1)/2){
			puts("0");
			continue;
		}
		ans=inf;
		ans=min(ans,fill(n-(r*c+1)/2,1));
		ans=min(ans,fill(n-r*c/2,0));
		printf("%d\n",ans);
	}
}
