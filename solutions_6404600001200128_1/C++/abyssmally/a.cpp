#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define N 1234

int t, n, a[N];
int main() {
	freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	scanf("%d", &t);
	fo(tc,1,t+1) {
		printf("Case #%d: ", tc);
		scanf("%d", &n);
		fo(i,0,n) scanf("%d", a+i);
		int madif = 0, ans1 = 0, ans2 = 0;
		fo(i,0,n-1) ans1 += max(0, a[i]-a[i+1]);
		fo(i,0,n-1) madif = max(madif, a[i]-a[i+1]);
		fo(i,0,n-1) {
			ans2 += min(madif, a[i]);
		}
		printf("%d %d\n", ans1, ans2);
	}

	return 0;
}