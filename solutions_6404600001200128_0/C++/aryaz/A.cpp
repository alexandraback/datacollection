#include <bits/stdc++.h>
using namespace std;

int m[1005];

int main () {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		int maxi = 0;
		int res1 = 0;
		int res2 = 0;
		for(int i = 0; i < n; i++) {
			cin >> m[i];
			if(i > 0) {
				maxi = max(m[i-1] - m[i], maxi);
				res1 += max(0, m[i-1] - m[i]);
			}
		}
		for(int i = 0; i < n-1; i++)
			res2 += min(maxi, m[i]);
		cout << "Case #" << t << ": " << res1 << " " << res2 << endl;
	}
	return 0;
}
