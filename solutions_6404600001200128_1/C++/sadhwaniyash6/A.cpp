/*
***************************************************************************************************************

							Author : Yash Sadhwani

**************************************************************************************************************
*/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stack>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<functional>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mod 1000000007
#define mem(x,y) memset(x,y,sizeof(x))
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define max_int_value 2147483647
#define max_long_value 9223372036854775807


//qsort(ww,cc,sizeof(tp),compare);
/*int compare(const void *a,const void *b){
	ll y=((((tp*)a)->w)-(((tp*)b)->w));
	if(y>0)return 1;
	else if(y==0)return 0;
	else return -1;
}*/


#define MAXN 1010

ll arr[MAXN];

int N;

inline void ReadInput(void){
	si(N);
	for(int i=1;i<=N;i++)sl(arr[i]);
}

inline void solve(int turn){
	ll ansA=0,ansB=0;
	ll maxdiff=0;
	for(int i=2;i<=N;i++){
		ll diff=arr[i-1]-arr[i];
		maxdiff=max(maxdiff,diff);
		if(arr[i]<arr[i-1])ansA+=diff;
	}
	//cout<<maxdiff<<endl;
	//cout<<maxdiff<<endl;
	for(int i=1;i<N;i++){
		ll foo=0;
		foo=min(arr[i],maxdiff);
		//cout<<foo<<" ";
		ansB+=foo;
	}
	//cout<<endl;
	cout<<"Case #"<<turn<<": "<<ansA<<" "<<ansB<<endl;//15 25"
}

inline void Refresh(void){

}

int main()
{
	int t; si(t);
	for(int i=1;i<=t;i++){
		ReadInput();
		solve(i);
		//return 0;
	}
	return 0;
}
