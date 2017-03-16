#include <cstdio>

int i,k,t,T,b,n,m[1001];
long long L,U,j;

long long f(int N){
	long long l,u,a;
	l=0,u=1e15;
	while(l<u){
		a=(l+u)/2;
		for(i=j=0;i<b;i++){
			j+=a/m[i]+1;
		}
		if(j==N){
			break;
		}else if(N<j){
			u=a-1;
		}else{
			l=a+1;
		}
	}
	return a;
}

int main(){
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d%d",&b,&n);
		for(i=0;i<b;i++){
			scanf("%d",&m[i]);
		}
		L=f(n-1);
		for(i=j=0;i<b;i++){
			j+=L/m[i]+1;
		}
		if(j<n){
			for(i=0,j=100001;i<b;i++){
				if(L%m[i]&&(m[i]-L%m[i])<j){
					j=m[i]-L%m[i];
					k=i;
				}
			}
		}else{
			for(i=b-1,k=j-n;i>=0;i--){
				if(L%m[i]==0){
					k--;
					if(k<0){
						k=i;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n",t,k+1);
	}
	return 0;
}
