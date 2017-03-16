#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;++i)
#define FOR(i, a, b) for(int i = a;i < b;++i)
#define F first
#define S second
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int, int> ii;
int r, c, n;
bool matrix[20][20];


void erase_() { REP(i, r) fill(matrix[i], matrix[i] + c, 0); }

int get() {
	int cnt = 0;
	REP(i, r) REP(j, c - 1) if(matrix[i][j] && matrix[i][j + 1]) ++cnt;
	REP(i, r - 1) REP(j, c) if(matrix[i][j] && matrix[i + 1][j]) ++cnt;
	return cnt;
}

int solve() {
	int m = r * c;
	int sol = 1e9;
	REP(i, (1 << m)) {
		if(__builtin_popcount(i) != n) continue;
		erase_();
		int mask = i;
		REP(j, m) matrix[j/c][j%c] = (i & (1 << j)) ? 1 : 0;
		sol = min(sol, get());
	}
	return sol;
}


int main() {
	int t;
	cin >> t;
	REP(i, t) {
		cin >> r >> c >> n;
		cout << "Case #" << i + 1 << ": " << solve() << "\n";
	}
}