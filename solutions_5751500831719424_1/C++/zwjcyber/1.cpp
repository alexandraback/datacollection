#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	int t;
	cin>>t;
	int id = 0;
	while(t--)
	{
		int n;
		cin>>n;
		string s[102];
		for(int i = 0;i < n;i++)
		{
			cin>>s[i];
		}
		int n0 = s[0].size();
		vector<char> v;
		for(int i = 0;i < n0;i++)
		{
			if(i == 0)
				v.push_back(s[0][0]);
			else if(s[0][i] != s[0][i - 1])
				v.push_back(s[0][i]);
		}
		int a[102][102];
		int b[102];
		memset(a,0,sizeof(a));
		for(int k = 0;k < v.size();k++)
		{
			b[k] = 1002;
		}
		bool f = true;
		for(int i = 0;i < n;i++)
		{
			int j = 0;
			int index = 0;
			while(j < s[i].size() && index < v.size())
			{
				if(s[i][j] == v[index])
				{
					a[i][index]++;
					j++;
				}
				else
					index++;
			}
			if(j < s[i].size())
			{
				f = false;
				break;
			}
			for(int k = 0;k < v.size();k++)
			{
				if(a[i][k] == 0)
					f = false;
			}
		}
		cout<<"Case #"<<++id<<": ";
		if(!f)
		{
			cout<<"Fegla Won"<<endl;
		}
		else
		{
			for(int k = 0;k < v.size();k++)
			{
				vector<int> v1;
				for(int i = 0;i < n;i++)
				{
					v1.push_back(a[i][k]);
				}
				sort(v1.begin(),v1.end());
				int tem = n /2;
				b[k] = v1[tem];
			}
			int count = 0;
			for(int i = 0;i < n;i++)
			{
				for(int k = 0;k < v.size();k++)
				{
					count += abs(a[i][k] - b[k]);
				}
			}
			cout<<count<<endl;
		}
	}
	return 0;
}


