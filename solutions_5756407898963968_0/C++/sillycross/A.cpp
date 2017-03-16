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

int a[5][5], v1[20], v2[20];

void lemon(int nowcase)
{
	int c1; scanf("%d",&c1);
	rep(i,1,4) rep(j,1,4) scanf("%d",&a[i][j]);
	memset(v1,0,sizeof v1);
	rep(i,1,4) v1[a[c1][i]]=1;
	
	scanf("%d",&c1);
	rep(i,1,4) rep(j,1,4) scanf("%d",&a[i][j]);
	memset(v2,0,sizeof v2);
	rep(i,1,4) v2[a[c1][i]]=1;
	
	printf("Case #%d: ",nowcase);
	int ans, ansc=0;
	rep(i,1,16) if (v1[i] && v2[i]) ans=i, ansc++;
	if (ansc==0)
	{
		printf("Volunteer cheated!\n");
	}
	else  if (ansc>1)
	{
		printf("Bad magician!\n");
	}
	else  printf("%d\n",ans);
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("A.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase) lemon(nowcase);
	return 0;
}

