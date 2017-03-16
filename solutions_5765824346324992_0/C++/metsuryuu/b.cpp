/*	Arkadiusz Wróbel - metsuryuu
 *
 *	Konkurs: Google Code Jam 2015
 *	Zadanie: Haircut
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

int b, n;
int t[1024];  // liczba minut na jednego klienta

LL makeNww() {
	LL wyn = 1;
	FOR(i, 1, b) {
		int nwd = __gcd(wyn, LL(t[i]));
		wyn /= nwd;
		wyn *= t[i];
	}
	return wyn;
}

int brut() {
	priority_queue<PII> Q;
	FOR(i, 1, b) {
		Q.push(MP(0, -i));
	}
	for (int i = 1; i < n; ++i) {
		PII v = Q.top();
		Q.pop();
		v.ST -= t[-v.ND];
		Q.push(v);
	}
	return -(Q.top().ND);
}

int main()
{
	int T;
	scanf("%d", &T);
	FOR(testCounter, 1, T){
		//wej
		scanf("%d%d", &b, &n);
		FOR(i, 1, b) {
			scanf("%d" , &t[i]);
		}
		//prog
		LL nww = makeNww();
		LL cykl = 0;
		FOR(i, 1, b) {
			cykl += nww / t[i];
		}
		n %= cykl;
		if (n == 0) {
			n = cykl;
		}
		
		//wyj
		printf("Case #%d: %d\n", testCounter, brut());
	}
	return 0;
}
