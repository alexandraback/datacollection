#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

const int N = 121;
string s[N];
int num[N][N];

int main()
{
	ios::sync_with_stdio(false);
	int T; cin>>T;
	for(int iT=1;iT<=T;iT++)
	{
		int n,t; cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s[i]; s[i] += '\0';
			string ts = "";
			t = 0;
			int len = 1;
			for(int j=1;j<(int)s[i].size();j++)
				if(s[i][j] != s[i][j-1])
				{
					num[t++][i] = len;
					ts += s[i][j-1];
					len = 1;
				}
				else len++;
			s[i] = ts;
		}
		bool flag = true;
		for(int i=1;i<n;i++)
			if(s[i] != s[i-1])
				flag = false; 
		if(flag)
		{
			int ans = 0;
			for(int i=0;i<t;i++)
			{
				sort(num[i],num[i]+n);
				for(int j=0;j<n;j++)
					ans += abs(num[i][j]-num[i][n/2]);
			}
			cout<<"Case #"<<iT<<": "<<ans<<'\n';
		}
		else cout<<"Case #"<<iT<<": "<<"Fegla Won\n";
	}
	return 0;
}