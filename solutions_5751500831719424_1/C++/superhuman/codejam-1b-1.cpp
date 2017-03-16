#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
    freopen("A-large1b.in","r",stdin);
   freopen("output-2l.out","w",stdout);
    int t,n,cc=1;
	scanf("%d",&t);
	for(cc=1;cc<=t;cc++)
	{
		char s[200][200],c[200][200];
		int b[200][200]={};
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		for(int i=0;i<n;i++)
		{
			int j;
			for(j=0;s[i][j];j++)
				c[i][j]=s[i][j];
			c[i][j]='\0';
		}
		for(int i=0;i<n;i++)
		{
			int j,k;
			c[i][0]=s[i][0];
			k=0;
			for(j=0;s[i][j];j++)
				if(s[i][j] != c[i][k])
				{
					k++;
					c[i][k]=s[i][j];
				}
			k++;
			c[i][k]='\0';
		}
		int flag=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(strcmp(c[i],c[j]))
				{
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)	
		{
			printf("Case #%d: Fegla Won\n",cc);
			continue;
		}
		else
		{
			int k=0,i;
			for(int j=0;j<n;j++)
			{
				i=0;
				for(int l=0;s[j][l];l++)
				{
					if(s[j][l] != c[0][i])
						i++;
					b[j][i]++;
				}
			}
			int ans=0;
			for(int l=0;c[0][l];l++)
			{
				int m=0;
				for(int j=0;j<n;j++)
					m=max(m,b[j][l]);
				int y=0,z;
				for(int j=1;j<m+1;j++)
				{
					y=0;
					for(int p=0;p<n;p++)
						y+= abs(b[p][l]-j);
					if(j==1)
						z=y;
					else
						z=min(z,y);
				}
				ans+=z;
			}
			printf("Case #%d: %d\n",cc,ans);
		}
	}
	
	return 0;
}
