/*
ID: eggylv999
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#define si(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define popcount __builtin_popcount
#define gcd __gcd
#define fli(i,a,b) for(int i=a;i<b;i++)
#define fld(i,a,b) for(i=a;i>=b;i--)
#define flit(it,c) for(it=c.begin();it<c.end();it++)
#define fldit(it,c) for(it=c.end();it>=c.begin();it--)
#define fill(a,v) memset(a, v, sizeof a)zzz
#define max(a,b) ( (a) > (b) ? (a) : (b))
#define min(a,b) ( (a) < (b) ? (a) : (b))
#define checkbit(n,b) ( (n >> b) & 1)
#define bound(n,a,b) (((n)>=(a))&&((n)<=(b)))
#define fi first
#define se second
#define mp make_pair
#define abS(a) ((a)>0?(a):(-(a)))
using namespace std;

typedef long long ll;

ll barbs[1005];
ll nbarbs;
ll ncust;

ll compute(ll time)
{
	ll res=nbarbs;
	fli(i,0,nbarbs)
		res+=time/barbs[i];
	return res;
}

int main()
{
	int T;
	int ntests;
	si(ntests);
	fli(T,1,ntests+1)
	{
		si(nbarbs);
		si(ncust);
		fli(i,0,nbarbs)
			si(barbs[i]);
		ll lo=0;
		ll hi=1000000000000;
		if(T==5)
			lo=0;
		ll ans;
		while(hi>=lo) //looking for lowest point where the ans is >=ncust, then subtract one
		{
			ll mid=(hi+lo)/2;
			if(compute(mid)==nbarbs)
			{
				ans=mid;
				for (ll i = mid; i >= 0; --i)
				{
					if(compute(ans)!=ncust)
						break;
					ans=i;
				}
				break;
			}
			else if(compute(mid)<ncust)
				lo=mid+1;
			else
				hi=mid-1;
			ans=mid;
		}
		if(compute(ans)<ncust)
			ans++;
		ll prev=compute(ans-1);
		ll next=compute(ans);
		assert(next>prev);
		fli(i,0,nbarbs)
		{
			if(ans/barbs[i]>(ans-1)/barbs[i])
				prev++;
			if(prev==ncust)
			{
				printf("Case #%d: %d\n",T,i+1);
				break;
			}
		}
		
	}
	exit(0);
}
