#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#define N 120001
#define oo 1000000000
#define eps 1e-7
using namespace std;
int a[101][101] = {0};
int b[101][101] = {0};
int hash[1001] = {0};
int main()
{
	int tot;
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &tot);
	for (int tt = 1; tt <= tot; tt++)
	{
		int n, m;
		scanf("%d", &n);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				scanf("%d", &a[i][j]);
		scanf("%d", &m);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				scanf("%d", &b[i][j]);
		memset(hash, 0, sizeof(hash));
		for (int i = 1; i <= 4; i++)
		{
			hash[a[n][i]]++;
			hash[b[m][i]]++;
		}
		int num = 0;
		for (int i = 1; i <= 16; i++)
		{
			if (hash[i] == 2)
			{
				if (num == 0) num = i;
				else num = -1;
			}
		}
		if (num == 0)
			printf("Case #%d: Volunteer cheated!\n", tt);
		else if (num == -1)
			printf("Case #%d: Bad magician!\n", tt);
		else
			printf("Case #%d: %d\n", tt, num);
	}
	return 0;
}
