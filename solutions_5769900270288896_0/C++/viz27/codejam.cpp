#include<bits/stdc++.h>
using namespace std;
int a[20];
bool b[20][20];
bool C[20][20],d[20][20];
int r,c;
int mini;
void select(int start,int rest)
{
	int i,j,k,ans;
	if(rest==0)
	{
		for(i=start;i<r*c;i++) a[i]=0;
		k=0;
		for(i=0;i<r;i++)
		{
			//cout<<endl;
		for(j=0;j<c;j++)
		{
			if(a[k]==1) b[i][j]=1;
			else b[i][j]=0;
			k++;
			//cout<<b[i][j]<<' ';
		}
		}
		for(i=0;i<r;i++)
		for(j=0;j<c;j++) C[i][j]=d[i][j]=0;
		
		for(i=0;i<r;i++)
		{
			//cout<<endl;
			for(j=0;j<c-1;j++)
			{
				if(b[i][j]==1 && b[i][j+1]==1) C[i][j]=1;
				//cout<<C[i][j]<<' ';
			}
		}
		for(j=0;j<c;j++)
		{
			//cout<<endl;
			for(i=0;i<r-1;i++)
			{
				if(b[i][j]==1 && b[i+1][j]==1) d[i][j]=1;
				//cout<<d[i][j]<<' ';
			}
		}
		ans=0;
		for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			if(C[i][j]==1) ans++;
			if(d[i][j]==1) ans++;
		}
		//cout<<endl<<ans<<endl;
		if(ans<mini) mini=ans;
	}
	else if(rest>r*c-start) return;
	else
	{
		a[start]=1;
		select(start+1,rest-1);
		a[start]=0;
		select(start+1,rest);
	}
}
	
int main()
{
	int t,n,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>r>>c>>n;
		mini=100000;
		select(0,n);
		cout<<"Case #"<<i<<": "<<mini<<endl;
	}
}
