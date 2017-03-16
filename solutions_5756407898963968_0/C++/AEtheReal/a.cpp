#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

int x[2][4][4];
int a[2];

int main() {	
int nt; scanf("%d", &nt); FOR(tt,1,nt+1){
	FOR(it,0,2){
		scanf("%d", &a[it]); a[it]--;
		FOR(i,0,4)FOR(j,0,4){
			scanf("%d", &x[it][i][j]);
			x[it][i][j]--;
		}
	}
	int ans = -1;
	int nans = 0;
	FOR(k,0,16){
		int nm = 0;
		FOR(it,0,2)FOR(j,0,4) if(x[it][a[it]][j] == k) nm++;
		if(nm == 2){
			ans = k;
			nans ++;
		}
	}
	printf("Case #%d: ", tt);
	if(nans == 0) printf("Volunteer cheated!\n");
	else if(nans > 1) printf("Bad magician!\n");
	else printf("%d\n", ans+1);
}	
return 0;
}


