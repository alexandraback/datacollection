#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 51;
const int MAXM = 2000011;
const int MAXK = 201;
const int INF = 1000000001;
const double eps = 1e-5;

int a[MAXK][MAXK];
int b[MAXK][MAXK];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cas,T,i,j,q1,q2,flag,ans;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d",&q1);
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				scanf("%d",&a[i][j]);
		scanf("%d",&q2);
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				scanf("%d",&b[i][j]);
		q1--; q2--;
		flag=0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(a[q1][i]==b[q2][j])
				{
					flag++;
					ans=a[q1][i];
				}
		printf("Case #%d: ",cas);
		if(flag==0)
			printf("Volunteer cheated!\n");
		else
			if(flag==1)
				printf("%d\n",ans);
			else
				printf("Bad magician!\n");
	}
	return 0;
	
}