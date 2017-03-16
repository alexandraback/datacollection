#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int t;

void solve(vector<string> &strs)
{
	vector<char> order;

	int previous = -1;
	for (char c : strs[0])
	{
		if (c != previous)
		{
			previous = c;
			order.push_back(c);
		}
	}

	vector<vector<int>> infos;
	for (string &s : strs)
	{
		infos.emplace_back();
		vector<int> &info = infos.back();

		int pointer = 0;
		int previous = -1;
		int start = 0;
		for (int r = 0; r < s.length(); r++)
		{
			char c = s[r];
			if (c != previous)
			{
				previous = c;
				if (pointer == order.size() || order[pointer] != c)
				{
					cout << "Case #" << t << ": Fegla Won" << endl;
					return;
				} else {
					pointer++;
					info.push_back(r - start);
					start = r;
				}
			}
		}

		info.push_back(s.length() - start);
		if (info.size() != infos[0].size())
		{
			cout << "Case #" << t << ": Fegla Won" << endl;
			return;
		}
	}

	// cout << "info---" << endl;
	// for (int s = 0; s < infos.size(); s++)
	// {
	// 	for (int k : infos[s]) cout << k << " ";
	// 	cout << endl;
	// }

	int result = 0;
	for (int k = 0; k <= order.size(); k++)
	{
		int minl = infos[0][k];
		int maxl = infos[0][k];
		for (int s = 0; s < strs.size(); s++)
		{
			if (infos[s][k] < minl) minl = infos[s][k];
			if (infos[s][k] > maxl) maxl = infos[s][k];
		}

		int minv = INT_MAX;
		for (int v = minl; v <= maxl; v++)
		{
			int value = 0;
			for (int s = 0; s < strs.size(); s++)
			{
				value += abs(infos[s][k] - v);
			}
			if (value < minv) minv = value;
		}

		result += minv;
	}

	cout << "Case #" << t << ": " << result << endl;
}

int main()
{
	int T;
	cin >> T;
	for (t = 1; t <= T; t++)
	{
		int p;
		cin >> p;
		string line;
		getline(cin, line);
		vector<string> strs;
		while (p-- > 0)
		{
			getline(cin, line);
			strs.push_back(line);
		}

		solve(strs);
	}
	return 0;
}
