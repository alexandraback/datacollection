#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector <int> VI;
typedef pair <LL, LL> PII;
const int MAXN = 1e6 + 7, Mo = 1e9 + 7;
const LL INF = 1e15;

LL N, M;
LL a[MAXN];

void init(){
	scanf("%lld%lld", &M, &N);
	for (int i=0; i<M; i++) scanf("%lld", a+i);
}

LL calc(LL ti){
	LL cnt = 0;
	for (int i=0; i<M; i++) cnt += ti / a[i] + 1;
	return cnt;
}

LL gao(int k){
	LL l = 1, r = INF;
	while (l < r){
		LL mid = (l+r)>>1;
		if (calc(mid) >= N-k) r = mid; else l = mid + 1;
	}		
	return l;
}

void solve(){
	LL t[1234] = {}, num = 0, ti;
	for (int i=0; i<=M; i++){
		t[i] = gao(i);
		if (t[0] != t[i]){
			ti = t[0]; num = i-1; break;
		}
	}	
	
	vector <PII> v;
	int cnt = 0, ans = 0;
	for (int i=0; i<M; i++)
		if (ti%a[i] == 0){
			cnt++; ans = i+1;
			if (cnt > num) break;
		}
	printf("%d\n", ans);
}

int main(){
	int t; scanf("%d", &t);
	for (int cas = 1; cas <= t; cas ++){
		printf("Case #%d: ", cas);
		init();
		if (N <= M){ 
			printf("%lld\n", N); continue; 
		}
		solve();		
	}
	return 0;
}

