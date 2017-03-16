/*************************************************************************
    > File Name: google2.cpp
    > Author: cy
    > Mail: 1002@qq.com 
    > Created Time: 15/4/18 10:08:29
 ************************************************************************/

#include<iostream>
#include<cstring>
#include <algorithm>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<stdlib.h>
#include<iomanip>
#include<list>
#include<deque>
#include<map>
#include <stdio.h>
#include <queue>

const int maxn=1000+5;

#define inf 0x3f3f3f3f
  #define INF 0x3FFFFFFFFFFFFFFFLL
#define rep(i,n) for(i=0;i<n;i++)
 #define reP(i,n) for(i=1;i<=n;i++)

#define ull unsigned long long
 #define ll long long

#define cle(a) memset(a,0,sizeof(a))

using namespace std;
struct node{
	int val;
	int ip;
	bool operator<(const node& a)const{
		if(val==a.val)return ip>a.ip;
		return val>a.val;
	}
}tree[10];
class cmp{
	public:
	 bool operator()(const node & a,const node & b)const{
		 return a<b;
	 }
};
int main()
{
#ifndef ONLINE_JUDGE
//freopen("0.in","r",stdin);
  //  freopen("B-small-attempt2.in","r",stdin);
  //  freopen("out.txt","w",stdout);
#endif
	int T,CASE=1;
	cin>>T;
	int num[10];
	while(T--){
		int n,b;
		cin>>b>>n;
		
		int i;
		int minnum=1;
		int cnt=0;
		priority_queue<node,vector<node>,cmp>Q;
		rep(i,b){
			cin>>num[i];
			minnum*=num[i];

			node a;
			a.val=0,a.ip=i;
			
			Q.push(a);
		}
		rep(i,b){
			cnt+=(minnum/num[i]);
		}
		n=n%cnt;
		if(n==0)n=cnt;
	//	n-=b;
		n--;
	//	cout<<minnum<<":"<<cnt<<endl;
		while(n--){
		    node a=Q.top();
		//	cout<<a.ip+1<<endl;
			a.val=a.val+num[a.ip];
			Q.pop();
			Q.push(a);
		}
		printf("Case #%d: %d\n",CASE++,Q.top().ip+1);
	}
    return 0;
}
