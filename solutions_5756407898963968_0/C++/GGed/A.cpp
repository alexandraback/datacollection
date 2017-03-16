#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

void solve(int tc){
	int r, x, v[20];
	printf("Case #%d: ", tc);
	FOE(i,1,16) v[i] = 1;
	scanf("%d", &r), --r;
	FOR(i,0,4) FOR(j,0,4){
		scanf("%d", &x);
		if (i != r) v[x] = 0;
	}
	scanf("%d", &r), --r;
	FOR(i,0,4) FOR(j,0,4){
		scanf("%d", &x);
		if (i != r) v[x] = 0;
	}
	int sol = -1;
	FOE(i,1,16) if (v[i]){
		if (sol == -1) sol = i;
		else sol = -2;
	}
	if (sol == -1) puts("Volunteer cheated!");
	else if (sol == -2) puts("Bad magician!");
	else printf("%d\n", sol);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
