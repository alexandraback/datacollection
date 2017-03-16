#include <iostream>
using namespace std;

int arr[17][17][20];

int unhap(int i,int j,int k,int l,int a[5][5],int n,int m)
{
	if (k==n or l==m) return 0;
	else if (a[k][l]==1 and a[i][j]==1) return 1;
	return 0;
}

void sel(int i,int j,int n,int m,int a[5][5])
{
	if (i<n)
	{
		a[i][j]=1;
		sel(i+1,j,n,m,a);
		a[i][j]=0;
		sel(i+1,j,n,m,a);
	}
	if (i==n and j<m)
	{
		a[0][j+1]=1;
		sel(1,j+1,n,m,a);
		a[0][j+1]=0;
		sel(1,j+1,n,m,a);
	}
	else
	{
		int ans=0;
		int un=0;
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (a[i][j]) ans++;
			}
		}
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (unhap(i,j,i+1,j,a,n,m)) un++;
				if (unhap(i,j,i,j+1,a,n,m)) un++;
					
			}
		}
		if (arr[n][m][ans]==-1)
		arr[n][m][ans]=un;
		else
		arr[n][m][ans]=min(arr[n][m][ans],un);
	}
}

int main()
{
	int tt,i,j,k,t,n,m,ans,a[5][5];
	for (i=1;i<=16;i++)
	{
		for (j=1;j<=16;j++)
		{
			for (k=0;k<=(i*j);k++)
			{
				arr[i][j][k]=-1;
			}
		}
	}
	for (i=1;i<=16;i++)
	{
		for (j=i;j<=16;j++)
		{
//			cout<<i<<" "<<j<<endl;
			if (i*j<=16)
				sel(0,0,i,j,a);
		}
	}
/*	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		{
			for (k=0;k<=(i*j);k++)
			{
				cout<<i<<" "<<j<<" "<<k<<" "<<arr[i][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}*/
	cin>>t;
	tt=1;
	while (tt<=t)
	{
		cin>>n>>m>>ans;
		if (n>m)
		{
			int temp=n;
			n=m;
			m=temp;
		}
		cout<<"Case #"<<tt<<": "<<arr[n][m][ans]<<endl;
		tt+=1;
	}
	return 0;
}