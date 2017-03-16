#include <stdio.h>
#include <algorithm>
using namespace std;
long long b[1010];
long long N,B;
long long count(long long m){
	long long res=0;
	for(int i=0;i<B;i++){
		if(m%b[i]==0){
			res+=m/b[i]+1;
		}else{
			res+=m/b[i]+1;
		}
	}
	return res;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%lld %lld",&B,&N);
		long long _mx=0;
		for(int i=0;i<B;i++){
			scanf("%lld",&b[i]);
			_mx=max(_mx,b[i]);
		}
		long long l=0,r=_mx*N;
		long long ans=-1;
		while(l<=r){
			long long mid=(l+r)/2ll;
			long long cnt=count(mid);
			if(cnt>=N){
				ans=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		long long tot=count(ans)-N;
		int ans_i=-1;
		for(int i=B-1;i>=0;i--){
			if(ans%b[i]==0){
				if(tot==0){
					ans_i=i;
					break;
				}
				tot--;
			}
		}
		printf("Case #%d: %d\n",t,ans_i+1);
	}
	return 0;
}
