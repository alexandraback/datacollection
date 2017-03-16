#include <bits/stdc++.h>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define Afridi 0
#define NL printf("\n")
#define debug(x) printf("wow  %d !!\n",x)
#define Max 1000000
#define INF INT_MAX
#define mod 1000000007
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

LL bigmod(LL b,LL p)
{
    if(p == 0)return 1;
    LL my = bigmod(b,p/2);
    my*=my;my%=mod;
    if(p & 1)my*=b,my%=mod;
    return my;
}
int setb(int n,int pos){return n=n | (1 << pos);}
int resb(int n,int pos){return n=n & ~(1 << pos);}
bool checkb(int n,int pos){return (bool)(n & (1 << pos));}

int ara[100],n;
char lol[100];

int main()
{
	//FI;
	freopen("A-large.in","r",stdin);
	freopen("Alarge.out","w",stdout);

	int t,T,i,j;
	si(T);
	rep(t,T)
	{
		si(n);
		int tot = 0;
		Rep(i,n)si(ara[i]) , tot += ara[i];
		printf("Case #%d:",t);
		while(tot)
		{
			int k = 0;
			int mx,idx;
			mx = 0;
			Rep(i,n)
			{
				if( ara[i] > mx)
				{
					mx = ara[i];
					idx = i;
				}
			}
			ara[idx]--;
			lol[k++] = idx + 'A';
			tot--;

			mx = 0;
			Rep(i,n)
			{
				if( ara[i] > mx)
				{
					mx = ara[i];
					idx = i;
				}
			}

			if( ara[idx] * 2 > tot )
			{
				ara[idx]--;
				tot--;
				lol[k++] = idx + 'A';
			}
			lol[k] = 0;
			printf(" %s",lol);
		}
		NL;
	}
    return 0;
}
