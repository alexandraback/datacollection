#include<cstdio>

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++)
	{
		int r[2];
		int used[32] = {0};
		int cnt = 0;
		int ans = 0;
		for(int i = 0; i < 2; i ++)
		{
			int j, k;
			scanf("%d", &r[i]);
			for(j = 1; j <= 4; j ++)
			{
				for(k = 1; k <= 4; k ++)
				{
					int a;
					scanf("%d", &a);
					if(j == r[i])used[a] ++;
				}
			}
		}
		for(int i = 1; i <= 16; i ++)
		{
			if(used[i] >= 2)
			{
				ans = i;
				cnt ++;
			}
		}
		if(cnt == 0)
		{
			printf("Case #%d: Volunteer cheated!\n", cas);
		}
		else if(cnt == 1)
		{
			printf("Case #%d: %d\n", cas, ans);
		}
		else {
			printf("Case #%d: Bad magician!\n", cas);
		}
	}
	return 0;
}
