#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N,M,a[1005];

void init()
{
	scanf("%d%d",&N,&M);
	for (int i=1; i<=N; i++) scanf("%d",&a[i]);
}

ll calc(ll x)
{
	ll s=0;
	for (int i=1; i<=N; i++) s+=x/a[i]+1;
	return s;
}

void doit()
{
	ll l=0,r=1e18;
	for (;l<=r;)
	{
		ll mi=(l+r)>>1;
		if (calc(mi)>=M) r=mi-1; else l=mi+1;
	}
	M-=calc(l-1);
	for (int i=1; i<=N; i++) if (l%a[i]==0)
	{
		M--;
		if (!M) {printf("%d\n",i); return;}
	}
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1; i<=T; i++)
	{
		init();
		printf("Case #%d: ",i);
		doit();
	}
	return 0;
}
/*
3 12
7 7 7

3
2 4
10 5
3 12
7 7 7
3 8
4 2 1
*/
