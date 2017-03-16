#define _CRT_SECURE_NO_WARNINGS C4996
#include <stdio.h>
int T,P;
int n,r,c;
int data[32][32];
int minget = 0x7ffffff;
void su(int x, int y, int num)
{
	if (x == r+1 && y==1)
	{
		if (num == 0)
		{
			int i, a,cnt=0;
			for (i = 1; i <= r; i++)
			{
				for (a = 1; a <= c; a++)
				{
					if (data[i][a] && data[i][a - 1]) cnt++;
					if (data[i][a] && data[i - 1][a]) cnt++;
				}
			}
			if (minget > cnt) minget = cnt;
		}
		return;
	}
	if (y == c)
	{
		data[x][y] = 0;
		su(x + 1, 1, num);
		data[x][y] = 1;
		if (num > 0) su(x + 1, 1, num - 1);
		data[x][y] = 0;
	}
	else
	{
		data[x][y] = 0;
		su(x, y+1, num);
		data[x][y] = 1;
		if (num > 0) su(x, y+1, num - 1);
		data[x][y] = 0;
	}
}
int main()
{
	int i;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	while (T)
	{
		scanf("%d%d%d", &r, &c, &n);

		su(1, 1, n);

		printf("Case #%d: %d\n", ++P, minget);
		minget = 0x7fffffff;
		T--;
	}

	return 0;
}
