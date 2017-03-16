#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long t,n,i,tes,ans,base,mid,top,tmp,k;
long long a[1007];

int main() {
	scanf("%lld",&t);
	for (tes=1 ; tes<=t ; tes++) {
		scanf("%lld%lld",&n,&k);
		for (i=1 ; i<=n ; i++) scanf("%lld",&a[i]);
		
		if (k <= n) ans = k; else {
			base = 0;
			top = 1000000000000000000LL;
		
			while (base != top) {
				mid = (base + top) / 2 + 1;
				
				tmp = 0;
				for (i=1 ; i<=n ; i++) {
					tmp += (mid + a[i] - 1) / a[i];
				}
				
				if (tmp >= k) top = mid - 1; else base = mid;
			}
		
			//printf("TOP : %lld\n",top);
			
			tmp = 0;
			for (i=1 ; i<=n ; i++) {
				tmp += (top + a[i] - 1) / a[i];
			}
			
			for (i=1 ; i<=n ; i++) if (top % a[i] == 0) {
				tmp++;
				if (tmp == k) {
					ans = i;
					i = n + 1;
				}
			}
		}
		
		printf("Case #%lld: %lld\n",tes,ans);
	}
}
