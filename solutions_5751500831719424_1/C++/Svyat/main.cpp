#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t;
int n;
vector<string> s;
string red;
vector<vector<int>> cnt;

string reduce(string t)
{
	string res = t.substr(0, 1);
	for (int i = 1; i < t.length(); ++i)
		if (t[i] != res.back())
			res += t[i];
	return res;
}

bool ok()
{
	red = reduce(s[0]);
	for (int i = 1; i < n; ++i)
		if (red != reduce(s[i]))
			return false;
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int id = 1; id <= t; ++id)
	{
		scanf("%d", &n);
		printf("Case #%d: ", id);
		s.resize(n);
		cnt.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> s[i];
		if (!ok())
			printf("Fegla Won\n");
		else
		{
			int res = 0;
			for (int i = 0, count; i < n; ++i)
			{
				count = 0;
				for (int j = 0, prv = 0; j < s[i].length(); ++j)
				{
					if (s[i][j] == prv)
						++count;
					else
					{
						if (prv)
							cnt[i].push_back(count);
						prv = s[i][j], count = 1;
					}
				}
				cnt[i].push_back(count);
			}
			for (int i = 0, best = 1e9; i < red.length(); ++i)
			{
				best = 1e9;
				for (int k = 1; k <= 100; ++k)
				{
					int tmp = 0;
					for (int j = 0; j < n; ++j)
						tmp += abs(cnt[j][i] - k);
					if (tmp < best)
						best = tmp;
				}
				res += best;
			}
			printf("%d\n", res);
		}
		s.clear();
		for (int i = 0; i < n; ++i)
			cnt[i].clear();
		cnt.clear();
	}
	return 0;
}