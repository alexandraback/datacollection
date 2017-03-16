#include<iostream>
using namespace std;
const int maxN=1010;
int M[maxN],N,B,ans;
long long calc(long long x){
	long long s;
	s=0;
	for(int i=0;i<B;i++)
		s=s+x/M[i]+1;
	return s;
}
int main(){
	freopen("B-large-1.in","r",stdin);
	freopen("B-large-1.out","w",stdout);
	int T,kase,i;
	long long l,r,mid,t;
	scanf("%d",&T);
	for(kase=1;kase<=T;kase++){
		scanf("%d%d",&B,&N);
		for(i=0;i<B;i++) scanf("%d",&M[i]);
		if(N<=B){
			printf("Case #%d: %d\n",kase,N);
			continue;
		}
		l=0; r=1LL<<62LL; 
		while(l+1<r){
			mid=(l+r)>>1;
			t=calc(mid);
		//	cout<<mid<<'\t'<<t<<endl;
			if(t<N) l=mid;
			else r=mid;
		}
		t=calc(l); l++;
	//	cout<<l<<'\t'<<t<<endl;
		for(i=0;i<B;i++){
			if(l%M[i]==0) t++;
			if(t==N) break;
		}
		printf("Case #%d: %d\n",kase,i+1);
	}
	return 0;
}
