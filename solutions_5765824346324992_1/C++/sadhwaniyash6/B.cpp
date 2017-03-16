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
#define BC 1000010

ll MC=mod;

ll M[MAXN];

ll N,B;

ll counts=0,extra;

ll myans=-1;

bool check(ll k){
	//cout<<k<<endl;
	extra=0;
	for(int i=1;i<=B;i++){
		counts+=ceil(k/(double)M[i]);
		if(k%M[i]==0)extra++;
	}
	//cout<<k<<" "<<counts<<" "<<extra<<endl;
	if(counts<N and counts+extra>=N)return true;
	return false;
}

ll bin(ll start,ll end){
	//if(start>end)return 1;
	ll mid=(start+end)/2;
	counts=0;
	//cout<<start<<" "<<end<<endl;
	if(check(mid))return mid;
	if(counts+extra>=N)return bin(start,mid-1);
	else return bin(mid+1,end);
}

inline void ReadInput(void){
	sl(B); sl(N);
	for(int i=1;i<=B;i++)sl(M[i]);
}

inline void solve(int turn){
	if(N<=B){
		cout<<"Case #"<<turn<<": "<<N<<endl;
		return;
	}
	ll timer=bin(0LL,MC*BC);
	//cout<<timer<<endl;
	ll my=0;
	for(int i=1;i<=B;i++){
		if(timer%M[i]==0)my++;
		if(my+counts==N){
			cout<<"Case #"<<turn<<": "<<i<<endl;
			return;
		}
	}
}

inline void Refresh(void){

}

int main()
{
	int t; si(t);
	for(int i=1;i<=t;i++){
		ReadInput();
		solve(i);
	}
	return 0;
}
