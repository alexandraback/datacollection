#include <iostream>
#include <algorithm>
using namespace std;
int a,b;
int A[5][4];
int B[5][4];
int T;
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		scanf("%d",&a);
		for(int i=1;i<=4;i++)
		{
			for(int j=0;j<4;j++)scanf("%d",&A[i][j]);	
		}
		scanf("%d",&b);
		for(int i=1;i<=4;i++)
		{
			for(int j=0;j<4;j++)scanf("%d",&B[i][j]);	
		}
		int cnt=0,v;

		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(A[a][i]==B[b][j])
				{
					cnt++;
					v=A[a][i];
				}
			}
		}
		if(cnt==1)
		{
			printf("Case #%d: %d\n",cas,v);
		}
		else if(cnt>1)
		{
			printf("Case #%d: Bad magician!\n",cas);
		}
		else
		{
			printf("Case #%d: Volunteer cheated!\n",cas);	
		}
	}
	return 0;
}
