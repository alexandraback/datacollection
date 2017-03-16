#include<iostream>
using namespace std;
int g[17][17];
int ans[17][17][17];
void check(int r,int c)
{
	int ct=0;
	int cn=0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			if(g[i][j]==1)
				cn++;
			if(j-1>=0&&g[i][j-1]==1&&g[i][j]==1)
				ct++;
			if(j+1<c&&g[i][j+1]==1&&g[i][j]==1)
				ct++;
			if(i-1>=0&&g[i-1][j]==1&&g[i][j]==1)
				ct++;
			if(i+1<r&&g[i+1][j]==1&&g[i][j]==1)
				ct++;
			
		}
	ct/=2;
	if(ct<ans[r][c][cn])
	{
	//	if(r==2&&c==3&&cn==6)
	//		cout<<ct<<"\n";
		ans[r][c][cn]=ct;
	}
	return ;

}
int main()
{
	for(int i=0;i<17;i++)
		for(int j=0;j<17;j++)
			for(int k=0;k<17;k++)
				ans[i][j][k]=100000;
	int pow[20];
	pow[0]=1;
	for(int i=1;i<17;i++)
	{
		pow[i]=2*pow[i-1];
	//	cout<<pow[i]<<" ";
	}

	for(int i=1;i<=16;i++)
	{
		for(int j=1;j<=16;j++)
		{
			if(i*j>16)
				continue;
			for(int k=0;k<pow[i*j];k++)
			{
				int t=k;
				for(int l=0;l<i*j;l++)
					g[l/j][l%j]=0;
				for(int l=0;l<i*j;l++)
				{
					g[l/j][l%j]=t%2;
					t=t/2;
				}
				check(i,j);
			}
		}
	}
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int r,c,n;
		cin>>r>>c>>n;
		cout<<"Case #"<<i<<": "<<ans[r][c][n]<<"\n";
	}
	return 0;
}
