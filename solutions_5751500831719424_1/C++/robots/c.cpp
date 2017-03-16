#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	freopen("A-large.in","r",stdin);
	freopen ("output.txt","w",stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		vector<string> v(n),unq(n);
		for (int j = 0; j < n; j++){
			cin >> v[j];
			unq[j] = v[j];
			string::iterator it;
			it = std::unique (unq[j].begin(), unq[j].end());  
			unq[j].resize( std::distance(unq[j].begin(),it) );
		}
		int c = 1;
		string s = unq[0];
		for (int j = 1; j < n; j++)
		{
			if (s == unq[j])
				c++;
		}
		if (c != unq.size())
		{
			printf ("Case #%d: Fegla Won\n",i + 1);
		}
		else
		{
			vector<vector<int> > v2(n,vector<int>(s.size()));
			for (int k = 0; k < n; k++)
			{
				int it = 0;
				for (int j = 0; j < s.size(); j++)
				{
					while (s[j] == v[k][it])
						v2[k][j]++,it++;
				}
			}
			vector<int> ss(s.size(),INT_MAX);
			for (int p = 0; p < s.size(); p++)
			{
				for (int k = 0; k < n; k++)
				{
					int to = v2[k][p];
					int c = 0;
					for (int j = 0; j < n; j++)
					{
						c += abs(v2[j][p] - to);
					}
					ss[p] = min (ss[p],c);
				}
			}
			int ans = 0;
			for (int i = 0; i < ss.size(); i++)
			{
				ans += ss[i];
			}
			printf ("Case #%d: %d\n",i + 1,ans);
		}
	}
	return 0;
}