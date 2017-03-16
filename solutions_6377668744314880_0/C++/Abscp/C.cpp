#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int n,ans,T,x[3010],y[3010];
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&T);
	for(int test=1;test<=T;++test){
		printf("Case #%d:\n",test);
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d%d",&x[i],&y[i]);
		for(int i=1;i<=n;++i){
			ans=n;
			if(n<=3)ans=0;
			for(int j=1;j<=n;++j){
				if(i==j)continue;
				double da=y[i]-y[j],db=-(x[i]-x[j]),dc=(double)y[i]*(x[i]-x[j])+(double)(y[j]-y[i])*x[i];
				int res1=0,res2=0;
				for(int k=1;k<=n;++k){
					if(i==k||j==k)continue;
					double t=da*x[k]+db*y[k]+dc;
					if(t<0)++res1;
					if(t>0)++res2;
				}
				ans=min(ans,min(res1,res2));
			}
			printf("%d\n",ans); 
		}
		
	} 
	return 0;
	
}
