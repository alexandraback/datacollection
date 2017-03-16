
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

void init()
{
	
}

// bit 0 is the least significant bit
// the order is descending lexicographically
// to generate in ascending order, take 0 as present
inline uint next_permutation(uint v)
{/*
	unsigned int t = (v | (v - 1)) + 1;  
	return t | ((((t & -t) / (v & -v)) >> 1) - 1); */

	uint t = v | (v - 1); // t gets v's least significant 0 bits set to 1
	// Next set to 1 the most significant bit to change, 
	// set to 0 the least significant ones, and add the necessary 1 bits.
	return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));  
}

int r, c, n;

inline int occupied(int i, int j, int t)
{
	return (t >> (i*c + j)) & 1;
}

int unhappiness(int t)
{
	int res = 0;
	REP (i, r)
		REP (j, c - 1) {
			if (occupied(i, j, t) && occupied(i, j + 1, t))
				res++;
		}
	REP (j, c)
		REP (i, r - 1) {
			if (occupied(i, j, t) && occupied(i + 1, j, t))
				res++;
		}
	return res;
}

void solve()
{
	cin >> r >> c >> n;
	int start = (1 << n) - 1, ans = INF;
	for (int t = start; t <= start << (r*c - n); t = next_permutation(t)) {
		ans = min(ans, unhappiness(t));
	}
	cout << ans;
}

int main()
{ _
	init();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
