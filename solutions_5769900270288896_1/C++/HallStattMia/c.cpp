#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;
const int p[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,r,c;
int a[10000][10000];
int b[10000];
int s,ans,need,pans;
void work1()
{
		need=r*c/2;
	need=n-need;
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
	if((i+j)%2==1)a[i][j]=1;
	else a[i][j]=0;
	for(int i=0;i<=4;i++)b[i]=0;
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
	if(a[i][j]==0)
	{
		s=0;
		for(int k=0;k<4;k++)
		{
			int x=i+p[k][0],y=j+p[k][1];
			if(x>0 && x<=r && y>0 && y<=c) s+=a[x][y];
		}
		b[s]++;
	}
	int i=0;
	ans=0;
	while(need>0)
	{
		while(b[i]==0)i++;
		b[i]--;
		need--;
		ans+=i;
	}
	pans=ans;
}
void work2()
{
	need=(r*c+1)/2;
	need=n-need;
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
	if((i+j)%2==0)a[i][j]=1;else a[i][j]=0;
	for(int i=0;i<=4;i++)b[i]=0;
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
	if(a[i][j]==0)
	{
		s=0;
		for(int k=0;k<4;k++)
		{
			int x=i+p[k][0],y=j+p[k][1];
			if(x>0 && x<=r && y>0 && y<=c) s+=a[x][y];
		}
		b[s]++;
	}
	int i=0;
	ans=0;
	while(need>0)
	{
		while(b[i]==0)i++;
		b[i]--;
		need--;
		ans+=i;
	}
	pans=min(pans,ans);
}
void task()
{
	scanf("%d%d%d",&r,&c,&n);
	work1();work2();
	printf("%d\n",pans);
	
}
int main()
{

	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		task();
	}
	//for(int i=1;i<=20;i++)cout<<f[i]<<endl;
}
