#include <stdio.h>

int main(int argc, char **argv)
{
	int T, x, y, a, i, j;
	int n[17];
	scanf("%d ", &T);
	for (x = 1; x <= T; x++)
	{
		for (i = 1; i <= 16; i++) n[i] = 0;
		scanf("%d ", &a);
		for (i = 1; i < a; i++) scanf("%d %d %d %d ", &j, &j, &j, &j);
		scanf("%d ", &j); n[j] = 1;
		scanf("%d ", &j); n[j] = 1;
		scanf("%d ", &j); n[j] = 1;
		scanf("%d ", &j); n[j] = 1;
		for (; i < 4; i++) scanf("%d %d %d %d ", &j, &j, &j, &j);
		y = 0;
		scanf("%d ", &a);
		for (i = 1; i < a; i++) scanf("%d %d %d %d ", &j, &j, &j, &j);
		scanf("%d ", &j); if (n[j] == 1) { y++; a = j; }
		scanf("%d ", &j); if (n[j] == 1) { y++; a = j; }
		scanf("%d ", &j); if (n[j] == 1) { y++; a = j; }
		scanf("%d ", &j); if (n[j] == 1) { y++; a = j; }
		for (; i < 4; i++) scanf("%d %d %d %d ", &j, &j, &j, &j);
		if (y == 0) printf("Case #%d: Volunteer cheated!\n", x);
		else if (y == 1) printf("Case #%d: %d\n", x, a);
		else printf("Case #%d: Bad magician!\n", x);
	}
	return 0;
}