#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int cnt[20];
int mat[4][4];

int main ()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int kase; scanf("%d", &kase);
	for (int _ = 1; _ <= kase; _++)
	{
		memset(cnt, 0, sizeof cnt);
		int k; scanf("%d", &k);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				scanf("%d", &mat[i][j]);
		for (int j = 0; j < 4; j++) ++cnt[mat[k - 1][j]];
		scanf("%d", &k);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				scanf("%d", &mat[i][j]);
		for (int j = 0; j < 4; j++) ++cnt[mat[k - 1][j]];
		int res, tcnt = 0;
		for (int i = 1; i <= 16; i++)
			if (cnt[i] == 2) ++tcnt, res = i;
		printf("Case #%d: ", _);
		if (tcnt == 1) printf("%d\n", res);
		else if (tcnt == 0) printf("Volunteer cheated!\n");
		else printf("Bad magician!\n");
	}
}
