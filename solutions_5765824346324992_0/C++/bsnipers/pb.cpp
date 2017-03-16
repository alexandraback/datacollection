#include <stdio.h>

long long all[1005];

long long check(long long tim, long long &b)
{
	long long ans=0;
	for(int i=0; i<b; i++){
		ans+=tim/all[i]+(tim%all[i]>0);
	}
	return ans;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("pb0.out","w",stdout);
	int cas;
	long long b,n;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		scanf("%I64d %I64d",&b,&n);
		for(int i=0; i<b; i++){
			scanf("%I64d",&all[i]);
		}
		long long ans=-1,step=1ll<<60;
		while(step){
			if(check(ans+step,b)>=n){
				step>>=1;
			}else{
				ans+=step;
			}
		}
		long long cnt=n-check(ans,b)-1;
		for(int i=0; i<b; i++){
			if(ans%all[i]==0){
				if(cnt){
					cnt--;
				}else{
					printf("Case #%d: %d\n",T,i+1);
					break;
				}
			}
		}
	}
	return 0;
}
