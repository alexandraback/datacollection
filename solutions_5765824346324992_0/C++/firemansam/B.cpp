#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
vector<ii> m, k, qq;
long long tcs, b, n, ans, kd, kk, vt[100005];
long long gcd(long long c, long long d){
	if(d == 0) return c;
	return gcd(d, c % d);
}
long long lcm(long long c, long long d){
	return (c * d) / gcd(max(c, d), min(c, d));
}
int main(){
	scanf("%lld", &tcs);
	for(long long tc=1;tc<=tcs;tc++){
		scanf("%lld%lld", &b, &n);
		m.clear();
		long long gd = 0;
		kd = 0;
		kk = 0;
		qq.clear();
		memset(vt, 0, sizeof vt);
		for(long long i=0;i<b;i++){
			long long tm;
			scanf("%lld", &tm);
			if (!i) gd = tm;
			else (gd = lcm(gd, tm));
			m.push_back(ii(tm, i));
		}
		k.clear();
		for(long long i=0;i<b;i++){
			kd += gd / m[i].first;
		}
		n %= kd;
		if (!n) n = kd;
		//we try simulating now
		sort(m.begin(), m.end());
		for(int i=0;i<b;i++){
			for(int j=1;j<(gd/m[i].first);j++){
				qq.push_back(ii(m[i].first * j, m[i].second));
			}
		}
		sort(qq.begin(), qq.end());
		//printf("%lld\n", n);
		/*for(int i=0;i<qq.size();i++){
			printf("%i %i\n", qq[i].first, qq[i].second);
		}*/
		if(n <= b) ans = n;
		else ans = (qq[n-b-1]).second + 1LL;
		printf("Case #%lld: %lld\n", tc, ans);
	}
}