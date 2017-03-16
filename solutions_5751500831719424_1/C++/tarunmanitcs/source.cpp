#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<string>
using namespace std;
int main()
{
	freopen("C:\\Users\\Tarun\\Desktop\\ip.txt","r",stdin);
	freopen("C:\\Users\\Tarun\\Desktop\\op.txt","w",stdout);
	int t,n,i,j,k,l;
	string a[105],b[105];
	cin>>t;
	for(l=1;l<=t;l++)
	{
	vector<int >c[105];
		cout<<"Case #"<<l<<": ";
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
		{
			b[i]="";
			b[i]+=a[i][0];
			c[i].push_back(1);
			for(j=1;j<a[i].size();j++)
			{
				if(a[i][j]!=b[i][b[i].size()-1])
				{
					b[i]+=a[i][j];
					c[i].push_back(1);
				}
				else
					c[i][c[i].size()-1]++;
			}
		}
		for(i=1;i<n;i++)
		{
			if(b[i]!=b[0])
			{
				cout<<"Fegla Won\n";
				break;
			}
		}
		if(i==n)
		{
			int ans=0;
			for(i=0;i<c[0].size();i++)
			{
				int min=1000000000;
				for(j=0;j<n;j++)
				{
					int sum=0;
					for(k=0;k<n;k++)
					{
						sum=sum+abs(c[k][i]-c[j][i]);
					}
					if(sum<min)
						min=sum;
				}
				ans=ans+min;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}