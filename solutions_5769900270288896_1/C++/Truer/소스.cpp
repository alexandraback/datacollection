#define _CRT_SECURE_NO_WARNINGS C4996
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int T,P;
int n,r,c;
int data[32][32],ans[32][32];
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
			if (minget > cnt)
			{
				minget = cnt;
				for (i = 1; i <= r; i++)
				{
					for (a = 1; a <= c; a++)
					{
						ans[i][a] = data[i][a];
					}
				}
			}
		}
		return;
	}
	if (y == c)
	{
		data[x][y] = 1;
		if (num > 0) su(x + 1, 1, num - 1);
		data[x][y] = 0;
		data[x][y] = 0;
		su(x + 1, 1, num);
	}
	else
	{
		data[x][y] = 1;
		if (num > 0) su(x, y + 1, num - 1);
		data[x][y] = 0;
		data[x][y] = 0;
		su(x, y+1, num);
	}
}
int sol1(int n2)
{
	int ans = 0;
	int i, a;
	for (i = 1; i <= r; i++)
	{
		for (a = 1; a <= c; a++)
		{
			if (!((i + a) % 2) && n2 > 0) n2--;
		}
	}
	//if (n2 == 0) break;
	for (i = 1; i <= r; i++)
	{
		for (a = 1; a <= c; a++)
		{
			if ((i == 1 && a == 1) || (i == 1 && a == c) || (i == r && a == 1) || (i == r && a == c))
			{
				if (((i + a) % 2) && n2 > 0){
					if (c == 1 || r == 1) ans += 1;
					else ans += 2;
					n2--;
				}
			}
		}
	}
	for (i = 1; i <= r; i++)
	{
		for (a = 1; a <= c; a++)
		{
			if (((i + a) % 2) && n2 > 0 && !((i == 1 && a == 1) || (i == 1 && a == c) || (i == r && a == 1) || (i == r && a == c)) && (i == 1 || i == r || a == 1 || a == c))
			{
				if (n2 > 0){
					if (c == 1 || r == 1) ans += 2;
					else ans += 3;
					n2--;
				}
			}
		}
	}
	for (i = 1; i <= r; i++)
	{
		for (a = 1; a <= c; a++)
		{
			if (((i + a) % 2) && n2 > 0 && !((i == 1 && a == 1) || (i == 1 && a == c) || (i == r && a == 1) || (i == r && a == c)) && !(i == 1 || i == r || a == 1 || a == c))
			{
				if (n2 > 0){
					ans += 4;
					n2--;
				}
			}
		}
	}

	return ans;
}
int main()
{
	int i,a;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	srand(time(NULL));
	int cnt = 0;
	while (T)
	{
		scanf("%d%d%d", &r, &c, &n);

		//++P;
		int n2 = n;
		int ans = 0,ans1=0;
		ans1 = sol1(n);
		for (i = 1; i <= r; i++)
		{
			for (a = 1; a <= c; a++)
			{
				if ((i + a) % 2 && n2 > 0) n2--;
			}
		}
		for (i = 1; i <= r; i++)
		{
			for (a = 1; a <= c; a++)
			{
				if ((i == 1 && a == 1) || (i == 1 && a == c) || (i == r && a == 1) || (i == r && a == c))
				{
					if (!((i + a) % 2) && n2 > 0){
						if(c==1 || r==1) ans += 1;
						else ans += 2;
						n2--;
					}
				}
			}
		}
		for (i = 1; i <= r; i++)
		{
			for (a = 1; a <= c; a++)
			{
				if (!((i + a) % 2) && n2 > 0 && !((i == 1 && a == 1) || (i == 1 && a == c) || (i == r && a == 1) || (i == r && a == c)) && (i == 1 || i == r || a == 1 || a == c))
				{
					if (n2 > 0){
						if(c==1 || r==1) ans += 2;
						else ans += 3;
						n2--;
					}
				}
			}
		}
		for (i = 1; i <= r; i++)
		{
			for (a = 1; a <= c; a++)
			{
				if (!((i + a) % 2) && n2 > 0 && !((i == 1 && a == 1) || (i == 1 && a == c) || (i == r && a == 1) || (i == r && a == c)) && !(i == 1 || i == r || a == 1 || a == c))
				{
					if (n2 > 0){
						ans += 4;
						n2--;
					}
				}
			}
		}
		if (ans > ans1) ans = ans1;
		printf("Case #%d: %d\n", ++P, ans);
		/*if (ans == minget) printf("Test:%d..OK!\n", P);
		else
		{
			printf("Test:%d..Wrong!\n", P);
			printf("Your Answer:%d\n", ans);
			printf("Correct Answer:%d\n", minget);
			printf("%d %d %d", r, c, n);
			cnt++;
		}
		minget = 0x7fffffff;*/

		T--;
	}

	return 0;
}
