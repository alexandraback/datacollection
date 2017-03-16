/*
ID: xiaoche4
PROG: skidesign
LANG: C++
*/
//#include "TC.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
struct Node{
	ll time,id;
	Node(){}
	Node(ll t,ll i){
		time=t; id=i;
	}
};
struct Cmp{
	bool operator()(const Node n1,const Node n2){
		if(n1.time!=n2.time) return n1.time>n2.time;
		return n1.id>n2.id;
	}
};
ll T,B,N;
ll m[1000];
ll l[1000]; ll cnt;
priority_queue<Node,vector<Node>,Cmp> q;
bool check(ll t,ll n){
	cnt=0;
	for(int i=0;i<B;i++){
		cnt+=t/m[i]+(t%m[i]!=0);
		l[i]=t%m[i];
		if(l[i]!=0) l[i]=m[i]-l[i];
	}
	return cnt>=N-n;
}
int main()
{
	freopen("B-large.in","r",stdin);
	//freopen("Ans.out","w",stdout);
	//ifstream fin("dict.out");
	//ofstream fout("Ans.out");
	//FILE *fin=fopen("table.txt","r");
	FILE *fout=fopen("Ans.out","w");
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>B>>N;
		for(int i=0;i<B;i++)
			cin>>m[i];
		/*
		for(int i=0;i<B;i++){
			q.push(Node(0,i+1));
		}
		Node ans;
		if(N>10000){
			fprintf(fout,"Case #%d: %d\n",k,-1);
			while(!q.empty())
			q.pop();
			continue;
		}
		for(int i=0;i<N;i++){
			ans=q.top(); q.pop();
			q.push(Node(ans.time+m[ans.id-1],ans.id));
		}
		while(!q.empty())
			q.pop();*/
		for(int i=1;i<=B;i++){
			ll l=-1,h=1e15,mid;
			while(l+1!=h){
				mid=(l+h)/2;
				if(check(mid,i))
					h=mid;
				else
					l=mid;
			}
			check(h,i);
			if(cnt==N-i) break;
		}
		cnt=N-cnt;
		for(int i=0;i<B;i++){
			q.push(Node(l[i],i+1));
		}
		Node ans;
		for(int i=0;i<cnt;i++){
			ans=q.top(); q.pop();
			q.push(Node(ans.time+m[ans.id-1],ans.id));
		}
		while(!q.empty())
			q.pop();
		fprintf(fout,"Case #%d: %d\n",k,ans.id);
		cout<<k<<" ok"<<endl;
	}

	return 0;
}