#include <stdio.h>
#include <string.h>
using namespace std;
int a[1010];
int main(int argc, char const *argv[])
{
	int t,n;
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		printf("Case #%d:",TT );
		int ans=0;
		for (int i=0;i<n-1;i++) if (a[i]>a[i+1]) ans=ans+a[i]-a[i+1];
		printf(" %d",ans);
		int MAX=0;
		ans=0;
		for (int i=0;i<n-1;i++) if (a[i]>a[i+1]&&a[i]-a[i+1]>MAX) MAX=a[i]-a[i+1];
		for (int i=0;i<n-1;i++) if (a[i]<MAX) ans+=a[i]; else ans+=MAX;
		printf(" %d\n", ans);
	}
	return 0;
}