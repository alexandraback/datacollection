// Author : Ankit Bisla
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define 	SZ(A) 		((int)A.size())
#define 	LEN(A) 		((int)A.length())
#define 	MS(A) 		memset(A, 0, sizeof(A))
#define 	MSV(A,a) 	memset(A, a, sizeof(A))
#define 	mp(x,y)		make_pair((x),(y))
#define 	pb(x) 		push_back(x)
#define		F 		first
#define 	S 		second
#define 	INF 		(int(1e9))
#define 	INFL 		(ll(1e18))
#define 	EPS 		1e-12
 
#define 	chkbit(s, b) 	(s & (1<<b))
#define 	setbit(s, b) 	(s |= (1<<b))
#define 	clrbit(s, b) 	(s &= ~(1<<b))
 
#define 	swap(x,y)  	{x=x+y-(y=x);}
#define 	FOUND(A, x) 	(A.find(x) != A.end())
 
#define 	s(x) 		scanf("%d",&x);
#define 	s2(x,y) 	scanf("%d%d",&x,&y);
#define 	sl(x) 		scanf("%lld",&x);
#define 	sl2(x,y) 	scanf("%lld%lld",&x,&y);
#define 	p(x) 		printf("%d\n",x);
#define 	pl(x) 		printf("%lld\n",x);

#define 	REP(i, n) 	for(i = 0; i < (n); i++)
#define 	FOR(i, a, n) 	for(i = a; i < n; i++)
#define 	REV(i, a, n) 	for(i = a; i >= n; i--)
#define 	FORALL(itr, c) 	for(itr = (c).begin(); itr != (c).end(); itr++)
#define 	ALL(A) 		A.begin(), A.end()
#define 	LLA(A) 		A.rbegin(), A.rend()
#define 	print(a,n)	REP(int i = 0; i < (n) ; i++)	pl(a[i]);
 
#define 	MOD	        1000000007
 
 
#define 	DEBUG 		1
#define 	TRACE 		1
 
#ifdef TRACE
    #define trace(x)            cerr<<x<<endl;
    #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
    #define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
    #define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
    #define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;
#else
    #define trace(x)
    #define trace1(x)
    #define trace2(x,y)
    #define trace3(x,y,z)
    #define trace4(a,b,c,d)
    #define trace5(a,b,c,d,e)
    #define trace6(a,b,c,d,e,f)
#endif
 
typedef long long ll;
typedef unsigned long long llu;
 
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef vector<bool> VB;

#define N	1010

typedef pair<ll, ll> P;

ll a[N];

ll gcd(ll a,ll b){
      return b==0?a:gcd(b,a%b);
}

ll lcm(ll a,ll b){      
      return (a/gcd(a,b))*b;
}

int main(){
	ll T,B,n,i;
	//#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	//#endif
	scanf("%lld",&T);
	for( ll qq = 1 ; qq <= T ; qq++ ){
	
		priority_queue< P, vector<P>, greater<P> > Q;
		
		scanf("%lld%lld",&B,&n);
		REP(i,B){
			scanf("%lld",&a[i]);
		}
		ll g = a[0];
		FOR(i,1,B){
			g = lcm(a[i],g);
		}
		
		ll co = 0;
		
		REP(i,B){
			co += (g/a[i]);
		}
		
		ll x = n/co;
		ll rem = n - (x*co);
		
		
		if(rem == 0){
			x--;
			rem = n - (x*co);
		}
		
		//trace1(rem);
		
		REP(i,B){
			Q.push( pair<ll,ll>(0,i+1) );
		}
		
		ll ans,first,seco;
		while(rem){
			P pp = Q.top();
			Q.pop();
			first = pp.F;
			seco = pp.S;
			//trace2(first,seco);
			Q.push( pair<ll,ll>(first+a[seco-1],seco) );
			rem--;
		}
		ans = seco;
		printf("Case #%lld: %lld\n",qq,ans);
	}
	return 0;
}       
