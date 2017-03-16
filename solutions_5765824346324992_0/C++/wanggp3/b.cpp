#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;
const int N = 1005;
typedef long long LL;
int n,B,a[N];
int get(){
	int ret=1;
	for(int i=0;i<B;i++){
		ret = ret*a[i]/__gcd(ret,a[i]);
	}
	return ret;
}
struct Node{
	int id,t;
	Node(int id=0,int t=0):id(id),t(t){}
};
	bool operator<(const Node& l,const Node& r){
		if(l.t!=r.t)return l.t>r.t;
		else return l.id>r.id;
	}
void solve(){
	scanf("%d%d",&B,&n);
	for(int i=0;i<B;i++)scanf("%d",&a[i]);
	int tmp=get();
	int tot=0;
	for(int i=0;i<B;i++)tot+=tmp/a[i];
	n=n%tot;
	if(n==0)n=tot;
	priority_queue<Node>Q;
	for(int i=0;i<B;i++){
		Q.push(Node(i,0));
	}
	int ans;
	for(int i=1;i<=n;i++){
		Node top = Q.top();Q.pop();
		ans=top.id;
        Q.push(Node(top.id,top.t+a[ans]));
	}	
	printf("%d\n",ans+1);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		printf("Case #%d: ",cas);
		solve();
	}
	return 0;
}
