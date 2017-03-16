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

ll v[N];
int n;

void main2()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%lld",v+i);
	ll r1,r2;
	r1 = r2 = 0;
	ll maior = 0;
	for(int i=1;i<n;i++)
	{
		if(v[i]<v[i-1]) r1+=(v[i-1]-v[i]);
		maior = max(v[i-1]-v[i],maior);
	}
	for(int i=0;i<n-1;i++) r2+=min(maior,v[i]);
	printf("%lld %lld\n",r1,r2);
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