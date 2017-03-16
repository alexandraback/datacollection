/*	Arkadiusz Wróbel - metsuryuu
 *
 *	Konkurs: Google Code Jam 2015
 *	Zadanie: 
 */
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <cmath>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

#define REP(I, N) for(int I = 0; I < (N); ++I)
#define FOR(I, M, N) for(int I = (M); I <= (N); ++I)
#define FORD(I, M, N) for(int I = (M); I >= (N); --I)
//#define FOREACH(IT, CON) for(__typeof((CON).begin()) IT = (CON).begin(); IT != (CON).end(); ++IT)

#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define SIZE(CON) ((int)(CON).size())
#define ALL(CON) (CON).begin(), (CON).end()

const int INF = 1000000000;
const LL INFLL = 1000000000000000000LL;

//######################################################################

const int wekt[4][2] {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

int ileStyk(const vector<vector<bool>> &t, const int y, const int x) {
	int wyn = 0;
	REP(i, 4) {
		if (t[y + wekt[i][0]][x + wekt[i][1]]) {
			++wyn;
		}
	}
	return wyn;
}

int make(const int n, const int m, int r, bool start) {
	vector<vector<bool>> t(n+2, vector<bool>(m+2, 0));
	
	FOR(i, 1, n) {
		bool b = start;
		start ^= 1;
		FOR(j, 1, m) {
			if (b) {
				t[i][j] = 1;
				--r;
			}
			b ^= 1;
		}
	}
	
	if (r <= 0) {
		return 0;
	}
	
	int wyn = 0;
	
	FOR(iii, 1, 4) {
		FOR(i, 1, n) {
			FOR(j, 1, m) {
				if (t[i][j] == 0 && ileStyk(t, i, j) == iii) {
					r -= 1;
					wyn += iii;
					if (r <= 0) {
						return wyn;
					}
				}
			}
		}
	}
	
	return INF;
}

int main()
{
	int T;
	scanf("%d", &T);
	FOR(testCounter, 1, T){
		int n, m, r;
		//wej
		scanf("%d%d%d", &n, &m, &r);
		//wyj
		printf("Case #%d: %d\n", testCounter, min(make(n, m, r, 0), make(n, m, r, 1)));
	}
	return 0;
}
