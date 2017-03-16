#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#define LL long long
#define REP(i,n) for (int i=1;i<=n;++i)
using namespace std;

int T,n;
LL m,ans;
int a[1010];
vector< pair<LL,int> > v;

LL Check(LL k) {
	LL ret=0;
	REP(i,n) ret+=k/(LL)a[i]+1;
	return ret;
}

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	REP(T_T,T) {
		cin>>n>>m;
		REP(i,n) scanf("%d",&a[i]);
		ans=-1;
		for (LL i=(1ll<<52);i;i>>=1ll)
			if (Check(ans+i)<m) ans+=i;
		++ans;
		v.clear();
		REP(i,n) v.push_back(make_pair(ans/(LL)a[i]*(LL)a[i],i));
		sort(v.begin(),v.end());
		printf("Case #%d: %d\n",T_T,v[n-1+m-Check(ans)].second);
	}
	return 0;
}