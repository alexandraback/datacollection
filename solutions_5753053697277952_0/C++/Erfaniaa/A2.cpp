#include <bits/stdc++.h>

using namespace std;

#define MAXN 110

int t, n;

bool isValid(vector<int> v)
{
	int sum = 0;
	for (auto x: v)
	{
		// cout << "-" << x << "-";
		sum += x;
	}
	// cout << sum << endl;
	sort(v.begin(), v.end());
	if (v[0] < 0)
		return false;
	return v[v.size() - 1] * 2 <= sum;
}

int main()
{
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin >> n;
		vector<int> a;
		a.clear();
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
		}
		cout << "Case #" << tt << ":";
		while (1)
		{
			string ans = "";
			for (int i = 0; i < n; i++)
			{
				a[i]--;
				if (isValid(a))
				{
					ans.push_back(i + 'A');
					break;
				}
				a[i]++;
			}
			if (ans.size() > 0)
			{
				cout << " " << ans;
				continue;
			}
			bool found = false;
			for (int i = 0; i < n; i++)
			{
				a[i]--;
				for (int j = i; j < n; j++)
				{
					a[j]--;
					if (isValid(a))
					{
						ans.push_back(i + 'A');
						ans.push_back(j + 'A');
						found = true;
						break;
					}
					a[j]++;
				}
				if (found)
					break;
				a[i]++;
			}
			if (ans.size() > 0)
			{
				cout << " " << ans;
				continue;
			}
			else
				break;
		}
		cout << endl;
	}
	return 0;
}