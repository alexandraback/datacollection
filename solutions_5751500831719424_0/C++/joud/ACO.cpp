# include <iostream>
# include <cmath>
# include <algorithm>
# include <queue>
# include <stack>
# include <algorithm>
# include <iomanip>
# include <string>
# include <cstring>
# include <cstdio>
# include <stdio.h>
using namespace std;

string a[100];
int main()
{
	freopen("1B.txt","w",stdout);
	int t;
	cin>>t;
	for (int tt=1;tt<=t;tt++)
	{
		
int b[100][100]={0};
int len[100]={0};
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		if (s.length()==1)
		{
			a[i]=s;
			b[i][0]=1;
			len[i]=1;
		}
		int now=1;
		for (int x=1;x<s.length();x++)
		{
			if (s[x]!=s[x-1])
			{
				a[i]+=s[x-1];
				len[i]++;
				b[i][len[i]-1]=now;
				now=1;
			}
			if (s[x]==s[x-1])
				now++;
			if (x==s.length()-1)
			{
				a[i]+=s[x];
				len[i]++;
				b[i][len[i]-1]=now;
			}
			
		}
	}
	bool p=1;
	for (int i=1;i<n;i++)
	{
		if (a[i]!=a[i-1])
		{
			cout<<"Case #"<<tt<<": Fegla Won\n";
			p=0;
			break;
		}
	}
	if (p==1)
	{
	int ans=0;
	for (int x=0;x<len[0];x++)
	{
		int best=10000000;
		for (int j=1;j<=100;j++)
		{
			int now=0;
			for (int k=0;k<n;k++)
			{
				now+=abs(j-b[k][x]);
			}
			if (now<best)
				best=now;
		}
		ans+=best;
	}
	cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	for (int i=0;i<100;i++)
	{
		a[i]="";
		len[i]=0;
	}
	}
}
