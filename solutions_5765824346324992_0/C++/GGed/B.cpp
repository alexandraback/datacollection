#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

int n;
LLD m, a[1005];

void solve(int tc){
	scanf("%d%lld", &n, &m);
	FOR(i,0,n) scanf("%lld", &a[i]);
	LLD t = m * a[0];
	for (LLD i=0, j=m*a[0]; i<=j;){
		LLD k = (i + j) >> 1, s = 0;
		FOR(r,0,n) s += 1 + k / a[r];
		if (s >= m) t = min(t, k), j = k - 1;
		else i = k + 1;
	}
	// printf("%lld\n", t);
	LLD cnt = 0;
	FOR(i,0,n) cnt += (t + a[i] - 1) / a[i];
	FOR(i,0,n){
		cnt += (t % a[i] == 0);
		if (cnt >= m){
			printf("Case #%d: %d\n", tc, i + 1);
			break;
		}
	}
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
