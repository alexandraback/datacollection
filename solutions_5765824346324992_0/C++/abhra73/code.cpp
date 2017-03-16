#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define F first
#define S second
using namespace std;

set<pair<pair<ll,ll>,ll> > st;
pair<pair<ll,ll>,ll> p,p1;
set<pair<pair<ll,ll>,ll> >::iterator it;
ll gcd(ll a,ll b){
	return (b==0)?a:gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}
ll arr[100];
int main() {
	ll t,b,n,cas=0,lc,cnt;
	scanf("%Ld",&t);
	while(t--){
		printf("Case #%Ld: ",++cas);
		scanf("%Ld%Ld",&b,&n);
		st.clear();
		lc=1;cnt=0;
		for(int i=0;i<b;i++){
			scanf("%Ld",&arr[i]);
			st.insert(mp(mp((ll)0,(ll)i),arr[i]));
			lc=lcm(lc,arr[i]);
		}
		for(int i=0;i<b;i++) cnt+=lc/arr[i];
		n--;
		n%=cnt;
		for(int i=0;i<=n-1;i++){
			it=st.begin();
			p=(*it);
			st.erase(it);
			p.F.F+=p.S;
			st.insert(p);
		}
		printf("%Ld\n",(*st.begin()).first.second + 1);
	}
	return 0;
}
