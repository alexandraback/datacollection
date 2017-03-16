#include <cstdio>
#include <cstring>

int test,a[5][5],b[5][5],n,m;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&test);
	for (int T = 1; T <= test; T++)
	{
		scanf("%d",&n); n--;
		for (int i = 0; i < 16; i++) scanf("%d",a[i / 4] + (i % 4));
		scanf("%d",&m);
		for (int i = 0; i < 16; i++) scanf("%d",b[i / 4] + (i % 4));
		m--;
		int ans = -1;
		for (int i = 0; i < 4 && ans >= -1; i++) for (int j = 0; j < 4 && ans >= -1; j++) if (a[n][i] == b[m][j])
		{
			if (ans == -1) ans = a[n][i]; else
			if (ans > -1) ans = -2;
		}
		printf("Case #%d: ",T);
		if (ans >= 0) printf("%d\n",ans); else
		if (ans == -1) puts("Volunteer cheated!"); else
			puts("Bad magician!");
	}
}
