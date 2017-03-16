#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
void solve()
{
	vector<int>v[101];
	int i,l[101],p=0,j,o=0,br,co,n;
	string s[101],ns,cs;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>s[i];
	ns=s[0][0];
	int sz=s[0].size();
	for(i=1;i<sz;i++)
		if(s[0][i]!=s[0][i-1])ns+=s[0][i];
	for(i=0;i<n;i++)
	{
		cs=s[i][0];
		sz=s[i].size();
		br=p=0;
		for(j=1;j<sz;j++)
			if(s[i][j]!=s[i][j-1])
			{
				cs+=s[i][j];
				v[br].push_back(j-p);
				br++;
				p=j;
			}
		v[br].push_back(j-p);
		br++;
		if(cs!=ns)
		{
			cout<<"Fegla Won\n";
			return;
		}
	}
	o=0;
	for(i=0;i<br;i++)
	{
		sort(v[i].begin(),v[i].end());
		sz=v[i].size();
		for(j=0;j<sz;j++)
			o+=abs(v[i][sz/2]-v[i][j]);
	}
	cout<<o<<endl;
}
int main()
{
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
}
