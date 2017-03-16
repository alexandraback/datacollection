#include <bits/stdc++.h>
using namespace std;

void solve(){
	int R,C,n;
	scanf("%d%d%d",&R,&C,&n);
	int a[16][16];
	int all = 1<<(R*C);
	int dig[16];
	int ans=0x3f3f3f3f;
	for(int mask=0;mask<all;mask++){
		int cnt=0;
		for(int i=0;i<R*C;i++)if(mask&(1<<i))dig[i]=1,cnt++;else dig[i]=0;
		if(cnt!=n)continue;
		cnt=0;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)a[i][j]=dig[cnt++];
		}
		int tmp=0;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(i!=0)tmp+=(a[i][j]&a[i-1][j]);
				if(j+1<C)tmp+=(a[i][j]&a[i][j+1]);
			}
		}
		ans=min(ans,tmp);
	}
	printf("%d\n",ans);
}	
int main(){
	int T;
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		printf("Case #%d: ",cas+1);
		solve();
	}
	return 0;
}
