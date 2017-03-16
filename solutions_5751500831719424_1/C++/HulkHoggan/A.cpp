#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

int t, n, a[211][211][2], b[211], count0, c[211];
string s;
bool ok;

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<++count0<<": ";
		cin>>n;
		ok=true;
		getline(cin,s);//[0]);
		memset(a, 0, sizeof(a));
		for(int i=0; i<n; ++i)
		{
			getline(cin,s);//[i]);
			b[i]=1;
			a[i][0][0]=s[0];
			a[i][0][1]=1;
			for(int j=1; j<s.size(); ++j)
				if (s[j]==s[j-1])
					a[i][b[i]-1][1]++;
				else
				{
					b[i]++;
					a[i][b[i]-1][0]=s[j];
					a[i][b[i]-1][1]++;
				}
			if (i && b[i]!=b[i-1])
				ok=false;
		}
		if (!ok)
		{
			cout<<"Fegla Won\n";
			continue;
		}
		for(int i=1; i<n; ++i)
			for(int j=0; j<b[i]; ++j)
				if (a[i][j][0]!=a[0][j][0])
					ok=false;
		if (!ok)
		{
			cout<<"Fegla Won\n";
			continue;
		}
		int ss=0;
		for(int i=0;i<b[0];++i)
		{
			for(int j=0;j<n;++j)
				c[j]=a[j][i][1];
			sort(c,c+n);
			int x=c[(n+1)/2-1];
			for(int j=0;j<n;++j)
				ss+=abs(x-c[j]);
		}
		cout<<ss<<endl;
	}
	return 0;
}