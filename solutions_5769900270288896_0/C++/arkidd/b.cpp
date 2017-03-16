/* DIKRA */
/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of DELAPAN.3gp's template -------------- */

#define INF 1000000000

int ntc;
int nr, nc, n;


int main(){
	scanf("%d", &ntc);
	
	FOR(itc, 1, ntc){
		scanf("%d %d %d", &nr, &nc, &n);
		
		int ans = INF;
		REP(mask, 1<<(nr*nc)){
			int a[20][20];
			int cnt = 0;
			REP(i, nr) REP(j, nc){
				a[i][j] = (mask & (1 << (i*nc + j)))?1:0;
				cnt += a[i][j];
			}

			if (cnt != n) continue;

			int temp = 0;
			REP(i, nr) REP(j, nc){
				if (a[i][j] == 0) continue;

				if (i+1 < nr && a[i+1][j] == 1) temp++;
				if (j+1 < nc && a[i][j+1] == 1) temp++;
			}

			MN(ans, temp);
		}

		printf("Case #%d: %d\n", itc, ans);
	}

	return 0;
}
