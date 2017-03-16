#include<bits/stdc++.h>
using namespace std;
int ans;
int v(int a[100][100],int r,int c)
{
	int z=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i<r-1)
				if(a[i][j]&&a[i+1][j])z++;
			if(j<c-1)
				if(a[i][j]&&a[i][j+1])z++;
		}
	}
	return z;
}
void check(int a[100][100],int i,int j,int r,int c,int n)
{
	if(n==0)
	{
		ans=min(ans,v(a,r,c));
		return;
	}
	if(i>=r||j>=c)return;
	int r1=(j!=c-1)?i:i+1;
	int c1=(j+1)%c;
	check(a,r1,c1,r,c,n);
	a[i][j]=1;
	check(a,r1,c1,r,c,n-1);
	a[i][j]=0;
}
int main()
{
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int r,c,n;
		cin>>r>>c>>n;
		int a[100][100]={{0}};
		ans=10000000;
		check(a,0,0,r,c,n);
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}