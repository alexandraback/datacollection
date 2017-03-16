#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <climits>
#include <utility>
#include <map>
#include <sstream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>
#include <bitset>
#define fore(i,m,n) \
for(int i=m;i<n;i++)
#define fori(i,m,n) \
for(int i=m;i<=n;i++)
#define T 100005
#define M 100005
using namespace std;

int a[T],n,b;
int gdc(int a,int b)
{
	return b==0 ? a : gdc(b,a%b);
}
int lcm(int a,int b)
{
	return a* (b/gdc(a,b));
}
int which(int m,int r)
{
	while(r)
	{
		fore(i,0,b)
		{
			if(!(r%a[i]))
				m--;
			if(!m)
				return i+1;
		}
		r--;
	}
}
int main()
{
	int test,mcm,cant,caso=0,res,mx=0;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&b,&n);
		fore(i,0,b)
			scanf("%d",&a[i]);
		mcm = 1;
		
		fore(i,0,b)
			mcm = lcm(mcm,a[i]);
		
		cant = 0;
		fore(i,0,b)
			cant+=mcm/a[i];
		
		if(n%cant!=0)
			res = which(n%cant,mcm);
		else
		{
			res = which(cant,mcm);
		}
		
		printf("Case #%d: %d\n",++caso,res);
		mx = max(mx,mcm);
	}
}	


