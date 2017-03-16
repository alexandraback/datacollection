#include <bits/stdc++.h>      
using namespace std;  

#define ll long long

int m[1010];


struct node{
	int idx;
	ll tot_time;
	node(int idx,ll tot_time):idx(idx),tot_time(tot_time){
	}
	node(){
	}
	bool operator <(const node& other)const{
		if(tot_time!=other.tot_time){
			return tot_time>other.tot_time;
		}
		return idx>other.idx;
	}
};

int main(){
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		cas++;
		int b,n;
		cin>>b>>n;
		priority_queue<node> que;
		
		ll gongbeishu=1;
		ll num=0;
		for(int i=1;i<=b;i++){
			scanf("%d",&m[i]);
			que.push(node(i,0));
			if(gongbeishu%m[i])gongbeishu*=m[i];
		}
		
		for(int i=1;i<=b;i++){
			num+=gongbeishu/m[i];
		}
		
		n%=num;
		if(n==0)n=num;
		
		for(int i=1;i<n;i++){
			node cur=que.top();	que.pop();
			que.push( node( cur.idx,cur.tot_time+m[cur.idx]) );
		}
		node ans=que.top();
		
		printf("Case #%d: %d\n",cas,ans.idx);
	}
	return 0;
}
