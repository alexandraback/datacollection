#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <numeric>
#include <tuple>
#include <climits>

#define INF 1023456789
#define SQR(x) ((x)*(x))
#define INIT(x,y) memset((x),(y),sizeof((x)))
#define SIZE(x) ((int)((x).size()))
#define REP(i, n) for (__typeof(n) i=0;i<(n);++i)
#define FOR(i, a, b) for (__typeof(a) i=(a);i<=(b);++i)
#define FORD(i, a, b) for (__typeof(a) i=(a);i>=(b);--i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define DEBUG
#ifdef DEBUG
#define DBG(x) cerr << #x << ": " << (x) << endl;
#else
#define DBG(x)
#endif

using namespace std;
 
typedef long long LL;
typedef pair<int,int> PI;
typedef tuple<int,int,int>trio;

int m[20][20];

inline int around(int r,int c)
{
	return m[r+1][c] + m[r][c-1] + m[r][c+1] + m[r-1][c];
}

void solve(int t)
{
	int R,C,N;
	scanf("%d%d%d",&R,&C,&N);
	int possibilities = 1 << (R*C);
	int res = INT_MAX;
	REP(i,possibilities)
	{
		if (__builtin_popcount(i) != N) continue;
		FOR(j,0,R+1) FOR(k,0,C+1) m[j][k] = 0;
		int mask = i;
		int row = 1;
		int col = 1;
		while (mask)
		{
			m[row][col] = mask&1;
			if (col + 1 <= C) col++;
			else 
			{
				col = 1;
				row++;
			}
			mask >>= 1;
		}
		//FOR(j,1,R) FOR(k,1,C) DBG(m[j][k]);
		int p = 0;
		FOR(j,1,R) FOR(k,1,C) if (m[j][k]) p += around(j,k);
		res = min(res,p);
	}
	printf("Case #%d: %d\n",t,res/2);
}

int main()
{
	int T;
	scanf("%d",&T);
	REP(i,T) solve(i+1);
        return 0;
}
