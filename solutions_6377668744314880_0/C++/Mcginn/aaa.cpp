#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const int inf = 0x37373737;
const int U = 3030;
int T,N;
int x[U] , y[U];
int ans[U];

int sgn(ll x){
	if(x == 0) return 0;
	return x > 0 ? 1 : -1;
}

ll cross(int a,int b,int c){
	return 1ll * (x[b]-x[a])*(y[c]-y[a]) - 1ll * (x[c]-x[a])*(y[b]-y[a]);
}

void DO(int a,int b){
	int cnt1(0) , cnt2(0);
	for(int i=1;i<=N;++i)
		if(i != a && i != b){
			int sig = sgn(cross(a,b,i));
			if(sig > 0) cnt1++;
			else if(sig < 0) cnt2++;
		}
	cnt1 = min(cnt1,cnt2);
	if(cnt1 < ans[a]) ans[a] = cnt1;
}


int main(){
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for(int re=1;re<=T;++re){
		scanf("%d",&N);
		for(int i=1;i<=N;++i)
			scanf("%d%d",x+i,y+i);
		for(int i=1;i<=N;++i)
			ans[i] = inf;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				if(i != j)
					DO(i,j);
		printf("Case #%d: \n",re);
		if(N == 1) printf("0\n");
		else{
			for(int i=1;i<=N;++i)
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
