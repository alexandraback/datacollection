#include<bits/stdc++.h>
using namespace std;
int n, m, k, t, A[65560], ans;

int check() {
	int ans = 0;
	//for(int i = 0; i < n * m; i++) cout << A[i] << " " ;
	//cout << endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(A[i * m + j] == 1) {
				if(i == n - 1) {
					if(A[i * m + j + 1] == 1) {
						ans++;
					}
					continue;	
				}
				if(j != m - 1) {
					if(A[i * m + j + 1] == 1) {
						ans++;
					}
				}
				if(A[i * m + j + m] == 1) {
					ans++;
				}
			}
		}
	}
	return ans;
}

int main() {
	cin >> t;
	for(int kase = 1; kase <= t; kase++) {
		cin >> n >> m >> k;
		if(k == 0) {
			ans = 0;
		} else {
			ans = 10000006;
		}
		int temp = n * m;
		int temp1 = n * m;
		temp = 1 << temp;
		//cout << temp << endl;
		int count = 0;
		for(int i = 1; i <= temp; i++) {
			if( __builtin_popcount(i) != k) continue;
			count++;
			int j = 1, pos = 0;
			while(j <= i) {
				if(j & i) {
					A[pos] = 1;
					//cout << pos << endl;
				}
				j = j << 1;
				pos++;
			}
			ans = min(ans, check());
			memset(A, 0, sizeof(A));
		}
		cout << "Case #" << kase << ": " << ans << endl;

	}


}