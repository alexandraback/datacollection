#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000];
int n,rat,ans1,ans2;

int main() {
	int t,tt,i;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%d",&n);
		for (i=0;i<n;i++) scanf("%d",&a[i]);
		ans1=ans2=rat=0;
		for (i=1;i<n;i++) {
			if (a[i-1]>a[i]) {
				ans1+=a[i-1]-a[i];
				rat=max(rat,a[i-1]-a[i]);
			}
		}
		for (i=0;i<n-1;i++) {
			ans2+=min(rat,a[i]);
		}
		printf("Case #%d: %d %d\n",tt,ans1,ans2);
	}
	return 0;
}
