/*	Arkadiusz Wróbel - metsuryuu
 *
 *	Konkurs: Google Code Jam 2015
 *	Zadanie: Logging
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

struct Point {
	LL x;
	LL y;
	Point(const LL xx, const LL yy) : x(xx), y(yy) {};
	Point() : x(0), y(0) {};
};


inline bool operator==(const Point &a, const Point &b) {
	return a.x == b.x && a.y == b.y;
}

inline bool cmpXY(const Point &a, const Point &b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

//inline bool cmpYX(const Point &a, const Point &b) {
//	return a.y == b.y ? a.x < b.x : a.y < b.y;
//}

inline LL ilWekt(const LL x1, const LL y1, const LL x2, const LL y2) {
	return x1 * y2 - x2 * y1;
}

//inline LL ilWekt(const PII &a, const PII &b, const PII &c) {  // gdzie x := ST, y := ND (niepolecane)
//	return ilWekt(b.ST - (LL)a.ST, b.ND - (LL)a.ND, c.ST - (LL)a.ST, c.ND - (LL)a.ND);
//}

inline LL ilWekt(const Point &a, const Point &b, const Point &c) {
	return ilWekt(b.x - (LL)a.x, b.y - (LL)a.y, c.x - (LL)a.x, c.y - (LL)a.y);
}

//######################################################################

int n;
vector<Point> p;

int make(const int v) {
	int wyn = n - 1;
	
	REP(u, n) if (v != u) {
		int dodat = 0;
		int ujemn = 0;
		REP(i, n) if (i != v && i != u) {
			LL x = ilWekt(p[v], p[u], p[i]);
			//printf("(%lld %lld) (%lld %lld) (%lld %lld) -> %lld\n", p[v].x, p[v].y, p[u].x, p[u].y, p[i].x, p[i].y, x);
			if (x > 0)
				++dodat;
			else
				++ujemn;
		}
		wyn = min(wyn, dodat);
		wyn = min(wyn, ujemn);
		//if (wyn < 3) {
			//printf("%d %d\n", v, u);
			//printf("  %d %d\n", dodat, ujemn);
		//}
	}
	
	return wyn;
}

int main()
{
	int T;
	scanf("%d", &T);
	FOR(testCounter, 1, T){
		p.clear();
		//wej
		scanf("%d", &n);
		REP(i, n) {
			int x, y;
			scanf("%d%d", &x, &y);
			p.PB(Point(x, y));
		}
		//prog
		
		//wyj
		printf("Case #%d:\n", testCounter);
		REP(i, n) {
			printf("%d\n", make(i));
		}
	}
	return 0;
}
