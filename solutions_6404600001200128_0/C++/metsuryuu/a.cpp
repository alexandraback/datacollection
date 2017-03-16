/*	Arkadiusz Wróbel - metsuryuu
 *
 *	Konkurs: Google Code Jam 2015
 *	Zadanie: Mushroom Monster
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

int n;
int t[1024];

LL make1() {
	LL wyn = 0;
	FOR(i, 1, n-1) {
		if (t[i-1] > t[i]) {
			wyn += t[i-1] - t[i];
		}
	}
	return wyn;
}

LL make2() {
	int v = 0;
	FOR(i, 1, n-1) {
		if (t[i-1] > t[i]) {
			v = max(v, t[i-1] - t[i]);
		}
	}
	LL wyn = 0;
	FOR(i, 1, n-1) {
		wyn += min(t[i-1], v);
	}
	return wyn;
}

int main()
{
	int T;
	scanf("%d", &T);
	FOR(testCounter, 1, T){
		//wej
		scanf("%d", &n);
		REP(i, n)
			scanf("%d", &t[i]);
		//prog
		
		//wyj
		printf("Case #%d: %lld %lld\n", testCounter, make1(), make2());
	}
	return 0;
}
