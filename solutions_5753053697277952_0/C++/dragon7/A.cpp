#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int a[30];
int main()
{
	int test;
	cin>>test;
	for(int z=1;z<=test;z++)
	{
		int n;
		cin>>n;
		int su = 0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			su += a[i];
		}
		cout<<"Case #"<<z<<": ";
		for(int j=1;j<=su;j++)
		{
			int maxval = 0;
			int cnt = 0;
			for(int i=1;i<=n;i++)
			{
				maxval = max(maxval,a[i]);
				if(a[i]>0)cnt++;
			}
			if(cnt==2)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i]>0)
					{
						char c = 'A'+i-1;
						cout<<c;
					}
				}
				cout<<" ";
				j++;
				continue;
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i]==maxval)
				{
					char c = 'A'+i-1;
					cout<<c<<" ";
					a[i]--;
					break;
				}
			}
		}
		cout<<endl;
	}
}
