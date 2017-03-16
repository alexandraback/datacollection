#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
#include <string>
#include <string>
#include <set>
#include <map>

#define X first
#define Y second

using namespace std;

string s[110];
int n;
int myabs(int x)
{
	if (x<0) x=-x;
	return x;
}
vector<pair<int, int> >v[110];
void solve(int test)
{
	cin>>n;
	for (int i=1; i<=n; i++) 
		cin>>s[i], v[i].clear();
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<s[i].length(); j++)
		{
			int z=j;
			while ( z<s[i].length() && s[i][z]==s[i][j] ) z++;
			z--;
			v[i].push_back( make_pair(s[i][j], z-j+1) );
			j=z;
		}
	}
	/*for (int i=1; i<=n; i++)
	{
		cout<<"--"<<endl;
		for (int j=0; j<v[i].size(); j++)
			cout<<v[i][j].X<<" "<<v[i][j].Y<<endl;
	}*/
	bool fl=1;
	for (int i=2; i<=n; i++)
	{
		
		if ( v[i].size()!=v[1].size() )
			fl=0;
		for (int j=0; j<v[i].size(); j++)
			if ( v[i][j].X!=v[1][j].X )
				fl=0;
	}
	if ( fl==0 )
	{
		printf("Case #%d: Fegla Won\n", test);
		return ;
	}
	int ans=0;
	
	for (int i=0; i<v[1].size(); i++)
	{
		int ps=0, add=(1<<29);
		for (int j=1; j<=110; j++)
		{
			ps=0;
			for (int z=1; z<=n; z++)
				ps+=myabs(j-v[z][i].Y);	
			add=min(add, ps);
		}
		
		ans+=add;
	}
	printf("Case #%d: %d\n", test, ans);
}
int main()
{
	freopen("A-small-attempt0.txt", "r", stdin);
	freopen("A-small-attempt0ans.txt", "w", stdout);
	int test;
	cin>>test;
	for (int i=1; i<=test; i++)
		solve(i);
	return 0;
}
