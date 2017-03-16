#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>
#define fi first
#define se second
#define PA pair<int,int>
#define VI vector<int>
#define VP vector<PA >
#define mk(x,y) make_pair(x,y)
#define N 1010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,te,T;
int a[N],an1,an2;
int main() {
	freopen("1a.in","r",stdin);
	freopen("1a.out","w",stdout);
	scanf("%d",&T);
	For(te,1,T) {
		scanf("%d",&n);
		For(i,1,n) scanf("%d",&a[i]);
		an1=0;
		For(i,1,n-1) an1+=max(a[i]-a[i+1],0);
		an2=0;
		int ci=0;
		For(i,1,n-1) {
			int A=a[i]-a[i+1];
			ci=max(ci,A);
		}
		For(i,1,n-1) an2+=min(a[i],ci);
		printf("Case #%d: %d %d\n",te,an1,an2);
	}
	return 0;
}
