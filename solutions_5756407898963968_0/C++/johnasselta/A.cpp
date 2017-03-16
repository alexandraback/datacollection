#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define MAXN
#define INF
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(a,b,c) for(int a=b;a<=(c);a++)
#define FORD(a,b,c) for (int a=b;a>=(c);a--)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)

using namespace std;

typedef long long LL;  

int test;
int odp[2], t[4][4][2];
int ile[17], ilosc;

int main(){
	scanf("%d",&test);
	FOR(g,1,test) {
		printf("Case #%d: ",g);
		
		REP(k,2) {
			scanf("%d",&odp[k]);
			REP(i,4) REP(j,4) scanf("%d",&t[i][j][k]);
		}
		
		REP(k,2) REP(j,4) ile[t[odp[k]-1][j][k]]++;
		FOR(i,1,16) if (ile[i] == 2) ++ilosc;
		
		if (ilosc == 0) puts("Volunteer cheated!");
		if (ilosc > 1) puts("Bad magician!");
		if (ilosc == 1) FOR(i,1,16) if (ile[i] == 2) printf("%d\n",i);
		
		ilosc = 0;
		FOR(i,1,16) ile[i] = 0; 
	}
	return 0;
}
