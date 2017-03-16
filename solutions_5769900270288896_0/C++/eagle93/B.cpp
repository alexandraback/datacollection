#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define REP(i,n) for( (i)=0 ; (i)<(n) ; (i)++ )
#define rep(i,x,n) for( (i)=(x) ; (i)<(n) ; (i)++ )
#define REV(i,n) for( (i)=(n) ; (i)>=0 ; (i)-- )
#define FORIT(it,x) for( (it)=(x).begin() ; (it)!=(x).end() ; (it)++ )
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define rforeach(it,c) for(__typeof((c).rbegin()) it=(c).rbegin();it!=(c).rend();++it)
#define foreach2d(i, j, v) foreach(i,v) foreach(j,*i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define SZ(x) ((int)(x).size())
#define MMS(x,n) memset(x,n,sizeof(x))
#define mms(x,n,s) memset(x,n,sizeof(x)*s)
#define pb push_back
#define mp make_pair
#define NX next_permutation
#define UN(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define CV(x,n) count(all(x),(n))
#define FIND(x,n) find(all(x),(n))-(x).begin()
#define ACC(x) accumulate(all(x),0)
#define PPC(x) __builtin_popcount(x)
#define LZ(x) __builtin_clz(x)
#define TZ(x) __builtin_ctz(x)
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))
#define low(x,i) lower_bound(all(x),i)
#define upp(x,i) upper_bound(all(x),i)
#define NXPOW2(x) (1ll << ((int)log2(x)+1))
#define PR(x) cout << #x << " = " << (x) << endl ;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

const int OO = (int) 2e9;
const double eps = 1e-9;

int pre[17][17][17];

void init() {

	for (int i = 2; i < 17; i++) {
		if (i % 2 == 0)
			pre[1][i][i / 2 + 1] = 1;
		for (int j = i / 2 + 2; j <= i; j++) {
			pre[1][i][j] = pre[1][i][j - 1] + 2;
		}
	}

	for (int i = 2; i < 9; i++) {
		pre[2][i][i + 1] = 2;
		pre[2][i][i + 2] = 4;
		for (int j = i + 3; j <= 2 * i; j++) {
			pre[2][i][j] = pre[2][i][j - 1] + 3;
		}
	}

	pre[3][3][6] = 4;
	pre[3][3][7] = 6;
	pre[3][3][8] = 8;
	pre[3][3][9] = 12;

	pre[3][4][7] = 4;
	pre[3][4][8] = 4;
	pre[3][4][9] = 7;
	pre[3][4][10] = 10;
	pre[3][4][11] = 13;
	pre[3][4][12] = 17;

	pre[3][5][9] = 3;
	pre[3][5][10] = 6;
	pre[3][5][11] = 8;
	pre[3][5][12] = 11;
	pre[3][5][13] = 14;
	pre[3][5][14] = 18;
	pre[3][5][15] = 22;

	pre[4][4][9] = 2;
	pre[4][4][10] = 4;
	pre[4][4][11] = 7;
	pre[4][4][12] = 10;
	pre[4][4][13] = 13;
	pre[4][4][14] = 16;
	pre[4][4][15] = 20;
	pre[4][4][16] = 24;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt2.in", "rt", stdin);
	freopen("out3.out", "wt", stdout);
#endif
	init();
	int t, tt = 1;
	cin >> t;
	while (t--) {
		int r, c, n;
		cin >> r >> c >> n;
		if (r > c)
			swap(r, c);
		cout << "Case #" << tt++ << ": " << pre[r][c][n] << "\n";
	}
	return 0;
}
