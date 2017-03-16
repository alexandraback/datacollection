#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,v) for(decltype((v).begin())it=(v).begin();it!=(v).end();++it)
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define SIZE(x) ((int)(x).size())
#define DBG(x) cerr<<">> "<<#x<<" = "<<x<<endl;
const int MX = 1e6 + 5;
const int INF = 1e9 + 5;

int r, c, n, res, t[20][20];

void gen(int x, int y) {
	if(x == r) {
		int xd = 0;
		REP(i,r) REP(j,c) xd += t[i][j];
		if(xd != n) return;
		int unhappy = 0;
		REP(i,r) REP(j,c) 
			if(t[i][j]) {
				if(i != r-1 && t[i+1][j] == 1)
					++ unhappy;
				if(j != c-1 && t[i][j+1] == 1)
					++ unhappy;
			}
		res = min(res, unhappy);
		return;
	}

	t[x][y] = 1;

	if(y == c-1)
		gen(x+1,0);
	else
		gen(x,y+1);
	
	t[x][y] = 0;

	if(y == c-1)
		gen(x+1, 0);
	else
		gen(x,y+1);
}

int main(int argc, char* argv[])
{
	int cases; scanf("%d", &cases); for(int ccc = 1; ccc <= cases; ++ ccc)
	{
		scanf("%d%d%d" ,&r, &c, &n);
		res = INF;

		gen(0,0);

		printf("Case #%d: %d\n", ccc, res);
	}


	return 0;
}
