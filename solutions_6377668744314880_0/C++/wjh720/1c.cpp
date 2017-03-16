#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>
#include <cmath>
#define fi first
#define se second
#define PA pair<int,int>
#define VI vector<int>
#define VP vector<PA >
#define mk(x,y) make_pair(x,y)
#define N 6010
#define db double
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
	db x,y,z;
	void read() {
		scanf("%lf%lf",&x,&y);
	}
	ww operator - (const ww &A) {
		return (ww){x-A.x,y-A.y};
	}
	db operator * (const ww &A) {
		return x*A.y-y*A.x;
	}
} a[N],b[N];
int i,j,k,n,m,te,T;
int an[N];
inline bool cc1(const ww &a,const ww &b) {
	return a.z<b.z;
}
int main() {
	freopen("1c.in","r",stdin);
	freopen("1c.out","w",stdout);
	scanf("%d",&T);
	For(te,1,T) {
		scanf("%d",&n);
		For(i,1,n) a[i].read(),an[i]=n;
		For(i,1,n) {
			For(j,1,n) b[j]=a[j];
			swap(b[1],b[i]);
			For(j,2,n) b[j]=b[j]-b[1],b[j].z=atan2(b[j].y,b[j].x);
			sort(b+2,b+n+1,cc1);
			int t=n;
			For(j,2,n) b[++t]=b[j];
			k=2;
			For(j,2,t) {
				for (;k<j&&b[k]*b[j]<=0;k++);
				if (j>n) an[i]=min(an[i],j-k);
			}
			if (n==1) an[i]=0;
		}
		printf("Case #%d:\n",te);
		For(i,1,n) printf("%d\n",an[i]);
	}
	return 0;
}
