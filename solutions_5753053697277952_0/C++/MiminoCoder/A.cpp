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

const int MAX = 26;
int N, num[MAX];

void Solve(int tc) {
	scanf("%d", &N);
	int M = 0;
	REP(i, N) {
		scanf("%d", num+i);
		M += num[i];
	}

	printf("Case #%d:", tc);
	while (M) {
		int i1 = -1, i2 = -1;
		REP(i, N) {
			if (i1 == -1 || num[i] > num[i1]) { i2 = i1; i1 = i; }
			else if (i2 == -1 || num[i] > num[i2]) { i2 = i; }
		}
		
		if (M == 3) {
			--num[i1], --num[i2];
			REP(i, N)
				if (num[i]) {
					printf(" %c", i+'A');
					--num[i];
					break;
				}
			--M;
		}
		
		printf(" %c%c", i1+'A', i2+'A'); 
		--num[i1]; 
		--num[i2];
		M -= 2;
	}
	printf("\n");
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