/*
ID: eggylv999
LANG: C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

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

int stamps[20000];

int main()
{
	int T;
	int ntests;
	si(ntests);
	fli(T,1,ntests+1)
	{
		int nstamps;
		si(nstamps);
		int ans1=0;
		int maxshr=0;
		int i;
		fli(i,0,nstamps)
		{
			si(stamps[i]);
			if(i>0&&stamps[i-1]>stamps[i])
			{
				ans1+=stamps[i-1]-stamps[i];
				maxshr=max(maxshr,stamps[i-1]-stamps[i]);
			}

		}
		int ans2=0;
		int j;
		fli(j,1,nstamps)
		{
			ans2+=min(maxshr,stamps[j-1]);
		}
		printf("Case #%d: %d %d\n",T,ans1,ans2);
	}
	exit(0);
}
