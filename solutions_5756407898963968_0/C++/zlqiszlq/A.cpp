#include<cstdio>
#include<cstring>
using namespace std;

int T;
int A[4][4],B[4][4];

bool Vis[4*4+10];

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int i,j,k,aa,ab;
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++)
	{
		scanf("%d",&aa);
		aa--;
		for (i=0;i<4;i++)
		{
			for (j=0;j<4;j++)
			{
				scanf("%d",&A[i][j]);
			}
		}
		scanf("%d",&ab);
		ab--;
		for (i=0;i<4;i++)
		{
			for (j=0;j<4;j++)
			{
				scanf("%d",&B[i][j]);
			}
		}
		memset(Vis,0,sizeof Vis);
		for (j=0;j<4;j++)
		{
			Vis[A[aa][j]] = 1;
		}
		k = 0;
		int ans;
		for (j=0;j<4;j++)
		{
			if (Vis[B[ab][j]])
			{
				++k;
				ans = B[ab][j];
			}
		}
		printf("Case #%d: ",cases);
		if (k == 0)
		{
			printf("Volunteer cheated!");
		}
		else if (k == 1)
		{
			printf("%d",ans);
		}
		else
		{
			printf("Bad magician!");
		}
		printf("\n");
	}
	return 0;
}
