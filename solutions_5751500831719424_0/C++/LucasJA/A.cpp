#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char w[100][101];
int cs[100], ts[100];

int get(int v, int n)
{
	int ret = 0;
	for (int i = 0; i < n; ++i)
		ret += abs(v-ts[i]);
	return ret;
}

int main()
{
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	for (int x = 1; x <= t; ++x)
	{
		int n;
		bool ok = true;
		int res = 0;
		memset(cs, 0, sizeof(cs));
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> w[i];
		while (w[0][cs[0]] != 0 && ok)
		{
			char ch = w[0][cs[0]];
			for (int i = 0; i < n; ++i)
			{
				int j;
				for (j = cs[i]; w[i][j] == ch; ++j);
				if (j-cs[i] == 0)
				{
					ok = false;
					break;
				}
				ts[i] = j-cs[i];
				cs[i] = j;
			}
			if (!ok)
				continue;
			int val = 1000;
			for (int i = 1; i <= 100; ++i)
				val = min(val, get(i, n));
			res += val;
			//res += abs(ts[0]-ts[1]);
		} 
		for (int i = 0; i < n && ok; ++i)
		{
			if (w[i][cs[i]] != 0)
				ok = false;
		}
		cout << "Case #" << x << ": ";
		if (!ok)
			cout << "Fegla Won\n";
		else
			cout << res << "\n";
	}
	return 0;
}
