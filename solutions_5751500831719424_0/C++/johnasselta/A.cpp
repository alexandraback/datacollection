#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define MAXN 107
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

int n,testy;
int pom[MAXN];
char s[MAXN][MAXN];
vector<pair<char,int> > wyn[MAXN]; 

void zamien(int kt) {
	int dl = strlen(s[kt]);
	
	int ile = 0;
	REP(i,dl) {
		if (i && s[kt][i] != s[kt][i-1]) {
			wyn[kt].PB(MP(s[kt][i-1],ile));
			ile = 0;
		}
		++ile;
	}
	wyn[kt].PB(MP(s[kt][dl-1],ile));
}

int check() {
	int wiel = int(wyn[0].size());
	FOR(i,1,n-1) {
		if (wyn[i].size() != wyn[i-1].size()) return -1;
		REP(j,wiel) if (wyn[i][j].ST != wyn[i-1][j].ST) return -1;
	}
	
	int res = 0;
	REP(j,wiel) {
		REP(i,n) pom[i] = wyn[i][j].ND;
		sort(pom,pom+n);
		REP(i,n) res += abs(pom[i]-pom[n/2]);
	}
	return res;
}

int main(){
	scanf("%d",&testy);
	FOR(g,1,testy) {
		printf("Case #%d: ",g);
		scanf("%d",&n);
		REP(i,n) wyn[i].clear();
		REP(i,n) scanf(" %s",s[i]);
		REP(i,n) zamien(i);
		
		int res = check();
		if (res == -1) puts("Fegla Won");
		else printf("%d\n",res);
	}
	return 0;
}
