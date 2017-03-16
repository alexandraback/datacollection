#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
static bool a[16+1];
void f()
{
	int i,j;
	int x;
	cin>>x;
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=4;j++)
		{
			int k;
			cin>>k;
			a[k]=a[k]&&(i==x);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int t,ti;
	cin>>t;
	for (ti=1;ti<=t;ti++)
	{
		memset(a,true,sizeof(a));
		int i;
		f();
		f();
		int n,x;
		n=0;
		for (i=1;i<=16;i++)
		{
			if (a[i])
			{
				x=i;
				n++;
			}
		}
		cout<<"Case #"<<ti<<": ";
		if (n>1)
		{
			cout<<"Bad magician!"<<endl;
		}
		else if (n==0)
		{
			cout<<"Volunteer cheated!"<<endl;
		}
		else
		{
			cout<<x<<endl;
		}
	}
	return 0;
}
