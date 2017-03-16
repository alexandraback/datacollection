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

int a[T];
int main()
{
	int test,n,f,s,caso=0,mx;
	scanf("%d",&test);
	while(test--)
	{
		f = 0;
		s = 0;
		scanf("%d",&n);
		fore(i,0,n)
			scanf("%d",&a[i]);
		fore(i,1,n)
			if(a[i-1]>a[i])
				f+=a[i-1]-a[i];
		mx = 0;
		fore(i,1,n)
			if(a[i-1]>a[i])
				mx = max(mx,abs(a[i]-a[i-1]));
			
		fore(i,0,n-1)
			if(mx>=a[i])
				s+=a[i];
			else
				s+=mx;
		
		
		
		printf("Case #%d: %d %d\n",++caso,f,s);
	}
}	


