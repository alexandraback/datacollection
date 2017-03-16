#include<stdio.h>
int tcn,tc;
int main(){
	int a,b,n;
	int ans;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d%d%d",&a,&b,&n);
		ans=0;
		if((a*b+1)/2<n)ans+=(n-(a*b+1)/2)*2;
		if(a%2==1&&b%2==1&&(a*b+1)/2<n)ans+=(n-(a*b+1)/2);
		else if(((a*b+1)/2+2)<n)ans+=n-((a*b+1)/2+2);
		if((2*a+2*b-4+((a-2)*(b-2)+1)/2)<n)ans+=n-(2*a+2*b-4+((a-2)*(b-2)+1)/2);
		if(a%2==1&&b%2==1){
			if((2*a+2*b-4+((a-2)*(b-2)+1)/2)>n&&((2*b+((a-2)*b+1)/2)<=n||(2*a+(a*(b-2)+1)/2)<=n)){
				ans--;
			}
		}
		if(a==1||b==1){
			ans=2*n-a*b-1;
			if(ans<0)ans=0;
		}
		printf("Case #%d: %d\n",tc,ans);
	}
}