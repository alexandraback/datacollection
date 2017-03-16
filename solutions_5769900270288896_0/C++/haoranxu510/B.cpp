#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

void lemon()
{
	int r,c,n; scanf("%d%d%d",&r,&c,&n);
	int wa=(r-1)*c+r*(c-1);
	if (r>c) swap(r,c);
	int z=(r*c)/2; if (r*c%2==1) z++;
	if (n<=z) { printf("0\n"); return; }
	if (r==1) 
	{
		n-=z;
		if (c%2==0) printf("%d\n",n*2-1); else printf("%d\n",n*2);
		return;
	}
	int m=r*c-n;
	int x=(r-2)*(c-2)/2; if ((r-2)*(c-2)%2==1) x++;
	if (m<=x)
	{
		printf("%d\n",wa-4*m); return;
	}
	if ((r-2)*(c-2)%2==1)
	{
		int k=(r/2-1)*2+(c/2-1)*2;
		int w1=4*x+min(k,m-x)*3;
		if (m-x>k) w1+=(m-x-k)*2;
				
		int w2=4*(x-1)+3*(m-(x-1));
		printf("%d\n",wa-max(w1,w2)); return;
	}
	else
	{
		int k;
		if (r%2==0 && c%2==0) 
			k=(r/2-1)*2+(c/2-1)*2;
		else  if (r%2==0)
				k=(r/2-1)*2+(c-2);
			else  k=(c/2-1)*2+(r-2);
		int w=4*x+min(k,m-x)*3;
		if (m-x>k) w+=(m-x-k)*2;
		printf("%d\n",wa-w); return;
	}
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("B.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase) 
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}

