#include<stdio.h>
#include<algorithm>
int f(int len,int n){
	if(n<=(len+1)/2)
		return 0;
	n-=(len+1)/2;
	if(len%2==0){
		return 1+(n-1)*2;
	} else {
		return n*2;
	}
}
int main(){
	int i,j,k;
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		int r,c,n,N;
		scanf("%d%d%d",&r,&c,&N);
		int orig=N*4;
		int m=r*c;
		int ans=10000000;
		if(r==1) ans=f(c,N);
		else if(c==1) ans=f(r,N);
		else if(r%2&&c%2){
			n=N;
			int ans1=0;
			int h=m/2+m%2;
			int useh=h>n?n:h;
			ans1+=0*useh;
			n-=useh;
			int edge=r/2+c/2+r/2+c/2;
			int useedge=edge>n?n:edge;
			ans1+=3*useedge;
			n-=useedge;
			ans1+=4*n;
			n=0;
			
			n=N;
			int ans2=0;
			int h2=m/2;
			int useh2=h2>n?n:h2;
			ans+=0*useh2;
			n-=useh2;
			int use4=4>n?n:4;
			ans2+=2*use4;
			n-=use4;
			int edge2=r/2+c/2+r/2+c/2-4;
			int useedge2=edge2>n?n:edge2;
			ans2+=3*useedge2;
			n-=useedge2;
			ans2+=4*n;
			n=0;
			if(ans>ans1)ans=ans1;
			if(ans>ans2)ans=ans2;
		} else {
			n=N;
			int ans1=0;
			int h=m/2;
			int useh=h>n?n:h;
			ans1+=0*useh;
			n-=useh;
			int use2=2>n?n:2;
			n-=use2;
			ans1+=2*use2;
			int edge=r+c-4;
			int useedge=edge>n?n:edge;
			ans1+=3*useedge;
			n-=useedge;
			ans1+=4*n;
			n=0;
			ans=ans1;
		}
		printf("Case #%d: %d\n",T,ans);
	}
}
