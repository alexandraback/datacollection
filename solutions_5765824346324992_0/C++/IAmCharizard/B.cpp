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

ll n,b,m[10010],CaseNo,mn,ans;

ll f(ll no)
{
	//cout<<no<<'\n';
	ll mx=0,y=0;
	FOR(i,0,b)
	{
		y+=(no/m[i])+1;
		mx=max(mx,m[i]*(no/m[i]));
	}
	ll p=0;
	FOR(i,0,b)
	{
		if(mx%m[i]==0)
			++p;
	}
	//cout<<y<<'\n';
	if(n>=(y-p+1) && n<=y)
	{
		//cout<<no<<'\n';
		ll r=0;
		FOR(i,0,b)
		{
			if(mx%m[i]==0)
			{
				++r;
				if(r+y-p==n)
				{
					ans=i+1;
					return n;
				}
			}
		}
	}
	if(n>y)
		return y;
	return (y-p+1);
}

void search(ll low,ll high)
{
	if(low>high)
	{
		//cout<<low<<'\n';
		//return;
	}
	ll mid=(low+high)/2;
	ll u=f(mid);
	//cout<<high<<'\n';
	if(u>n)
		search(low,mid-1);
	else if(u<n)
		search(mid+1,high);
	return;
}

void scan()
{
	mn=L;
	s3(b,n)
	FOR(i,0,b)
	{
		s2(m[i])
		mn=min(mn,m[i]);
	}
}

void out()
{
	if(n<=b)
		ans=b;
	else
		search(0,mn*n);
	printf("Case #%lld: %lld\n",CaseNo,ans);
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
