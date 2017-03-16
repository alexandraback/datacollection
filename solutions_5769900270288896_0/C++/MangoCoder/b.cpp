#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#define For(i,j,n) for(int i=j ; i<=n ; ++i)
using namespace std;

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		int R, C, N; cin >> R >> C >> N;
	
		int n, r;
		n = R * C;
		r = N;
	
		vector<int> v(n);
		For (i, 0, n-1) {
			v[i] = i;
		}
		
		int ans = 100000000;
		For (mask, 1, (1 << n)-1)  if (__builtin_popcount(mask) == r) {
			
			vector<vector<bool> > b(R, vector<bool> (C, false));
			
			For (i, 0, n-1) {
				if (mask & (1<<i)) {
					b[v[i]/C][v[i]%C] = true;
					//cout << v[i] << " ";
				}
			}
			int by = 0;
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C-1; ++j) {
					if (b[i][j] && b[i][j+1]) by++;
				}
			}
			for (int j = 0; j < C; ++j) {
				for (int i = 0; i < R-1; ++i) {
					if (b[i][j] && b[i+1][j]) by++;
				}
			}
			
			ans = min(ans, by);
			//cout << endl;
		}
			
		if (ans == 100000000) {
			cout << 0 << endl;
		}
		else {
			cout << ans << endl;
		}
		
	}
	return 0;
}
