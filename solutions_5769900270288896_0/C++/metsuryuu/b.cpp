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

//const int wekt[4][2] {
	//{0, 1},
	//{0, -1},
	//{1, 0},
	//{-1, 0}
//};

int n, m, r;

int t[32][32];
int ile;

int wy;

void dalej(const int y, const int x, const int d) { // TODO przerywać kiedy trzeba
	if (d == r) {
		if (ile < wy) {
			wy = ile;
			//printf("(%d %d %d %d)\n", n, m, r, d);
			//FOR(i, 1, n) {FOR(j, 1, m) printf(" %d", t[i][j]); printf("\n");}
			//printf("---------\n");
			return;
		}
	}
	
	if (y > n) {
		return;
	}
	if (x > m) {
		dalej(y+1, 1, d);
		return;
	}
	
	dalej(y, x+1, d);
	
	t[y][x] = 1;
	if (t[y][x-1])
		++ile;
	if (t[y-1][x])
		++ile;
	
	dalej(y, x+1, d+1);
	
	t[y][x] = 0;
	if (t[y][x-1])
		--ile;
	if (t[y-1][x])
		--ile;
}

int main()
{
	int T;
	scanf("%d", &T);
	FOR(testCounter, 1, T){
		//wej
		scanf("%d%d%d", &n, &m, &r);
		//prog
		wy = INF;
		dalej(1, 1, 0);
		//wyj
		printf("Case #%d: %d\n", testCounter, wy);
	}
	return 0;
}
