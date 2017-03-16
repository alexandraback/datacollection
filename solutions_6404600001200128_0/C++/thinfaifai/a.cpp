#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,a[1005];

int main() {
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++) {
		scanf("%d",&n);
		for (int i=0; i<n; i++)
			scanf("%d",&a[i]);
		int ret1 = 0,mx = 0;
		for (int i=0; i<n-1; i++) {
			if (a[i] > a[i+1]) ret1 += a[i]-a[i+1];
			mx = max(a[i]-a[i+1],mx);
		}
		int ret2 = 0;
		for (int i=0; i<n-1; i++) {
			ret2 += min(mx,a[i]);
		}
		printf("Case #%d: %d %d\n",t,ret1,ret2);
	}
    return 0;
}
