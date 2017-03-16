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

int rm[] = {0,0,1,-1};
int cm[] = {1,-1,0,0};

int solve(int n){
	priority_queue<pair<int, pii> > pq;	
	vector<vector<int> > v;
	v.resize(nr);
	REP(i, nr) v[i].resize(nc);


	int ans = 0;
	REP(i, nr) REP(j, nc){
		v[i][j] = 1;
		if ((i == 0 || i == nr-1) && (j == 0 || j == nc-1)){
			pq.push(MP(2, MP(i,j)));
		} else
		if (i == 0 || i == nr-1 || j == 0 || j == nc-1){
			pq.push(MP(3, MP(i,j)));
		} else {
			pq.push(MP(4, MP(i,j)));
		}
	}

	REP(i, nr) REP(j, nc){
		if (i+1 < nr) ans++;
		if (j+1 < nc) ans++;
	}
	

	for (int move = 0; move < nr*nc - n; ){
		//printf("move = %d\n", move);
		int adj = pq.top().A;
		int r = pq.top().B.A;
		int c = pq.top().B.B;
		pq.pop();

		int cnt = 0;
		REP(i, 4){
			int rr = rm[i]+r;
			int cc = cm[i]+c;

			if (rr < 0 || rr >= nr || cc < 0 || cc >= nc) continue;

			if (v[rr][cc]) cnt++;				
		}

		if (cnt == adj){
			ans -= adj;
			//printf("remove %d %d, decrease %d\n", r, c, adj);
			v[r][c] = 0;
			move++;
		} else {
			pq.push(MP(cnt, MP(r,c)));
		}
	}

	return ans;
}

int solve2(int n){
	priority_queue<pair<int, pii> > pq;	
	vector<vector<int> > v;
	v.resize(nr);
	REP(i, nr) v[i].resize(nc);


	int ans = 0;
	REP(i, nr) REP(j, nc){
		v[i][j] = 1;
		if ((i == 0 || i == nr-1) && (j == 0 || j == nc-1)){
			pq.push(MP(2, MP(i,j)));
		} else
		if (i == 0 || i == nr-1 || j == 0 || j == nc-1){
			pq.push(MP(3, MP(i,j)));
		} else {
			pq.push(MP(4, MP(i,j)));
		}
	}

	REP(i, nr) REP(j, nc){
		if (i+1 < nr) ans++;
		if (j+1 < nc) ans++;
	}
	

	for (int move = 0; move < nr*nc - n; ){
		//printf("move = %d\n", move);
		int adj = pq.top().A;
		int r = pq.top().B.A;
		int c = pq.top().B.B;
		pq.pop();

		int cnt = 0;
		REP(i, 4){
			int rr = rm[i]+r;
			int cc = cm[i]+c;

			if (rr < 0 || rr >= nr || cc < 0 || cc >= nc) continue;

			if (v[rr][cc]) cnt++;				
		}

		if (cnt == adj){
			ans -= adj;
			//printf("remove %d %d, decrease %d\n", r, c, adj);
			v[r][c] = 0;
			move++;
		} else {
			pq.push(MP(cnt, MP(r,c)));
		}
	}

	ans = 0;
	REP(i, nr) REP(j, nc){
		if (v[i][j] == 1) continue;

		if (i+1 < nr && v[i+1][j] == 0) ans++;
		if (j+1 < nc && v[i][j+1] == 0) ans++;
	}

	return ans;
}

int main(){
	scanf("%d", &ntc);
	
	FOR(itc, 1, ntc){
		scanf("%d %d %d", &nr, &nc, &n);
		
		int a1 = solve(n);
		int a2 = solve2(nr*nc - n);

		printf("Case #%d: %d\n", itc, min(a1, a2));
	}

	return 0;
}
