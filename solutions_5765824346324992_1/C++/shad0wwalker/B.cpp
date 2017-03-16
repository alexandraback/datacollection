#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node{
	long long t;
	int p;
	friend bool operator<(node a,node b){
		if(a.t<b.t) return 0;
		else if(a.t==b.t&&a.p<b.p) return 0;
		return 1;
	}
	node(long long tt = 0,int pp = 0){
		t=tt;p=pp;
	}
};

 long long GCD(long long x,long long y)
 {
	 if(!y) return x;
	 return GCD(y,x%y);
 }

 long long LCM(long long x,long long y)
 {
	 return x*y/GCD(x,y);
 }
 void run()
 {
	 int b,n,i,loopnum=0;
	 long long loop=1,a[1010];
	 node now;
	 priority_queue<node> q;
	 scanf("%d%d",&b,&n);
	 for(i=1;i<=b;i++){
		 scanf("%lld",&a[i]);
	 }
	 for(i=1;i<=b;i++)
		loop=LCM(loop,a[i]);
	 for(i=1;i<=b;i++)
		loopnum+=loop/a[i];
	 n=(n-1)%loopnum+1;
	 if(b>=n){
		 printf("%d\n",n);
		 return;
	 }
	 for(i=1;i<=b;i++)
		 q.push(node((long long)a[i],i));
	 for(i;i<n;i++){
		 now=q.top();
		 q.pop();
		 now.t+=a[now.p];
		 q.push(now);
	 }
	 printf("%d\n",q.top().p);
 }
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		printf("Case #%d: ",k);
		run();
	}
 return 0;
}

