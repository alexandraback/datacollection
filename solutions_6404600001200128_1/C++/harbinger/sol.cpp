
// Author: Tiago Togores

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(), (a).end()
#define CLR(a, x) memset(a, x, sizeof a)
#define REP(i, n) for (auto i = 0; i < (n); i++)
#define FORT(it, l) for (auto it = (l).begin(); it != (l).end(); it++)
#define SCW(n) while ((cin >> (n)) && (n))
#define SCR(n) for (cin >> (n); (n)--;)
#define READLINE(line) cin.getline((line), sizeof (line))
#define VALID(i, j, n, m) (0 <= (i) && (i) < (n) && 0 <= (j) && (j) < (m))
#define PI M_PI
#define EPSILON 1e-6
#define INF 1000000000
#define MOD 1000000007
#define endl '\n'
//NOTE: append ll to name if using long long
#define BITCOUNT __builtin_popcount
#define BITLEAD0 __builtin_clz
#define BITTRAIL0 __builtin_ctz
#define BITPARITY __builtin_parity

typedef unsigned int uint;
typedef long long int int64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

///////////////////////////////

#define N 1010
int v[N];

void init()
{
	
}

void solve()
{
	int n;
	cin >> n;
	REP (i, n)
		cin >> v[i];
	int64 ans1 = 0, ans2 = 0;
	int d = 0;
	for (int i = 1; i < n; i++) {
		int m = max(v[i - 1] - v[i], 0);
		ans1 += m;
		d = max(d, m);
	}
	REP (i, n - 1)
		ans2 += min(d, v[i]);
	cout << ans1 << " " << ans2 << endl;
}

int main()
{ _
	init();
	int t, tc = 1;
	SCR(t) {
		cout << "Case #" << tc++ << ": ";
		solve();
	}
	return 0;
}
