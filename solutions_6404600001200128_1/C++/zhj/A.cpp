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
#define N 1200
using namespace std;
const double pi=acos(-1);
int T,n,a[N],tim;
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",&a[i]);
		int ans1=0,ans2=0;
		rep(i,1,n-1)if(a[i]>a[i+1])ans1+=a[i]-a[i+1];
		int maxx=0;
		rep(i,1,n-1)maxx=max(maxx,a[i]-a[i+1]);
		rep(i,1,n-1)ans2+=min(maxx,a[i]);
		printf("Case #%d: %d %d\n",++tim,ans1,ans2);
	}
}
