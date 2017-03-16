#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

struct gg
{
	int p;
	char name;
}g[1010];

bool cmp(gg g1, gg g2)
{
	return g1.p > g2.p;
}

int main()
{
	int T;
	cin >> T;
	int cas = 0;

	while (T--)
	{
		cout << "Case #" << ++cas << ": ";
		vector<char> res;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> g[i].p;
			g[i].name = 'A' + i;
		}
		if (n == 2)
		{
			int q = g[0].p;
			while (q--)
			{
				cout << g[0].name << g[1].name;
				if (q)
				{
					cout << " ";
				}
			}
			cout << endl;
			continue;
		}
		g[n].p = 0;
		sort(g, g + n, cmp);
		for (int i = 1; i <= n; ++i)
		{
			int q = g[0].p - g[i].p;
			while (q--)
			{
				for (int j = 0; j < i; ++j)
				{
					res.push_back(g[j].name);
					g[j].p--;
				}
			}
		}
		int size = res.size();
		for (int i = 0; i < size; ++i)
		{
			cout << res[i];
			if (i < size - 2)
			{
				cout << " ";
			}
		}
		cout << endl;

	}



	return 0;
}

