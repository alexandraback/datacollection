#include<stdio.h>
#include<string.h>

int a[1005];

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		int n;
		scanf("%d",&n);
		int i,ans1=0,m=0,ans2=0;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<n;i++)ans1+=(a[i]-a[i+1]>0?a[i]-a[i+1]:0);
		for(i=1;i<n;i++)if(m<a[i]-a[i+1])m=a[i]-a[i+1];
		for(i=1;i<n;i++)ans2+=(a[i]<m?a[i]:m);
		printf("Case #%d: %d %d\n",q,ans1,ans2);
	}
	return 0;
}
