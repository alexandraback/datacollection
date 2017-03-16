#include <cstdio>
#include <algorithm>
#include <cstring>

#define N 10

using namespace std;

#define FOR(i, s, e) for (int i=(s); i<(e); i++)
#define FOE(i, s, e) for (int i=(s); i<=(e); i++)
#define CLR(x, a) memset(x, a, sizeof(x))

int a[N][N], b[N][N], r1, r2, TC;

void solve(int tc){
	scanf("%d", &r1);
	FOR(i, 0, 4) FOR(j, 0, 4) scanf("%d", &a[i][j]);
	scanf("%d", &r2);
	FOR(i, 0, 4) FOR(j, 0, 4) scanf("%d", &b[i][j]);
	
	int ret = -1, cnt = 0;
	
	FOE(k, 1, 16){
		int ok = 1;
		FOR(i, 0, 4) FOR(j, 0, 4)
			if (a[i][j] == k)
				if (i + 1 != r1) ok = 0;
		FOR(i, 0, 4) FOR(j, 0, 4)
			if (b[i][j] == k)
				if (i + 1 != r2) ok = 0;
		if (ok) ret = k, cnt++;
	}
	
	printf("Case #%d: ", tc);
	if (ret == -1) printf("Volunteer cheated!\n");
	else if (cnt > 1) printf("Bad magician!\n");
	else printf("%d\n", ret);
}


int main(){
	scanf("%d", &TC);
	FOR(i, 0, TC) solve(i + 1);
}
