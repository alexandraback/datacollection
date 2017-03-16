#include<iostream>
#include<cstdio>
using namespace std;
int n,a[1010];

 void run()
 {
	 int i,ans1=0,ans2=0,max=0;
	 scanf("%d",&n);
	 for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	 for(i=1;i<n;i++){
		 if(a[i]>a[i+1]){
			ans1+=a[i]-a[i+1];
			if(max<a[i]-a[i+1]) max=a[i]-a[i+1];
		 }
	 }
	 for(i=1;i<n;i++)
		 if(a[i]>=max) ans2+=max;
		 else ans2+=a[i];
	 printf("%d %d\n",ans1,ans2);
 }
int main()
{
	//freopen("A-large.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		printf("Case #%d: ",k);
		run();
	}
 return 0;
}

