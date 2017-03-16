#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("A-large (1).in","r",stdin);
	freopen("q1.out","w",stdout);
	int t;
	cin>>t;
	int kk=0;
	while(t--)
	{
		kk++;
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int l=0,sl=0,il=0,isl=0;
		for(int i=0;i<n;i++)
		{
			if(l<a[i])
			{
				l=a[i];
				il=i;
			}
		}
		for(int i=0;i<n;i++)
		{
			if((sl<a[i])&&(il!=i))
			{
				sl=a[i];
				isl=i;
			}
		}
		char c;
		cout<<"Case #"<<kk<<": ";
		while(l!=sl)
		{
			if(l-sl==0)
			{
				break;
			}
			if(l-sl==1)
			{
				c=65+il;
				cout<<c<<" ";
				l--;
				break;
			}
			c=65+il;
			l=l-2;
			cout<<c<<c<<" ";
		}
		for(int i=0;i<n;i++)
		{
			if((i==il)||(i==isl))
			{
				continue;
			}
			c=65+i;
			while(a[i]!=0)
			{
				if(a[i]==1)
				{
					a[i]--;
					cout<<c<<" ";
				}
				else
				{
					a[i]=a[i]-2;
					cout<<c<<c<<" ";
				}
			}
		}
		while(l!=0)
		{
			c=65+il;
			cout<<c;
			c=65+isl;
			cout<<c<<" ";
			l--;
		}
		cout<<endl;
	}
	return 0;
}
