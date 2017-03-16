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

int n, a[10005];

void solve(int tc){
	scanf("%d", &n);
	FOR(i,0,n) scanf("%d", &a[i]);
	int x = 0, y = 0;
	FOR(i,1,n) x += max(0, a[i-1] - a[i]);
	if (x > 0){
		int r = 0;
		FOR(i,1,n) r = max(r, a[i-1] - a[i]);
		FOR(i,0,n-1) y += min(r, a[i]);
	}
	printf("Case #%d: %d %d\n", tc, x, y);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
