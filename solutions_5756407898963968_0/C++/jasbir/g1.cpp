#include<cstdio>
using namespace std;
int find_common(int a[][4],int b[][4],int c,int d)
{
	int ans=-1;
	int count=0;
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)	
	if(a[c][i]==b[d][j])
	{count ++;ans=a[c][i];
	}
   
	if(count ==1) return ans;
	if(count ==0) return -1;
	if(count>1) return -2;
}
int main()
{
	int ntc;
	int a[4][4],b[4][4];
	int x,y;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		scanf("%d",&x);
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		scanf("%d",&a[i][j]);
		scanf("%d",&y);
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		scanf("%d",&b[i][j]);
		int ans=find_common(a,b,x-1,y-1);
		if(ans>0) printf("%d\n",ans);
		if(ans==-1) printf("Volunteer cheated!\n");
		if(ans==-2) printf("Bad magician!\n");
	}
}
