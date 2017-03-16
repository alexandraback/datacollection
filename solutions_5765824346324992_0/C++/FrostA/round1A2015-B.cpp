// #include <bits/stdc++.h>
#include "iostream"
#include "cstdio"
#include "algorithm"
#include "math.h"
#include "queue"
#include "map"
#include "set"
#include "stack"
#include "fstream"
#include "cstring"
#include "string"
#define L(x) (x<<1+1)
#define R(x) (x<<1+2)
#define REP(a,b) for(int a=0;a<b;a++)
#define REP1(a,b) for(int a=1;a<=b;a++)
#define RREP(a,b) for(int a=b-1;a>=0;a--)
#define RREP1(a,b) for(int a=b;a>0;a--)
#define ITR(a,b) for(;a!=b;a++)
using namespace std;
#define P 1000000007LL
#define MAXN 100
#define E7 10000000LL
typedef long long ll;

int m[100010];
int b;
ll n;
int main(){
	int T;
	cin>>T;
	REP1(cases, T){
		cin>>b>>n;
		REP(i,b)cin>>m[i];
		ll l=0, r= 100000000000000LL;
		ll mid;
		while(l+1<r){
			mid = (l+r)/2;
			ll count=0;
			REP(i,b)count+=mid/m[i];
			if(count+b>=n)r=mid;
			else l=mid;
		}
		mid=r;
		ll count=0;
		REP(i,b)count+=l/m[i];
		if(count+b>=n)mid=l;

		count=0;
		REP(i,b)count+=(mid-1)/m[i];
		count+=b;

		int ans=1;
		REP(i,b)
			if(mid%m[i]==0){count++;if(n==count){ans=i+1;break;}}

		cout<<"Case #"<<cases<<": "<<ans<<endl;
		// cout<<"Case #"<<cases<<": "<<mid<<endl;
	}
	return 0;
}
