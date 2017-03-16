#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("A-small-attempt0.in", "r", stdin);
	FILE *fout = freopen("A-small-attempt0.out", "w", stdout);
	assert	( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		int ans = 0;
		int mmush = 0;
		for(int i = 1; i < n; i++){
			ans += max(0,a[i-1]-a[i]);
			mmush = max(mmush, a[i-1]-a[i]);
		}
		int ans2 = 0;
		for(int i = 0; i < n-1; i++){
			ans2 += min(mmush, a[i]);
		}
		cout << ans << " " << ans2 << endl;

	}
	exit(0);
}