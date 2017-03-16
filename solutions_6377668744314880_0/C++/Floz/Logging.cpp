#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define sqr(x) ((x)*(x))
typedef pair<double,double> ii;
#define fi first
#define se second
#define pi acos(-1.0)
ii dec(ii x,ii y){
	return ii(x.fi-y.fi,x.se-y.se);
}
double cross(ii x,ii y){
	return (x.fi*y.se-x.se*y.fi);
}
double dist(ii x){
	return sqr(x.fi)+sqr(x.se);
}
#define maxn 1010
ii a[maxn],c[maxn];
bool cmp(ii x,ii y){
	int m=cross(dec(a[1],x),dec(a[1],y));
	if (m!=0) return m>0;
	return (dist(dec(a[1],x))<dist(dec(a[1],y)));
}
int n,l,q[maxn],r;
int ans[maxn];
bool b[maxn];
int check(int y){
	int N=n;
	int n=0;
	int cnt=0;
	for (int i=1;i<=N;i++) 
		if (b[i]) {
			n++;a[n]=c[i];
		}else cnt++;
	
	if (n<=3) return ans[y]=min(ans[y],cnt);
	sort(a+1,a+1+n);
	l=0;
	for (int i=1;i<=n;i++) {
		while (l>1&&cross(dec(a[q[l-1]],a[q[l]]),dec(a[q[l]],a[i]))<0) l--;
		q[++l]=i;
	}
	for (int i=1;i<=l;i++) 
		if (c[y].fi==a[q[i]].fi&&c[y].se==a[q[i]].se) {
			ans[y]=min(ans[y],cnt);return 0;
		}
	l=0;
	for (int i=1;i<=n;i++) {
		while (l>1&&cross(dec(a[q[l-1]],a[q[l]]),dec(a[q[l]],a[i]))>0) l--;
		q[++l]=i;
	}
	for (int i=1;i<=l;i++) 
		if (c[y].fi==a[q[i]].fi&&c[y].se==a[q[i]].se) {
			ans[y]=min(ans[y],cnt);return 0;
		}
	return 0;
}
int dfs(int x,int y){
	if (x==n+1) return check(y);
	//printf("%d %d\n",x,y);
	b[x]=1;dfs(x+1,y);
	if (x!=y) b[x]=0,dfs(x+1,y);
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int _=1;_<=T;_++) {
		printf("Case #%d:\n",_);
		memset(ans,0x3f,sizeof(ans));
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%lf%lf",&c[i].fi,&c[i].se);
		for (int i=1;i<=n;i++) dfs(1,i);
		for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
