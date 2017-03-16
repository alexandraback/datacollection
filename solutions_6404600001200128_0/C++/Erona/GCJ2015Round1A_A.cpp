#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1005;
int a[N];
int main()
{
	freopen("/Users/Erona/Downloads/A-small-attempt0 (1).in","r",stdin);
	freopen("/Users/Erona/Downloads/A-small-attempt0 (1).out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int Cs=1;Cs<=T;Cs++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",a+i);
		int ans1=0;
		int maxd=0;
		for(int i=0;i<n-1;i++)if(a[i]>a[i+1])
		{
			int d=a[i]-a[i+1];
			ans1+=d;
			maxd=max(maxd,d);
		}
		int ans2=0;
		for(int i=0;i<n-1;i++)
		if(a[i]>maxd)ans2+=maxd;
		else ans2+=a[i];
		printf("Case #%d: %d %d\n",Cs,ans1,ans2);
	}
	return 0;
}