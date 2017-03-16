#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("A-large.in", "r", stdin);
	FILE *fout = freopen("A-large.out", "w", stdout);
	assert	( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		LL a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		LL ans = 0;
		LL mmush = 0;
		for(int i = 1; i < n; i++){
			ans += max(0LL,a[i-1]-a[i]);
			mmush = max(mmush, a[i-1]-a[i]);
		}
		LL ans2 = 0;
		for(int i = 0; i < n-1; i++){
			ans2 += min(mmush, a[i]);
		}
		cout << ans << " " << ans2 << endl;

	}
	exit(0);
}