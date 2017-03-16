#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=1;i<=n;++i)
typedef long long LL;
int T,Case,n=4,r[3],a[3][5][5];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		rep(k,2){
			scanf("%d",r+k);
			rep(i,n) rep(j,n) scanf("%d",&a[k][i][j]);
		}
		int x=0;
		rep(i,4) rep(j,4) if (a[1][r[1]][i]==a[2][r[2]][j]) x=x*17+a[1][r[1]][i];
		printf("Case #%d: ",++Case);
		if (!x) puts("Volunteer cheated!"); else if (x<=16) printf("%d\n",x); else puts("Bad magician!");
	}
	return 0;
}

