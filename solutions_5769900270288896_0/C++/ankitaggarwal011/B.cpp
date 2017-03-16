#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
using namespace std;

int R, C, N;
int memo[1000000];

int solve(int n){
	int res = 0;
	for (int x = 0; x < R; x++){
		for (int y = 0; y < C; y++){
			if (x > 0 && (n & (1 << (x * C + y - C))) && (n & (1 << (x * C + y)))) res++;
			if (y > 0 && (n & (1 << (x * C+ y - 1))) && (n & (1 << (x * C + y)))) res++;
		}
	}
	return res;
}

int main() { _
	int T, cases, i, ans;
	cin >> T;
	for (cases = 1; cases <= T; cases++){
		cin >> R >> C >> N;
		ans = N*R*C;
		for(i = 1; i < (1 << (R * C)); i++){
			memo[i] = memo[i - (i & -i)] + 1;
			if (memo[i] == N) ans = min(ans, solve(i));
		}
		cout << "Case #"<<cases << ": " << ans << endl;
	}
}
