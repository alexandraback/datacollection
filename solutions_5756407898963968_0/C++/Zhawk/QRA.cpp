#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int A[10][10];
int ss[10];
int tt = 1;
void solve(void)
{
	int s1;
	scanf("%d",&s1);
	int i,j;
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			scanf("%d",&A[i][j]);
	for(i=1;i<=4;i++)
		ss[i] = A[s1][i];
	int s2;
	scanf("%d",&s2);
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			scanf("%d",&A[i][j]);
	int ps = 0;
	int ans = 0;
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
		if(A[s2][i]==ss[j])
		{
			ps++;
			ans = ss[j];
		}
	printf("Case #%d: ",tt++);
	if(ps==0)
		printf("Volunteer cheated!\n");
	 if(ps==1)
		printf("%d\n",ans);
	if(ps>1)
		printf("Bad magician!\n");
	
}


int main(void)
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		solve();
	}
	

	return 0;
}