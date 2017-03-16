#include <bits/stdc++.h>
using namespace std;
int T, n, a[30];
void solve(int test) {
	scanf("%d", &n);
	int sum=0;
	priority_queue<pair<int, int> >pq;
	for (int i=0; i<n; i++) scanf("%d", &a[i]), sum+=a[i], pq.push({a[i], i});
	printf("Case #%d:", test);
	if (sum%2) {
		sum--;
		int f1=pq.top().first, f2=pq.top().second;
		pq.pop();
		printf(" %c", f2+'A');
		if (f1>1) pq.push({f1-1, f2});
	}
	while (!pq.empty()) {
		int f1=pq.top().first, f2=pq.top().second;
		pq.pop();
		int g1=pq.top().first, g2=pq.top().second;
		pq.pop();
		printf(" %c%c", f2+'A', g2+'A');
		if (f1>1) pq.push({f1-1, f2});
		if (g1>1) pq.push({g1-1, g2});
	}
	printf("\n");
}
int main () {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &T);
	for (int i=1; i<=T; i++) {
		solve(i);
	}
	return 0;
}
