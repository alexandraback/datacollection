#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define For(i,a,b) for(int i=a-1;i>=b;i--)
#define rep(i,b) FOR(i,0,b)
#define Rep(i,b) For(i,a,0)
#define SORT(x) sort(x.begin(),x.end());
#define FILL(x,i) memset(x,i,sizeof(x));
#define K 1000000007
#define L 100010
#define ll long long
#define s1(a) scanf("%d",&a);
#define s2(a) scanf("%lld",&a);
#define s3(a,b) scanf("%lld%lld",&a,&b);
#define s4(a,b,c) scanf("%lld%lld%lld",&a,&b,&c);
#define pb push_back
#define mp make_pair
#define F first
#define S second 
#define PII pair<int,int>
#define PLL pair<ll,ll>

bool cmp(ll a,ll b){if(a>b) return true; return false;}
/*******************************MAIN CODE STARTS*******************************/

int CaseNo,z,y,m[1010],n;

void scan()
{
	s1(n)
	FOR(i,0,n)
		s1(m[i])
}

void out()
{
	int x=0;
	z=y=0;
	FOR(i,1,n)
	{
		y+=max(0,m[i-1]-m[i]);
		if(m[i-1]>m[i])
			x=max(x,m[i-1]-m[i]);
	}
	//cout<<x<<'\n';
	FOR(i,0,n-1)
		z+=min(x,m[i]);
	printf("Case #%d: %d %d\n",CaseNo,y,z);
}

int main()
{
	int t;
	s1(t)
	while(CaseNo!=t)
	{
		CaseNo++;
		scan();
		out();
	}
	return 0;
}
