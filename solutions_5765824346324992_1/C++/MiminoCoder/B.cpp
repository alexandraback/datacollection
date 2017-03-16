#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 1007;
ll B, N, in[MAX];

void Solve(int tc)
{
	scanf("%lld%lld", &B, &N);
	--N;
	REP(i, B) scanf("%lld", in+i);

	ll be = 0, en = in[0]*N, res = 0;
	while (be <= en) {
		ll m = (be+en) / 2, n = 0;
		REP(i, B) n += 1 + m / in[i];
		if (N < n) {
			res = m;
			en = m-1;
		} else {
			be = m+1;
		}
	}
	if (res) {
		REP(i, B) 
			N -= 1 + (res-1) / in[i];
	}

	printf("Case #%d: ", tc);
	REP(i, B)
		if (res % in[i] == 0 && N-- == 0) {
			printf("%d\n", i+1);
			return;
		}
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) {
		cerr << "Test case: " << tc << endl;
		Solve(tc);
	}

	return 0;
}