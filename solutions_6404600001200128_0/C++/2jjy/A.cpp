#include <iostream> 
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert> 
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);++i)
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
int n,ind[1001];
int maxdelta;
int tot1,tot2;
void task()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&ind[i]);
	maxdelta=0;
	tot1=tot2=0;
	rep(i,n-1)maxdelta=max(maxdelta,ind[i]-ind[i+1]);
	rep(i,n-1)
	{
		tot1+=max(0,ind[i]-ind[i+1]);
		tot2+=min(ind[i],maxdelta);
	}
	printf("%d %d\n",tot1,tot2);
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int nt;scanf("%d",&nt);
	rep(i,nt)
	{
		printf("Case #%d: ",i);
		task();
	}
}
