#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,k;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		int a,b,c[4][4],d[4][4],e[16]={0},cnt=0,i,j;
		cin>>a;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				cin>>c[i][j];
			}
			
		}
		cin>>b;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				cin>>d[i][j];
			}
			
		}
		for(i=0;i<4;i++)
		{
			e[c[a-1][i]-1]=e[c[a-1][i]-1] +1;
			e[d[b-1][i]-1]=e[d[b-1][i]-1] +1;
		}
		for(i=0;i<16;i++)
		{
			if(e[i]==2)
			{
				cnt=cnt+1;
			}
		}
		if(cnt==1)
		{
			for(i=0;i<16;i++)
			{
				if(e[i]==2)
				{
					cout<<"Case #"<<k<<": "<<i+1<<endl;
				}
			}
		}
		else if(cnt==0)
		{
			cout<<"Case #"<<k<<": "<<"Volunteer cheated!"<<endl;
		}
		else if (cnt==2||cnt==3||cnt==4) 
		{
			cout<<"Case #"<<k<<": "<<"Bad magician!"<<endl;
		}
	}
	return 0;
}