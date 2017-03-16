#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};	
//////////////////////

const int N = 1000001;

ll a,b;
ll v[N];

ll test( ll x ) 
{
	ll qtd = 0;
	for(int i=0;i<a;++i) qtd+=(x/v[i]);
	return qtd;
}

void main2()
{
	scanf("%lld %lld",&a,&b);
	for(int i=0;i<a;++i) scanf("%lld",v+i);

	if( a >= b )
	{
		printf("%lld\n",b);
		return;
	}

	b-=a;
	ll lo = 0, hi = 100000000000000000LL;
	while(hi-lo>1)
	{
		ll mid = (lo+hi)>>1;
		if( test(mid) >= b ) hi = mid;
		else lo = mid;
	}
	if( test(hi-1) >= b ) hi--;
	if( test(lo+1) < b ) lo++;

	b-=test(lo);
	for(int i=0;i<a;++i)
	{
		b-=(hi%v[i]==0);
		if( b <= 0 )
		{
			printf("%d\n",i+1);
			return;
		}
	}
}

int main()
{
	//ios::sync_with_stdio(0);
	int t; scanf("%d",&t);
	for(int tt=1;tt<=t;++tt){
		printf("Case #%d: ",tt);
		main2();
	}
	return 0;
}