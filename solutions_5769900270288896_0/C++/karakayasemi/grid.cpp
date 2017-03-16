#include <iostream>
#include <climits>
using namespace std;

int m[20][20];
int minres=INT_MAX;

int dfs(int r,int c,int d,int total,int n)
{
	int i,j,t=0;

	for(int k=0;k<(1<<r*c);k++)
	{
		int g=k;t=0;
		int cur=0;
		int flag=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(g%2==1){m[i][j]=1;}
				else m[i][j]=0;
				if(g%2==1) cur++;
				g/=2;
				if(cur>n) {flag=1;break;}
			}
			if(flag) break;
		}
		if(flag) continue;
		if(cur!=n) continue;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(m[i][j]==1)
				{
					if(i-1>=0 && m[i-1][j]!=0)	t++;
					if(j-1>=0 && m[i][j-1]!=0)	t++;
					if(i+1<r && m[i+1][j]!=0)	t++;
					if(j+1<c && m[i][j+1]!=0)	t++;
				}
			}
		}
		if(minres>t)
			minres=t;
	}
}


int main()
{
	int T;
	int r,c,n;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>r>>c>>n;
		minres=INT_MAX;
		dfs(r,c,0,0,n);
		cout<<"Case #"<<i+1<<": "<<minres/2<<endl;
	}
	return 0;	
}
