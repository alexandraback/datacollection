#pragma warning(disable:4996)
#include<stdio.h>
int w[18][2];
int main()
{
	int TC, T, a, x1, x2, i, j, t, c;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
		scanf("%d", &x1);
		for (i = 1; i <= 4; i++){
			for (j = 1; j <= 4; j++){
				scanf("%d", &a);
				w[a][0] = i;
			}
		}
		scanf("%d", &x2);
		for (i = 1; i <= 4; i++){
			for (j = 1; j <= 4; j++){
				scanf("%d", &a);
				w[a][1] = i;
			}
		}
		c = 0;
		for (i = 1; i <= 16; i++){
			if (w[i][0] == x1 && w[i][1] == x2){
				c++;
				t = i;
			}
		}
		if (!c) printf("Volunteer cheated!\n");
		else if(c > 1) printf("Bad magician!\n");
		else printf("%d\n", t);
	}
}