#include<bits/stdc++.h>
#define int64 long long
#define sqr(x) (x)*(x)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define VI vector<int>
#define VI64 vector<int64>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define SZ(x) ((int)(x).size())
#define N 12000
using namespace std;
const double pi=acos(-1);
struct point{
	int x,y;
}p[N];
int ans[N],T,tim,n,id[N];
double v[N];
int det(point &a,point &b,point &c,point &d){
	return (b.x-a.x)*(d.y-c.y)-(b.y-a.y)*(d.x-c.x);
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d%d",&p[i].x,&p[i].y);
		rep(i,1,n)ans[i]=1e9;
		rep(i,1,n){
			int tot=0;
			rep(j,1,n)if(j!=i)id[++tot]=j;
			sort(id+1,id+tot+1,[&](const int x,const int y){
				double t1=atan2(p[x].y-p[i].y,p[x].x-p[i].x),
					   t2=atan2(p[y].y-p[i].y,p[y].x-p[i].x);
				return t1<t2;
			});
			rep(j,1,tot){
				v[j]=atan2(p[id[j]].y-p[i].y,p[id[j]].x-p[i].x);
				v[j+tot]=v[j]+2*pi;
				id[j+tot]=id[j];
			}
			int k=1;
			rep(j,1,tot){
				while(v[k]<v[j]+pi-1e-9)k++;
				ans[i]=min(ans[i],k-j-1);
				ans[id[j]]=min(ans[id[j]],k-j-1);
			}
		}
		printf("Case #%d:\n",++tim);
		if(n==1){
			ans[1]=0;
		}
		rep(i,1,n)printf("%d\n",ans[i]);
	}
}

