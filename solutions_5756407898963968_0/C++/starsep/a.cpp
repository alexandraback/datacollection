#include <cstdio>
#include <algorithm>
using namespace std;
void solve()
{
	int a[4][4];
	int b[4][4];
	int lol[8];
	int x,y;
	scanf("%d",&x);
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			scanf("%d",&a[i][j]);
	scanf("%d",&y);
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			scanf("%d",&b[i][j]);
	x--;y--;
	for(int i=0;i<4;i++)
		lol[i]=a[x][i];
	for(int i=4;i<8;i++)
		lol[i]=b[y][i-4];
	sort(lol,lol+8);
	int q=0;
	for(int i=0;i<7;i++)
		if(lol[i]==lol[i+1])
			q++;
	if(q==0)
		printf("Volunteer cheated!\n");
	else if(q>1)
		printf("Bad magician!\n");
	else
	{
		for(int i=0;i<7;i++)
			if(lol[i]==lol[i+1])
				printf("%d\n",lol[i]);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
}