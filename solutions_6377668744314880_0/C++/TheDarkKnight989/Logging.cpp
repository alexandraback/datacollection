#include<stdio.h>
#include<string.h>
#define NM 25
#include<map>
#define fi first
#define se second
#include<algorithm>
using namespace std;
#define ll long long
typedef pair<int,int> ii;
void minimize(int &a,int b){
	if(a > b) a = b;
}
bool CCW(ii o,ii a,ii b){
	int u1=a.fi - o.fi;
	int v1=a.se - o.se;
	int u2=b.fi - o.fi;
	int v2=b.se - o.se;
	return (1ll*u1*v2 > 1ll*u2*v1);
}
map<ii,int> mp;
ii o , a[NM] , b[NM];
int n , ans[NM] , x[NM] , y[NM];
bool cmp(ii a,ii b){
	return (CCW( o , a , b));
}
bool ok(ii u,ii v,ii t){
	ll a1 = -(v.se - u.se);
	ll b1 = (v.fi - u.fi);
	ll c1 = -a1*u.fi  - b1*u.se;
	return (1ll*a1*t.fi + 1ll*b1*t.se + c1 == 0);
}
void solve(int mask){
	int m = 0 , ntree = 0;
	for(int i = 0 ; i < n  ;  i++)
		if(mask&1<<i){
		 	m++ ; a[m] = ii(x[i] , y[i]); ntree++;
		}
	if(m == 0) return ;
	if(m == 1)	minimize(ans[mp[a[1]]] , n - 1);
	sort(a + 1 , a + 1 + m);
	o = a[1] ; sort(a + 2 , a + 1 + m , cmp);
	int t = 0;
	for(int i = 1 ; i <= m ; i++){
    	while(t >= 2 && !CCW(b[t - 1],b[t],a[i])) t--;
    	t++;
    	b[t] = a[i];
    }
	for(int i = 1 ; i <= m ; i++){
    	for(int j = 2 ; j <= t ; j++) if(ok(b[j],b[j - 1],a[i])) minimize(ans[mp[a[i]]] , n - ntree);
    	if(ok(b[t] , b[1] , a[i])) minimize(ans[mp[a[i]]] , n - ntree);
	}
}
main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int c = 1 ; c <= T ; c++){
		scanf("%d",&n);
		mp.clear() ; for(int i = 1 ; i <= n ; i++) ans[i] = n;
		for(int i = 0 ; i < n ; i++){
			scanf("%d %d",&x[i],&y[i]);
			mp[ii(x[i] , y[i])] = i + 1;
		}
		for(int i = 0 ; i < (1<<n) ; i++)	solve(i);
		printf("Case #%d:\n",c);
		for(int i = 1 ; i <= n ; i++)	printf("%d\n",ans[i]);
	}
}
