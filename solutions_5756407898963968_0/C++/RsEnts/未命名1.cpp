#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int T, mat[20][20], Ans, Anscnt, ma;
bool Can[20];

int main() {
	int i, j, T0 = 0;
	scanf("%d", &T);
	for( ; T; --T) {
		scanf("%d", &ma);
		memset(Can, 0, sizeof(Can));
		Ans = 0; Anscnt = 0;
		for(i = 1; i <= 4; ++i)
			for(j = 1; j <= 4; ++j)
				scanf("%d", &mat[i][j]);
		for(i = 1; i <= 4; ++i)
			Can[mat[ma][i]] = 1;
		scanf("%d", &ma);
		for(i = 1; i <= 4; ++i)
			for(j = 1; j <= 4; ++j)
				scanf("%d", &mat[i][j]);
		for(i = 1; i <= 4; ++i)
			if(Can[mat[ma][i]]) {
				++Anscnt;
				Ans = mat[ma][i];
			}
		if(Anscnt == 0)
			printf("Case #%d: Volunteer cheated!\n", ++T0);
		if(Anscnt == 1)
			printf("Case #%d: %d\n", ++T0, Ans);
		if(Anscnt > 1)
			printf("Case #%d: Bad magician!\n", ++T0);
	}
	return 0;
}
