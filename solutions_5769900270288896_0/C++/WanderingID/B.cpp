#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<int(n); ++i)
#define out(x) cout<<#x"="<<x<<endl
bool a[20][20];
int r, c, n, ans;
void gao(int x, int y, int noise, int cnt) {
	if (x==r+1) {
		if (cnt == n) ans = min(ans, noise);
		return;
	}
	int nx = x, ny = y + 1;
	if (ny > c) {
		nx ++;
		ny = 1;
	}
	a[x][y] = 0;
	gao(nx, ny, noise, cnt);
	a[x][y] = 1;
	gao(nx, ny, noise+a[x-1][y]+a[x][y-1], cnt+1);
}
int main() {
	int T;
	scanf("%d",&T);
	REP(tt,T){
		scanf("%d%d%d", &r, &c, &n);
		memset(a, 0, sizeof a);
		ans = 10000000;
		gao(1, 1, 0, 0);
		printf("Case #%d: %d\n", tt+1, ans);
	}
}