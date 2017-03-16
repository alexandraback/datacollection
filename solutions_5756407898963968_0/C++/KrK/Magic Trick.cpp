#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxc = 16;
const int Maxd = 4;

int t;
int cnt[Maxc + 1];
int B[Maxd][Maxd];
int tot, res;

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		fill(cnt + 1, cnt + Maxc + 1, 0);
		int r; scanf("%d", &r); r--;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++) {
				scanf("%d", &B[i][j]);
				if (i == r) cnt[B[i][j]]++;
			}
		scanf("%d", &r); r--;
		for (int i = 0; i < Maxd; i++)
			for (int j = 0; j < Maxd; j++) {
				scanf("%d", &B[i][j]);
				if (i == r) cnt[B[i][j]]++;
			}
		tot = 0;
		for (int i = 1; i <= Maxc; i++)
			if (cnt[i] == 2) { tot++; res = i; }
		printf("Case #%d: ", tc);
		if (tot == 1) printf("%d\n", res);
		else if (tot > 1) printf("Bad magician!\n");
		else printf("Volunteer cheated!\n");
	}
	return 0;
}