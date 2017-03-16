#include <cstdio>
using namespace std;

int T, i, a, j, x, b[100], ans;

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int Q = 1; Q <= T; Q++) {
		scanf("%d", &a);
		for (i = 1; i <= 16; i++)	b[i] = 0;
		for (i = 1; i <= 4; i++)
			for (j = 1; j <= 4; j++) {
				scanf("%d", &x);
				if (i == a)	b[x]++;
			}
		scanf("%d", &a);
		for (i = 1; i <= 4; i++)
			for (j = 1; j <= 4; j++) {
				scanf("%d", &x);
				if (i == a)	b[x]++;
			}
		ans = 0;
		for (i = 1; i <= 16; i++)	if (b[i] == 2)	ans++;
		if (!ans)	printf("Case #%d: Volunteer cheated!\n", Q);
		else	if (ans > 1)	printf("Case #%d: Bad magician!\n", Q);
		else {
			for (i = 1; i <= 16; i++)	if (b[i] == 2)	printf("Case #%d: %d\n", Q, i);
		}
	}
}
