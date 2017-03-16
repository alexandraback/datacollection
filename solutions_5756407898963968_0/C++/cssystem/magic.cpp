/*
Author:wuhuajun
*/
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef double dd;
const int maxn=210;

int T,r1,r2,a[5][5],b[5][5];
int f[maxn];

void close()
{
exit(0);
}


void init()
{
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
	scanf("%d",&T);
	for (int cas = 1;cas <= T;cas++)
	{
		printf("Case #%d: ",cas);
		memset(f,0,sizeof(f));
		scanf("%d",&r1);
		for (int i=1;i<=4;i++)
			for (int j=1;j<=4;j++)
				scanf("%d",&a[i][j]);
		scanf("%d",&r2);
		for (int i=1;i<=4;i++)
			for (int j=1;j<=4;j++)
				scanf("%d",&b[i][j]);
		for (int i=1;i<=4;i++)
			f[a[r1][i]] = 1;
		int cnt = 0, ans = 0;
		for (int i=1;i<=4;i++)
			if (f[b[r2][i]] == 1)
			{
				ans = b[r2][i];
				cnt++;
			}
		if (cnt >= 2)
			printf("Bad magician!\n");
		if (cnt == 0)
			printf("Volunteer cheated!\n");
		if (cnt == 1)
			printf("%d\n",ans);
	}
}

int main ()
{
	init();
	close();
	return 0;
}

