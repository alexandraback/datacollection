#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

struct M{
	int n;
	ll m;
	ll t;
}m[1005];

struct cmp{
	bool operator()(M a,M b){
		if(a.t==b.t)return a.n>b.n;
		return a.t>b.t;
	}
};

int gcd(int a,int b){
	while(b){
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int q1=1;q1<=t;q1++){
		int b,n,i;
		ll G=1,g;
		scanf("%d%d",&b,&n);
		priority_queue<M,vector<M>,cmp>q;
		for(i=1;i<=b;i++){
			int d;
			scanf("%d",&d);
			g=gcd(d,G);
			G=G*d/g;
			m[i].n=i;
			m[i].m=d;
			m[i].t=0;
			q.push(m[i]);
		}
		ll k=0;
		for(i=1;i<=b;i++){
			k+=G/m[i].m;
		}
		n=n%k+k;
		for(i=1;i<n;i++){
			M tmp=q.top();
			q.pop();
			tmp.t+=tmp.m;
			q.push(tmp);
		}
		M tmp=q.top();
		printf("Case #%d: %d\n",q1,tmp.n);
	}
	return 0;
}
