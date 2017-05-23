#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

// int manage(int *count[][2],int n,int x)
// {
// 	int i,min=999999,dist,j;
// 	for (i=0;i<n;i++)
// 	{
// 		for (j=0;j<n;j++)
// 		{
// 			dist+=abs(count[i][x][0]-count[j][x][0]);
// 		}
// 		if (min>dist)
// 		{
// 			min=dist;
// 		}
// 	}
// 	return min;
// }

int main()
{
	freopen ("input.in","r",stdin);
	freopen ("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	int z;
	for (z=1;z<=t;z++)
	{
		printf("Case #%d: ",z);
		int n;
		scanf("%d",&n);
		char a[n][102];
		for (int j=0;j<n;j++)
			scanf("%s",a[j]);
		int count[100][102][2]={};
		int i,j,flag=0;
		for (i=0;i<n;i++)
		{
			int x=0;
			for (j=0;a[i][j]!='\0';j++)
			{
				if (x==0 && count[i][x][0]==0)
				{
					count[i][x][1]=a[i][j];
					count[i][x][0]++;
					continue;
				}
				if (count[i][x][1]==a[i][j])
					count[i][x][0]++;
				else
				{
					x++;
					count[i][x][1]=a[i][j];
					count[i][x][0]++;
				}				
			}
		}
		int x;
		for (x=0;x<100;x++)
		{
			int prev=count[0][x][1];
			for (i=1;i<n;i++)
			{
				if (count[i][x][1]==prev)
				{
					continue;
				}
				printf("Fegla Won\n");
				flag=1;
			}
			if (flag==1)
				break;
		}
		if (flag==1)
			continue;
		int moves=0;
		for (x=0;x<100;x++)
		{
			int d,min=999999,dist,f;
			for (d=0;d<n;d++)
			{
				dist=0;
				for (f=0;f<n;f++)
				{
					dist+=abs(count[d][x][0]-count[f][x][0]);
				}
				if (min>dist)
				{
					min=dist;
				}
			}
			moves+=min;
		}
		printf("%d\n",moves);
	}
	return 0;
}