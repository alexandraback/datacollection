#include<cstdio>
#include<iostream>
using namespace std;
int n,ans1,ans2,T;
int a[1010];
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for(int test=1;test<=T;++test){
		ans1=ans2=0;
		int k=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=1;i<n;++i)
			if(a[i]>a[i+1])
				ans1+=a[i]-a[i+1];
		int mi=0;
		for(int i=1;i<n;++i)
			mi=max(mi,a[i]-a[i+1]);
		for(int i=1;i<n;++i)
			ans2+=min(a[i],mi);
		printf("Case #%d: %d %d\n",test,ans1,ans2);
	}
	return 0;
} 
