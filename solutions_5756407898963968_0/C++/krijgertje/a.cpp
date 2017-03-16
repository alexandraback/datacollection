#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  

int a[4][4],b[4][4],A,B;
int cnt[17];
int ans[16],nans;

void run(int casenr) {
	scanf("%d",&A); --A;
	REP(i,4) REP(j,4) scanf("%d",&a[i][j]);
	scanf("%d",&B); --B;
	REP(i,4) REP(j,4) scanf("%d",&b[i][j]);
	memset(cnt,0,sizeof(cnt));
	REP(j,4) ++cnt[a[A][j]];
	REP(j,4) ++cnt[b[B][j]];
	nans=0; FORE(k,1,16) if(cnt[k]==2) ans[nans++]=k;
	if(nans==0) printf("Case #%d: Volunteer cheated!\n",casenr);
	if(nans==1) printf("Case #%d: %d\n",casenr,ans[0]);
	if(nans>=2) printf("Case #%d: Bad magician!\n",casenr);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
