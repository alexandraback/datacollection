#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int t,n,i,ans1,ans2,sst,tes;
int a[1000007];

int main() {
	scanf("%d",&t);
	for (tes=1 ; tes<=t ; tes++) {
		ans1 = 0;
		ans2 = 0;
		sst = 0;
	
		scanf("%d",&n);
		for (i=1 ; i<=n ; i++) scanf("%d",&a[i]);
		for (i=2 ; i<=n ; i++) if (a[i-1] > a[i]) ans1 += a[i-1] - a[i];
		for (i=2 ; i<=n ; i++) if (a[i-1] > a[i]) sst = max(sst,(a[i-1]-a[i]));
		
		if (sst != 0) {
			for (i=2 ; i<=n ; i++) ans2 += min(a[i-1],sst);
		}
		
		printf("Case #%d: %d %d\n",tes,ans1,ans2);
	}
}
