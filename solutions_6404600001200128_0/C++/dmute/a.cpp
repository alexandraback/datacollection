#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100005;
int a[maxn], tst,n;
int main()  {
	scanf("%d", &tst);
	for (int t=1;t<=tst;t++)  {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d", &a[i]);
		int sum1=0;
		for (int i=1;i<n;i++)
			if (a[i]>a[i+1]) sum1+=a[i]-a[i+1];
		int sum2=0, x=0;
		for (int i=1;i<n;i++)
			x=max(x, a[i]-a[i+1]);
		for (int i=1;i<n;i++)
			sum2+=min(a[i], x);
		printf("Case #%d: %d %d\n",t, sum1, sum2);
	}
	return 0;
}