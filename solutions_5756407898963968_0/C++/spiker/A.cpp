#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int a[4][4],b[4][4];

int used[16];

int r1,r2;
int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for (int q = 1; q <= t; q++)
	{
		memset(used,0,sizeof(used));
		scanf("%d", &r1);
		r1--;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				scanf("%d", &a[i][j]);
				a[i][j]--;
			}
		scanf("%d", &r2);
		r2--;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				scanf("%d", &b[i][j]);
				b[i][j]--;
			}
		for (int i = 0; i < 4; i++)
			used[a[r1][i]]++;
		for (int i  = 0; i < 4; i++)
			used[b[r2][i]]++;
		int ans = -1;
		int cnt = 0;
		for (int i = 0; i < 16; i++)
			if (used[i] == 2)
			{
				cnt++;
				ans = i + 1;
			}
		if (cnt == 1)
		{
			printf("Case #%d: %d\n", q, ans);
		}
		else
			if (cnt > 1)
			{
				printf("Case #%d: Bad magician!\n", q);
			}
			else
				printf("Case #%d: Volunteer cheated!\n", q);
	}
	return 0;
}