#include <cstdio>
#include <vector>
#include <algorithm>

#define FO(i,a,b) for (long long i = a; i < b; i++)
#define sz(v) (long long)(v.size())

using namespace std;

long long array[1005];

int main() {
	freopen("mush.in","r",stdin);
	freopen("mush.out","w",stdout);
	long long t;
	scanf("%lld\n",&t);
	FO(_,0,t) {
		printf("Case #%lld: ",_+1);
		long long n;
		scanf("%lld\n",&n);
		FO(i,0,n) {
			scanf("%lld ",&array[i]);
		}
		long long ans=0;
		FO(i,0,n-1) {
			ans+=max(0ll,array[i]-array[i+1]);
		}
		long long big=-1;
		printf("%lld ",ans);
		FO(i,0,n-1) {
			big=max(big,array[i]-array[i+1]);
		}
		if (big==-1) {
			printf("0\n");
			continue;
		}
		ans = 0;
		FO(i,0,n-1) {
			ans+=min(array[i],big);
		}
		printf("%lld\n",ans);
	}
	return 0;
}


