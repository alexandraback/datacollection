#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010];
int main(){
	int T;
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int _=1;_<=T;_++) {
		printf("Case #%d: ",_);
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",a+i);
		int ans=0;
		for (int i=1;i<n;i++) ans+=max(a[i]-a[i+1],0);
		printf("%d ",ans);
		ans=0;int mx=0;
		for (int i=1;i<n;i++) mx=max(mx,a[i]-a[i+1]);
		for (int i=1;i<n;i++) ans+=min(mx,a[i]);
		printf("%d\n",ans);
	}
	return 0;
}
