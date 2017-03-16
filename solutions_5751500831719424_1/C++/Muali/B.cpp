#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;


void solve()
{
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++ i)
	{
		cin >> v[i];
	}
	string pat = "";
	for (int i = 0; i < v[0].size(); ++i)
	{
		pat += v[0][i];
		while (i + 1 < v[0].size() && v[0][i + 1] == v[0][i]) ++i;
	}
	bool ps = true;
	vector<vector<int>> vc(n);
	for (int i = 0; i < v.size(); ++i)
	{
		int k = 0;
		for (int j = 0; j < v[i].size(); ++j)
		{
			int start = j;
			if ( k < pat.size() && pat[k] == v[i][j])
				++k;
			else
			{
				ps = false;
				break;
			}
			while (j + 1 < v[i].size() && v[i][j + 1] == v[i][j]) ++j;
			vc[i].push_back(j - start + 1);
		}
		if (k != pat.size())
			ps = false;
	}
	if (!ps)
	{
		cout << "Fegla Won";
		return;
	}
	int ans = 0;
	for (int i = 0; i < pat.size(); ++i)
	{
		int c = 1000000000;
		for (int j = 1; j <= 100; ++j)
		{
			int t = 0;
			for (int k = 0; k < n; ++k)
			{
				t += abs(vc[k][i] - j);
			}
			c = min(c, t);
		}
		ans += c;
	}
	cout << ans;
}

void main()
{
	freopen("i.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	

}