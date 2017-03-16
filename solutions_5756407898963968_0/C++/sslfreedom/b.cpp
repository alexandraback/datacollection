#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std; 

int n, m, cas;
int a[10][10], b[10][10];
int used[100];
void work()
{
	int x, y;
	scanf("%d", &x);
	for (int i=1; i<=4; ++i)
		for (int j=1; j<=4; ++j)
			scanf("%d", &a[i][j]);
	scanf("%d", &y);
	for (int i=1; i<=4; ++i)
		for (int j=1; j<=4; ++j)
			scanf("%d", &b[i][j]);
	memset(used, 0, sizeof(used));
	for (int i=1; i<=4; ++i)
	{
		++used[a[x][i]];
		++used[b[y][i]];
	}
	int s=0, tmp=0;
	for (int i=1; i<=16; ++i)
		if (used[i]>1) 
		{
			++s; 
			tmp=i;
		}
	if (s==0)
		printf("Volunteer cheated!\n");
	else if (s>1)
		printf("Bad magician!\n");
	else printf("%d\n", tmp);
}

int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d", &cas);
	for (int i=1; i<=cas; ++i)
	{
		printf("Case #%d: ", i);
		work();
	}
	return 0;
}
