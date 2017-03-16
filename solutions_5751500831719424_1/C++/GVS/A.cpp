#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>

using namespace std;
int i , j,  k , n , ans;
string s[1000];
int cnt[1000];
vector<pair<int,int> > v[1000];
int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);

	int test;
	cin>>test;
	for (int t = 1; t <= test; t++)
	{
		cin>>n;
		for (i = 0; i < n; i++)
		{
			v[i].clear();
			cin>>s[i];
		}
		cout<<"Case #"<<t<<": ";

		for (i = 0; i < n; i++)
		{
			j = 0;
			while (j < s[i].size())
			{
				k = j;
				while (k < s[i].size() && s[i][k] == s[i][j])
					k++;

				v[i].push_back(make_pair(s[i][j] , k - j ));

				j = k;
			}
		}

		int ans = 0;
		int good = 1;
		for (i = 0; i < n; i++)
		{
			if (v[i].size() != v[0].size())
				good = 0;
		}

		for (j = 0; j < v[0].size(); j++)
		{
			if (!good) 
				break;

			for (i = 0; i < n; i++)
			{
				if (v[i][j].first != v[0][j].first)
					good = 0;
			}

			if (!good) 
				break;

			int minop = 100000;
			
			for (int raod = 1; raod <= 100; raod++)
			{
				int sum = 0;
				for (i = 0; i < n; i++)
					sum += abs(v[i][j].second - raod);


				minop = min(minop , sum);
			}

			ans += minop;
		}
		if (good == 0)
		{
			cout<<"Fegla Won\n";
		} else
			cout<<ans<<endl;

	}
	return 0;
}