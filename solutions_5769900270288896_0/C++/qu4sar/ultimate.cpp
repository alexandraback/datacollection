//AV
//quasar

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, r, c, n;
int mat[20][20];
int ans = 1 << 30;

void solve(int i, int j, int u, int p){
	if (i == r - 1 && j == c){
		if (p == n){
			ans = min(ans, u);
		}
		return;
	}
	i += j / c;
	j %= c;
	solve(i, j + 1, u, p);
	mat[i][j] = 1;
	if (i > 0 && mat[i - 1][j] == 1)u++;
	if (j > 0 && mat[i][j - 1] == 1)u++;
	solve(i, j + 1, u, p + 1);
	mat[i][j] = 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	int cs = 1;
	while (t--){
		ans = 1 << 30;
		memset(mat, 0, sizeof(mat));
		cin >> r >> c >> n;
		solve(0, 0, 0, 0);
		cout << "Case #"<<cs<<": "<<ans<<"\n";
		cs++;
	}
}
