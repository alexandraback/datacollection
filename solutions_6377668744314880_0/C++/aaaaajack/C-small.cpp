#include<cstdio>
#include<algorithm>
#define N 20
using namespace std;
struct point{
	long long x;
	long long y;
	int id;
	bool operator<(point rhs)const{return x<rhs.x||x==rhs.x&&y<rhs.y;}
	bool operator==(point rhs)const{return x==rhs.x&&y==rhs.y;} 
}p[N];
int ans[N];
point conv[N];
int sp;
bool check(point a,point b,point c){
	return (b.x-a.x)*(c.y-a.y)>=(b.y-a.y)*(c.x-a.x);
}
int main(){
	int T,cs,n,cnt,i,j;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			p[i].id=i;
			scanf("%lld%lld",&p[i].x,&p[i].y);
			ans[i]=n-1;
		}
		sort(p,p+n);
		for(i=0;i<(1<<n);i++){
			cnt=n;
			for(j=0;j<n;j++){
				if(i&(1<<j)) cnt--;
			}
			sp=0;
			for(j=0;j<n;j++){
				if(!(i&(1<<p[j].id))) continue;
				while(sp>=2&&!check(conv[sp-2],conv[sp-1],p[j])) sp--;
				conv[sp++]=p[j];
			}
			for(j=n-2;j>=0;j--){
				if(!(i&(1<<p[j].id))) continue;
				while(sp>=2&&!check(conv[sp-2],conv[sp-1],p[j])) sp--;
				conv[sp++]=p[j];
			}
			for(j=0;j<sp-1;j++){
				ans[conv[j].id]=min(ans[conv[j].id],cnt);
			}
		}
		printf("Case #%d:\n",cs);
		for(i=0;i<n;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}