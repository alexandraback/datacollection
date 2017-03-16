#include <cstdio>
#include <algorithm>
#define REP(i,n) for (int i=1;i<=n;++i)
using namespace std;

int T,n,ans1,ans2,big,now;
int a[10010];

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	REP(T_T,T) {
		scanf("%d",&n);
		REP(i,n) scanf("%d",&a[i]);
		ans1=ans2=0; big=now=0;
		REP(i,n-1)
			if (a[i]>a[i+1]) {
				ans1+=a[i]-a[i+1];
				big=max(big,a[i]-a[i+1]);
			}
		REP(i,n-1)
			ans2+=min(a[i],big);
		printf("Case #%d: %d %d\n",T_T,ans1,ans2);
	}
	return 0;
}