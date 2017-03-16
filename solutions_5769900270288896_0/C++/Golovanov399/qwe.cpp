#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

void solve(){
	int r, c, n;
	cin >> r >> c >> n;
	int N = r * c;
	vector<int> a(N);
	for (int i = 0; i < n; i++){
		a[i] = 1;
	}
	sort(all(a));
	int ans = 1e9;
	vector<int> qw;
	do {
		int cur = 0;
		for (int i = 0; i < r - 1; i++){
			for (int j = 0; j < c; j++){
				int x = i * c + j;
				int y = (i + 1) * c + j;
				if (a[x] && a[y]){
					cur++;
				}
			}
		}
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c - 1; j++){
				int x = i * c + j;
				int y = i * c + (j + 1);
				if (a[x] && a[y]){
					cur++;
				}
			}
		}
		if (cur < ans){
			ans = cur;
			qw = a;
		}
	} while (next_permutation(all(a)));
	cout << ans << "\n";
	// for (int i = 0; i < N; i++){
	// 	cerr << qw[i];
	// 	if (i % c == c - 1)
	// 		cerr << "\n";
	// }
}

int main(){

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		printf("Case #%d: ", i + 1);
		solve();
		cerr << "Test #" << i + 1 << " completed\n";
	}

	return 0;
}