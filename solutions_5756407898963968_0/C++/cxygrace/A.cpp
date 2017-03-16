#include <iostream>
#include <cstdio>
using namespace std;

int dat[10][10];
bool ans[30];

int work()
{
	for (int i = 1; i <= 16; i++) ans[i] = false;
	int r;
	scanf("%d", &r);
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			scanf("%d", &dat[i][j]);
	for (int i = 1; i <= 4; i++) ans[dat[r][i]] = true;
	
	scanf("%d", &r);
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
		{
			scanf("%d", &dat[i][j]);
			if (i != r) ans[dat[i][j]] = false;
		}
	
	int cnt = 0;
	for (int i = 1; i <= 16; i++)
		if (ans[i]) cnt++;
	
	if (cnt == 0) return -2;
	else if (cnt > 1) return -1;
	else
	{
		for (int i = 1; i <= 16; i++)
			if (ans[i]) return i;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		int res = work();
		printf("Case #%d: ", i);
		if (res > 0) printf("%d\n", res);
		else if (res == -1) printf("Bad magician!\n");
		else printf("Volunteer cheated!\n");
	}
	
	return 0;
}
