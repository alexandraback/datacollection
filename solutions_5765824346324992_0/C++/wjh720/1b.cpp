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
#define int64 long long
#define N 1010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,T,te;
int a[N];
inline int64 cal(int64 x) {
	if (x<0) return 0;
	int64 i,an=0;
	For(i,1,n) an+=x/a[i]+1;
	return an;
}
int main() {
	//freopen("1b.in","r",stdin);
//	freopen("1b.out","w",stdout);
	scanf("%d",&T);
	For(te,1,T) {
		scanf("%d%d",&n,&m);
		For(i,1,n) scanf("%d",&a[i]);
		int64 l=0,r=(int64)1e15,mid;
		for (;l<=r;) {
			mid=(l+r)/2;
			if (cal(mid)>=m) r=mid-1;
			else l=mid+1;
		}
		m-=cal(r);
		r++;
		For(i,1,n) if (r%a[i]==0) {
			if (!(--m)) {
				printf("Case #%d: %d\n",te,i);
				break;
			}
		}
	}
	return 0;
}
