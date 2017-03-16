//============================================================================
// Author	   : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name :
// Time Limit   : .000s
// Description  :
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI	3.1415926535897932385
#define EPS	1e-7
#define MOD	1000000007
#define INF	1000111222
#define MAX	505

int n, cnt[MAX][MAX], maxi[MAX];
string s[MAX], pat;

int solve() {
	pat = "";
	rep(j, s[0].length()) {
		if (j == 0 || (s[0][j] != s[0][j - 1])) pat += s[0][j];
	}
	fill(cnt, 0); fill(maxi, 0);
	rep(i, n) {
		string tmp = "";
		rep(j, s[i].length()) {
			if (j == 0 || (s[i][j] != s[i][j - 1])){
				cnt[i][tmp.length()] = 1;
				tmp += s[i][j];
			}
			else {
				cnt[i][tmp.length() - 1]++;
			}
		}
		if (tmp != pat) return -1;
	}
	int res = 0, m = pat.length();
	rep(j, m) {
		rep(i, n) maxi[j] = max(maxi[j], cnt[i][j]);
	}
	rep(j, m) {
		int mini = INF;
		fr(k, 1, maxi[j]) {
			int add = 0;
			rep(i, n) add += abs(cnt[i][j] - k);
			mini = min(mini, add);
		}
		res += mini;
	}
	return res;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		rep(i, n) cin >> s[i];
		printf("Case #%d: ", ++caseNo);
		int res = solve();
		if (res >= 0) printf("%d\n", res);
		else puts("Fegla Won");
	}
	return 0;
}
