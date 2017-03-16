#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cno=1;cno<=t;cno++)
	{
		int n;
		cin>>n;
		int m=n;
		int a[n],i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<"Case #"<<cno<<": ";
		char o1,o2;
		int max;
		while(m>0)
		{
			if(m>2)
			{
				max=0;
				for(i=1;i<n;i++)
				{
					if(a[i]>a[max])
						max=i;
				}
				a[max]--;
				if(a[max]==0)
					m--;
				o1='A'+max;
				cout<<o1<<" ";
			}
			else
			{
				for(i=0;i<n;i++)
				{
					if(a[i])
					{
						o1='A'+i;
						break;
					}
				}
				i++;
				for(;i<n;i++)
				{
					if(a[i])
					{
						o2='A'+i;
						break;
					}
				}
				a[o1-'A']--;
				if(a[o1-'A']==0)
					m--;
				a[o2-'A']--;
				if(a[o2-'A']==0)
					m--;
				cout<<o1<<o2<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
