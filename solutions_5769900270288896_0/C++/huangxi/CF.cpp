#include <bits/stdc++.h>
#define  RD(x)      scanf("%d", &x)
#define  REP(i, n)  for (int i=0; i<int(n); ++i)
#define  FOR(i, n)  for (int i=1; i<=int(n); ++i)
#define  pii        pair<int, int>
#define  piL        pair<int, long long>
//#define  mp         make_pair
#define  pb         push_back
#define  whatis(x)  cout << #x << ": " << x << endl;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

using namespace std;
#define  N   123
#define  eps 1e-8
#define  pi  acos(-1.0)
#define  inf 0XFFFFFFFFFFFFFFll
#define  mod 100007ll
#define  LL  long long
#define  ULL unsigned long long


int mp[N][N];

int n, r, c;
int ans;
void work() {
	int cnt = 0;
	FOR(i, r) FOR(j, c) {
		if (mp[i][j]) {
			if (mp[i][j+1])
				cnt++;
			if (mp[i+1][j])
				cnt++;
		}
	}
	ans = min(ans, cnt);
}

void dfs(int i = 1, int j = 1, int has = 0) {
	if (has == n) {
		work();
		return;
	}
	if (has > n)
		return;

	if (i == r + 1)
		return;
	if (j == c + 1)
		dfs(i+1, 1, has);
	else {
		if ((r - i) * c + (c - j + 1) + has < n)
			return;
		mp[i][j] = 1;
		dfs(i, j+1, has+1);
		mp[i][j] = 0;
		dfs(i, j+1, has);
	}
}

int Main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);


	int T;
	cin >> T;

	FOR(_T, T) {

		cin >> r >> c >> n;
		memset(mp, 0, sizeof mp);
		ans = 2 * r * c;
		dfs();

		cout << "Case #" << _T << ": " << ans << endl;



	}

	return 0;

}

int main() {
	return Main();
}
