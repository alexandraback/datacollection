#include <cstdio>
#include <algorithm>
#define LL long long
#define REP(i,n) for (int i=1;i<=n;++i)
using namespace std;

int T,n;
int x[3030];
int y[3030];
int ans[3030];

inline LL Cj(int x1,int y1,int x2,int y2) {
	return (LL)x1*(LL)y2-(LL)x2*(LL)y1;
}

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	REP(T_T,T) {
		scanf("%d",&n);
		REP(i,n) scanf("%d%d",&x[i],&y[i]);
		REP(i,n) ans[i]=n-1;
		REP(i,n) REP(j,i-1) {
			int tmp0=0,tmp1=0;
			REP(k,n) {
				LL tmp=Cj(x[i]-x[k],y[i]-y[k],x[j]-x[k],y[j]-y[k]);
				if (tmp>0) tmp0++;
				if (tmp<0) tmp1++;
			}
			ans[i]=min(ans[i],min(tmp0,tmp1));
			ans[j]=min(ans[j],min(tmp0,tmp1));
		}
		printf("Case #%d:\n",T_T);
		REP(i,n) printf("%d\n",ans[i]);
	}
	return 0;
}