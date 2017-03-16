#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
#include<unordered_map>
using namespace std;


int a[1000005];
int n, m;

int st[4][2] = {1, 0, 0, 1};
int mp[17][17];

int best;

void func(int p, int msk, int k)
{
	if (k == 0)
	{
		memset(mp, 0, sizeof(mp));
		for (int i = 0; i < n * m; i++)
		{
			if (msk & (1 << i))
				mp[i / m][i % m] = 1;
		}
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!mp[i][j])
					continue;
				for (int k = 0; k < 2; k++)
				{
					int x = i + st[k][0];
					int y = j + st[k][1];
					if (x >= 0 && x < n && y >= 0 && y < m && mp[x][y])
						res++;
				}
			}
		}
		best = min(best, res);
		return;
	}
	if (n*m - p > k)
		func(p + 1, msk, k);
	func(p + 1, msk | (1 << p), k - 1);
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int TT;
	scanf("%d", &TT);
	for (int T = 0; T < TT; T++)
	{
		printf("Case #%d: ", T + 1);
	
		scanf("%d%d", &n, &m);
		int k;
		scanf("%d", &k);
		int cnt = (n / 2 + m % 2) * (m / 2 + m % 2) + (n / 2)*(m / 2);
		/*if (k <= cnt)
		{
			printf("%d\n", 0);
			continue;
		}*/
		best = 1000000000;
		func(0, 0, k);
		printf("%d\n", best);
	}

	return 0;
}