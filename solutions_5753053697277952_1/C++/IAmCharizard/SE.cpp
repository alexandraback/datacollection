#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define For(i,a,b) for(int i=a-1;i>=b;i--)
#define rep(i,b) FOR(i,0,b)
#define Rep(i,b) For(i,a,0)
#define SORT(x) sort(x.begin(),x.end());
#define ERASE(x) x.erase(x.begin(),x.end());
#define FILL(x,i) memset(x,i,sizeof(x));
#define K 1000000007
#define L 400
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
#define EPS 0.000001
#define MAX 1

typedef long long int ll;

bool cmp(ll a,ll b){if(a>b) return true; return false;}

ll powr(int s,int p)
{
	if(p==0)
		return 1;	
 
	if(p%2==1)
	{
		ll q=powr(s,p/2);
		ll a=q;
		q=(a*a);
		q=(q*s);	
		return ( q );
	}
 
	else
	{
		ll q=powr(s,p/2);
		ll a=q;
		q=(a*a);	
		return (q);
	}
}
/*******************************MAIN CODE STARTS*******************************/

ll n,a[26],s;

bool  check()
{
	FOR(i,0,n)
	{
		if(a[i]*2 > (s-1))
			return false;
	}
	return true;
}

int main()
{
	int t=1;
	s1(t)
	FOR(i,1,t+1)
	{
		printf("Case #%d: ",i);
		s2(n)
		s=0;
		FOR(i,0,n)
		{
			s2(a[i])
			s+=a[i];
		}
		while(s)
		{
			bool flag = false;
			FOR(i,0,n)
			{
				if(a[i])
				{
					a[i]-=1;
					if(check())
					{
						cout<<char('A'+i)<<' ';
						flag=true;
						break;
					}
					a[i]+=1;
				}
			}
			if(!flag)
			{
				int c=0;
				FOR(i,0,n)
				{
					if(a[i])
					{
						cout<<char('A'+i);
						c++;
						if(c==2)
							break;
					}
				}
				cout<<' ';
				s-=2;
			}
			else
				s-=1;	
		}
		cout<<'\n';	
	}
	return 0;
}
