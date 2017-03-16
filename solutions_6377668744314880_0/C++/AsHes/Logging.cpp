#include<bits/stdc++.h>

using namespace std;

int n,x[50][2],y[50][2];

int isLeft(int a[2], int b[2], int c[2]){
     if (((b[0] - a[0])*(c[1] - a[1]) - (b[1] - a[1])*(c[0] - a[0])) == 0)
     {
         return 0;
     }
     else if((((b[0] - a[0])*(c[1] - a[1]) - (b[1] - a[1])*(c[0] - a[0])) > 0)) return 1;
     else   return 2;
}
int solve(int ind)
{
	int ans=1000;
	for(int i=0;i<n;i++)
	{
		y[i][0]=x[i][0]-x[ind][0];
		y[i][1]=x[i][1]-x[ind][1];
	}
	int q[2],c1,c2,temp;
	for(int i=0;i<n;i++)
	{
		if(i==ind)	continue;
		c1=0;c2=0;
		for(int j=0;j<n;j++)
		{
			if(j==i || j==ind)	continue;
			temp=((y[i][0] - y[ind][0])*(y[j][1] - y[ind][1]) - (y[i][1] - y[ind][1])*(y[j][0] - y[ind][0]));
			if(temp>0)
			{
				c1++;
			}
			else if(temp<0)	c2++;
		}
		//printf("%d %d\n",c1,c2);
		ans=min(ans,min(c1,c2));
	}
	return ans;
}
int main()
{
	int t,ind=0,ans[50];
	scanf("%d",&t);
	while(t--)
	{
		ind++;
		scanf("%d",&n);
		for(int i=0;i<n;i++)	ans[i]=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x[i][0],&x[i][1]);
		}
		for(int i=0;i<n;i++)
		{
			ans[i]=solve(i);
		}
		printf("Case #%d:\n",ind);
		for(int i=0;i<n;i++)
		{
			printf("%d\n",ans[i]);
		}
	}
}
