#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef double db;
int n;
int a[1111];
int main()
{
	freopen("bs.in","r",stdin);
	freopen("bs.out","w",stdout);
	int tes;scanf("%d",&tes);
	for (int tt=1;tt<=tes;tt++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		int su1=0;
		int ma=0;
		for (int i=1;i<=n-1;i++)if(a[i]>a[i+1])su1+=a[i]-a[i+1],ma=max(ma,a[i]-a[i+1]);
		int su2=0;
		for (int i=1;i<=n-1;i++)su2+=min(a[i],ma);
		printf("Case #%d: %d %d\n",tt,su1,su2);
	}
	return 0;
}



		



