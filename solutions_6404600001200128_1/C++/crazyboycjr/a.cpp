#include <cstdio>
#include <cstring>

using namespace std;
#define rep(i,l,r) for (int i=(l);i<=(r);i++)

const int maxn=1040;
int n,a[maxn];

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;scanf("%d\n",&T);
	rep(t,1,T) {
		printf("Case #%d: ",t);
		scanf("%d\n",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		int ans1=0;
		rep(i,1,n-1) {
			if (a[i]>a[i+1])
				ans1+=a[i]-a[i+1];
		}
		printf("%d ",ans1);
		int ma=0;
		rep(i,1,n-1) {
			if (a[i]>a[i+1])
				if (ma<a[i]-a[i+1])
					ma=a[i]-a[i+1];
		}
		int ans2=0,now=0;
		rep(i,1,n-1) {
			if (now<a[i]) now=a[i];
			if (ma>now) {
				ans2+=now;
				now=0;
			}
			else {
				ans2+=ma;
				now-=ma;
			}
		}
		printf("%d\n",ans2);
	}
	return 0;
}
