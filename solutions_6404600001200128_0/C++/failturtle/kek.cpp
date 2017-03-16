#include <cstdio>
#include <vector>
#include <algorithm>

#define FO(i,a,b) for (int i = a; i < b; i++)
#define sz(v) (int)(v.size())

using namespace std;

int array[1005];

int main() {
	freopen("mush.in","r",stdin);
	freopen("mush.out","w",stdout);
	int t;
	scanf("%d\n",&t);
	FO(_,0,t) {
		printf("Case #%d: ",_+1);
		int n;
		scanf("%d\n",&n);
		FO(i,0,n) {
			scanf("%d ",&array[i]);
		}
		int ans=0;
		FO(i,0,n-1) {
			ans+=max(0,array[i]-array[i+1]);
		}
		int big=-1;
		printf("%d ",ans);
		FO(i,0,n-1) {
			big=max(big,array[i]-array[i+1]);
		}
		if (big==-1) {
			printf("%d\n",0);
			continue;
		}
		ans = 0;
		FO(i,0,n-1) {
			ans+=min(array[i],big);
		}
		printf("%d\n",ans);
	}
	return 0;
}


