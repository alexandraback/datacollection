#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
using namespace std;
int t;
int n;
vector<vector<pair<char, int> > > chs;
string s;
int pos;

void solve()
{
	int ans = 0, l = 0;
	cin >> n;
	chs.clear();
	chs.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> s;

		pos = 1;
		l = 1;
		while(pos < s.length())
		{
			l = 1;
			while (pos < s.size() && s[pos] == s[pos - 1]) ++pos, l++;
			chs[i].push_back(make_pair(s[pos - 1], l));
			++pos;
		}
		if (pos == s.size())
			chs[i].push_back(make_pair(s[pos - 1], 1));
/*		cout << s << ": ";
		for (int j = 0; j < chs[i].size(); ++j)
			cout << chs[i][j].first << " " << chs[i][j].second << " ";
		cout << endl;*/
	}
	for (int i = 1; i < n; ++i)
	{
		if (chs[i].size() != chs[i - 1].size())
		{
			cout << "Fegla Won" << endl;
			return;
		}
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < chs[i].size(); ++j)
		{
			if (chs[i][j].first != chs[i - 1][j].first)
			{
				cout << "Fegla Won" << endl;
				return;
			}
		}
	}
	vector<int> ll;
	for (int j = 0; j < chs[0].size(); ++j)
	{
		ll.clear();	
		for (int i = 0; i < n; ++i)
			ll.push_back(chs[i][j].second);
		sort(ll.begin(), ll.end());
	
	    int med = ll[n / 2];
//	    cout << med << endl;
		for (int i = 0; i < n; ++i)
			ans += abs(med - chs[i][j].second);
	}

	cout << ans << endl;
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return 0;
}