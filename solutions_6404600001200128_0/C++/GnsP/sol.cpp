// Author : Ganesh Prasad Sahoo (sir.gnsp@gmail.com)
// Date : 11 Apr 2015
/**
  * This file is a submission for Google Code Jam  programming contest.
  * Author :  Ganesh Prasad Sahoo <sir.gnsp@gmail.com>
  * 
  * This file and/or the source code contained within can not be
  * copied and/or distributed for competitive purposes in any
  * condition. However the codes can be used for pure educational
  * purposes with the permission of the Author.
***/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <stack>
#include <utility>
using namespace std;

#define s(n) 	scanf("%d",&n)
#define sl(n) 	scanf("%lld",&n)
#define p(n) 	printf("%d ",n)
#define pl(n)	printf("%lld",n)
#define sf(n) 	scanf("%f",&n)
#define sd(n) 	scanf("%lf",&n)
#define ss(n) 	scanf("%s",n)
#define pf(n) 	printf("%f ",n)
#define pd(n) 	printf("%lf ",n)
#define ps(n) 	printf("%s ",n)
#define nl		putchar('\n')
#define e1		first
#define e2		second

#define INF		(int)1e9
#define MOD		(int)(1e9+7)
#define LINF	(ll)1e18
#define EPS		1e-11
const double PI = acos(-1.0)

#define pow2(n) (1<<(n))
#define pow2l(n) ((ll)1<<(n))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(n)   ((a)<0?-(a):(a))
#define MAXE(...)	max_element(__VA_ARGS__)

#define FOR(i,a,b)	for(int i=a;i<b;i++)
#define RNG(i,n)	FOR(i,0,n)
#define REV(i,a,b)	for(int i=a;i>=b;--i)
#define FORECH(v,c)	for(typeof((c).begin()) v=(c).begin(); v!=(c).end(); ++v)
#define ALL(a)		(a).begin(),(a).end()
#define LEN(a)		((int)(a.size()))
#define PB(x)		push_back(x)
#define TIMES(x)	while((x)--)
#define UPB			upper_bound
#define LWB			lower_bound
#define MP			make_pair

#ifndef ONLINE_JUDGE
#define DEBUG__
#endif
#ifdef DEBUG__
	#define derr(x) 	cerr<<"<"<<#x<<": "<<x<<">"<<endl
	#define _DEBUG(...) __VA_ARGS__
	;template<typename T> void debug(T a, T b){ for(;a!=b;++a) cerr<<*a<<" "; cerr<<endl; }
#else
	#define derr(...)
	#define _DEBUG(...)
	;template<typename T> void debug(T a, T b){}
#endif

typedef long long 		ll;
typedef pair<int, int> 	pii;
typedef pair<ll, ll> 	pll; 
typedef vector<int> vi;
typedef vector<ll> 	vl;
typedef vector<vi> 	vvi;
typedef vector<vl>	vvl;
typedef list<int>	li;
typedef map<int,int> mii;

template<typename T> T modPow(T b, T e, T m=(ll)MOD){T res=1;while(e){if(!(e&0x1))res=(res*b)%m;e>>=1;b=(b*b)%m;}return res; }
template<typename T> T gcd (T u, T v){ return (u==0||v==0||u==v)?(u|v):((~u&1)?((v&1)?gcd(u>>1,v):gcd(u>>1,v>>1)<<1):((~v&1)?gcd(u,v>>1):((u>v)?gcd((u-v)>>1,v):gcd((v-u)>>1,u)))); }
template<typename T> T lcm (T a, T b){ return a*b/gcd(a,b); }
//#undef DEBUG__
//***************************************************************************************************
//***************************************************************************************************

int arr[1005];
int diff[1005];

int main(){
	int T,t;
	s(T);
	RNG(tc, T){
		int N,a=0,b=0;
		s(N);
		RNG(i, N){
			s(t);
			arr[i]=t;
			if(i>0 && arr[i]<arr[i-1]) a+=arr[i-1]-arr[i];
			if(i>0) diff[i-1] = arr[i-1]-arr[i];
		}
		int mx = (int)*MAXE(diff, diff+N-1);
		RNG(i, N-1){
			if(arr[i]>=mx) b+=mx;
			else b+=arr[i];
		}
		printf("Case #%d: %d %d\n",tc+1, a, b);
	}
	return 0;
}
