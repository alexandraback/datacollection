#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define st first
#define nd second
#define make(a,b) make_pair(a,b)

typedef pair<int,int> pun;
typedef long long ll;

int tab[N];
int n;
ll klienci(long long x)
{
	//ile klientow zostanie wzietych do obslugi w x-tej minucie
	long long ile = 0;
	for (int i=0;i<n;i++)
		ile += ceil( x / (long double)tab[i] );
	return ile;
}

int jaki(int k,long long x)
{
	for (int i=0;i<n;i++)
		if ( x % tab[i] == 0 )
		{
			k--;
			if ( k == 0 ) return i+1;
		}
}

void test()
{
	int K;
	scanf("%d%d",&n,&K);
	for (int i=0;i<n;i++)
		scanf("%d",tab+i);
	ll p = 1, k = 100LL*1000LL * K;
	while( p < k )
	{
		if ( klienci( (p+k+1)/2 ) < K ) p = (p+k+1)/2;
		else k = (p+k+1)/2-1;
	}
//	printf("%lld\n",p);
	printf("%d\n",jaki(K - klienci(p), p));
}

int main()
{
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		test();
	}
}
