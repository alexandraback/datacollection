#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int ans,n,m;
int a[16][16];
bool mark[1000000];
int count1();
int getNum();
void coutArray()
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
void rec(int left)
{
//	coutArray();
	if(left==0)
	{
		ans=min(ans,count1());
		return;
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			if(a[i][j]==0)
			{
				a[i][j]=1;
				int x=getNum();
				if(!mark[x])
				{
					mark[x]=true;
					rec(left-1);
				}
				a[i][j]=0;
			}
		}
}
int getNum()
{
	int two=1;
	int ans=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			ans+=two*a[i][j];
			two*=2;
		}
	return ans;
}
int count1()
{
	int ans=0;
	int px[4]={0,0,1,-1};
	int py[4]={1,-1,0,0};
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(a[i][j]==1)
			for(int k=0;k<4;++k)
			{
				int x=i+px[k];
				int y=j+py[k];
				if( x>=0 && x<n && y>=0 && y<m)
					if(a[x][y]==1)
						++ans;
			}
	return ans;
			
}
int main()
{
	if( true)
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	int t;
	cin>>t;
	for(int k=1;k<=t;++k)
	{
		ans=10000;
		int q,r,c;
		cin>>r>>c>>q;
		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)
				a[i][j]=0;
		for(int i=0;i<1000000;++i)
			mark[i]=false;
		n=r;
		m=c;
		rec(q);
		cout<<"Case #"<<k<<": "<<ans/2<<endl;
	}
	return 0;
}