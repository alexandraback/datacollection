#include <cstdio>
#include <cstring>

using namespace std;
#define rep(i,l,r) for (int i=(l);i<=(r);i++)

typedef long long LL;
const int maxn=1020;

int B,n,a[maxn];
int b[maxn];

int chk(LL tim) {
	LL tmp=0,t2=0;
	rep(i,1,B) {
		tmp+=tim/a[i];
		b[i]=tim%a[i];
		if (b[i]==0) t2++;
		else tmp++;
	}
	if (tmp<n&&tmp+t2>=n) return 1;
	if (tmp>=n) return 2;
	return 0;
}

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;scanf("%d\n",&T);
	rep(t,1,T) {
		printf("Case #%d: ",t);
		scanf("%d%d\n",&B,&n);
		rep(i,1,B) scanf("%d",&a[i]);
		if (n<=B) {
			printf("%d\n",n);
			continue;
		}
		LL l(1),r(200000000000000LL),mid;
		while (l<r-1) {
			mid=(l+r)>>1;
			int tp=chk(mid);
			if (tp==2) r=mid;
			if (tp==0) l=mid;
			if (tp==1) break;
		}
		int ans=0;
		if (chk(mid)==1) {
			LL tmp=0;
			rep(i,1,B) {
				tmp+=mid/a[i];
				if (mid%a[i]==0)
					b[i]=1;
				else tmp++,b[i]=0;
			}
			rep(i,1,B) {
				tmp+=b[i];
				if (tmp>=n) {ans=i;break;}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
