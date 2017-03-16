#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
ll b,n,a[1111];
ll check(ll k){
	ll cnt=0;
	for(int i=0;i<b;i++){
		cnt+=k/a[i]+1;
	}
	return cnt;
}
ll f(ll k){
	ll cnt=0;
	vector<pp> s;
	for(int i=0;i<b;i++){
		cnt+=k/a[i]+1;
		s.push_back(pp(a[i]-k%a[i],i+1));
	}
	if(cnt==n){
		return n;
	}
	sort(s.begin(),s.end());
	//for(int i=0;i<s.size();i++)printf("%lld,%lld ",s[i].first,s[i].second);
	//puts("");
	return s[(n-cnt)-1].second;
}
int main(){
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	//printf("%d\n",T);
	for(int t=1;t<=T;t++){
		scanf("%lld%lld",&b,&n);
		//printf("%lld %lld\n",b,n);
		for(int i=0;i<b;i++)scanf("%lld",&a[i]);//,printf("%lld ",a[i]);
		ll lo=0,hi=1e18,mid,ans;
		while(lo+1<hi){
			mid=(lo+hi)/2;
			if(check(mid)>=n){
				hi=mid;
			}
			else{
				lo=mid;
			}
		}
		//printf("%lld %lld\n",lo,check(lo));
		ans=f(lo);
		printf("Case #%d: %lld\n",t,ans);
	}
}
