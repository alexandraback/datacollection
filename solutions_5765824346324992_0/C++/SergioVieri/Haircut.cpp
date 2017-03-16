#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ft first
#define sc second
#define INF (int)1e9
typedef long long LL;
using namespace std;

LL arr[1005];
priority_queue<pair<LL,LL> > pq;


int main(){
	freopen("b4.in","r",stdin);
	freopen("b4.out","w",stdout);
	int t, no = 0;
	scanf("%d",&t);
	while(t--){
		while(!pq.empty()) pq.pop();
		LL ans = 0;
		LL b, n, rep, md = 0;
		scanf("%lld%lld",&b,&n);
		n--;
		for(int i = 0; i < b; i++ ){
			scanf("%lld",&arr[i]);
		}
		rep = arr[0];
		for(int i = 1; i < b; i++ ){
			rep = (rep*arr[i])/__gcd(rep,arr[i]);
		}
		for(int i = 0; i < b; i++ ){
			md += rep/arr[i];
		}
		n %= md;
//		if(n==0) n+=md;
//		printf("n -> %d (%d)\n",n,md);
		for(int i = 0; i < b; i++ ){
			pq.push(mp(-arr[i],-i));
		}
		for(int i = b; i < n; i++ ){
			pair<LL,LL> cur = pq.top();
			pq.pop();
			pq.push(mp(cur.ft-arr[-cur.sc],cur.sc));
//			printf("%d->%d\n",i,cur.sc);
		}
//		printf("%d->%d\n",n,pq.top().sc);
		ans = -pq.top().sc;
		if(n<b) ans = n;
		printf("Case #%d: %lld\n",++no,ans+1);
	}
	return 0;
}


