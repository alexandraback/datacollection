#include <stdio.h>
int main(){
	int i,j,k;
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		int n;
		int M[10001];
		long long rate=0;
		long long ans1=0,ans2=0,now;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&M[i]);
			if(i && M[i-1]-M[i] > rate){
				rate=M[i-1]-M[i];
			}
			if(i){
				if(M[i]<M[i-1]){
					ans1+=M[i-1]-M[i];
				}
			}
		}
		now=M[0];
		for(i=1;i<n;i++){
			if(M[i-1]>rate){
				ans2+=rate;
			} else {
				ans2+=M[i-1];
			}
		}
		
		printf("Case #%d: %lld %lld\n",T,ans1,ans2);
	}
}
