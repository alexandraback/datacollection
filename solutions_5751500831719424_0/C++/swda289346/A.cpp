#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<char, int>> split(const string &s)
{
	vector<pair<char, int>> ans;
	ans.push_back(make_pair(s[0], 1));
	for (int i=1;i<s.size();i++)
		if (s[i]==ans.back().first)
			ans.back().second++;
		else
			ans.push_back(make_pair(s[i], 1));
	return ans;
}

bool hasAns(const vector<vector<pair<char, int>>> &get)
{
	for (int i=1;i<get.size();i++)
		if (get[0].size()!=get[i].size())
			return false;
	for (int i=0;i<get[0].size();i++)
		for (int j=1;j<get.size();j++)
			if (get[0][i].first!=get[j][i].first)
				return false;
	return true;
}

int calcAns(const vector<vector<pair<char, int>>> &get)
{
	int ans = 0;
	for (int i=0;i<get[0].size();i++)
	{
		int tmp1 = INT_MAX;
		for (int j=0;j<get.size();j++)
		{
			int tmp2 = 0;
			for (int k=0;k<get.size();k++)
			{
				if (j==k)
					continue;
				tmp2 += abs(get[j][i].second-get[k][i].second);
			}
			tmp1 = min(tmp1, tmp2);
		}
		ans += tmp1;
	}
	return ans;
}

int main()
{
	int t;
	int n;
	int ans;
	string s;
	vector<vector<pair<char, int>>> get;
	cin >> t;
	for (int i=1;i<=t;i++)
	{
		ans = INT_MAX;
		get.clear();
		cin >> n;
		for (int j=0;j<n;j++)
		{
			cin >> s;
			get.push_back(split(s));
		}
		cout << "Case #" << i << ": ";
		if (hasAns(get))
			cout << calcAns(get);
		else
			cout << "Fegla Won";
		cout << endl;
	}
	return 0;
}
