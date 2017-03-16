#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef __int64 ll;
const int INF = 1000000007;
int a[5][5],b[5][5];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
	int T,i,j,r1,r2,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&r1);
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		scanf("%d",&r2);
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%d",&b[i][j]);
			}
		}
		int ret=-1;
		for(i=1;i<=16;i++)
		{
			int f1=0,f2=0;
			for(j=0;j<4;j++)if(a[r1-1][j]==i)f1=1;
			for(j=0;j<4;j++)if(b[r2-1][j]==i)f2=1;
			if(f1&&f2){if(ret==-1)ret=i;else ret=0;}
		}
		printf("Case #%d: ",ca++);
		if(ret==-1)puts("Volunteer cheated!");
		else if(!ret)puts("Bad magician!");
		else printf("%d\n",ret);
	}
	return 0;
}
