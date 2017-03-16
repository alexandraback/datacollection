#include <stdio.h>
int main(){
	int i,j,k;
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		long long N,B;
		static long long M[100001];
		scanf("%lld%lld",&B,&N);
		for(i=0;i<B;i++){
			scanf("%lld",&M[i]);
		}
		long long ans=1;
		long long min=0,mid,max=1000000000LL*100000+1+123456789;
		long long t,cnt;
		if(N==0){
			goto ANS;
		}
		
		while(min<max){
			mid=(min+max)/2;
			cnt=0;
			for(i=0;i<B;i++){
				cnt+=(mid)/M[i] +1;
			}
			//printf("%lld %lld %lld %lld\n",min,max,mid,cnt);
			if(cnt<N){
				//printf("!ok");
				min=mid+1;
			} else {
				max=mid;
			}
		}
		//printf("%lld %lld %lld %lld\n",min,max,mid,cnt);
		t=max;
		cnt=0;
		for(i=0;i<B;i++){
			cnt+=(t-1)/M[i]+1;
		}
		//printf("%lld %lld\n",t,cnt);
		for(i=0;i<B;i++){
			if(t%M[i]==0)cnt++;
			if(cnt==N)break;
		}
		ans=i+1;
		
		
		ANS:
		printf("Case #%d: %lld\n",T,ans);
	}
}
