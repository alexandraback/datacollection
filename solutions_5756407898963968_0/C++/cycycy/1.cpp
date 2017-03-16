#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin>>t;
	int a,b;
	int s[4];
	for (int ii=0;ii<t;ii++)
	{
		int ans=0;
		cin>>a;
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
			{
				int k;
				cin>>k;
				if (i+1==a)
					s[j]=k;
			}
		cin>>b;
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
			{
				int k;
				cin>>k;
				if (i+1==b)
				for (int l=0;l<4;l++)
					if (s[l]==k)
					{
						if (ans==0)
							ans=k;
						else
							ans=100;
					}
			}
		cout<<"Case #"<<ii+1<<": ";
		if (ans==0)
		{
			cout<<"Volunteer cheated!\n";
			continue;
		}
		if (ans==100)
		{
			cout<<"Bad magician!\n";
			continue;
		}
		cout<<ans<<"\n";
	}
}