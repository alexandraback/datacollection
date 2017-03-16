#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int TC;
ll n, b, p[2000];
ll cntcustom(ll x){
	ll ans = 0;
	for(int i = 0; i < b; ++i){
		ans += (x/p[i]) + 1;
	}
	return ans;
}
vector<int> op(ll x){
	vector<int> rt;
	for(int i = 0; i < b; ++i){
		if(x%p[i] == 0) rt.push_back(i);
	}
	return rt;
}
int main(){
	scanf("%d", &TC);
	for(int tc = 1; tc <= TC; ++tc){
		scanf("%lld %lld", &b, &n);
		for(int i = 0; i < b; ++i) scanf("%d", &p[i]);
		ll top = n * 200000LL, bot = 0LL;
		while(top > bot){
			ll mid = (top+bot)/2;
			if(cntcustom(mid) < n) bot = mid+1;
			else top = mid;
		}
		ll c = cntcustom(bot);
		vector<int> p = op(bot);
		reverse(p.begin(), p.end());
		printf("Case #%d: %d\n", tc, p[c-n]+1);
	}
}