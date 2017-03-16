#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int convert(string str, vector<pair<char, int>> &vec)
{
	vec.clear();
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 || str[i] != str[i - 1])
		{
			vec.push_back(make_pair(str[i], 1));
		}
		else
			vec.back().second++;
	}
	return 0;
}

int main()
{
	int T;
	cin >> T;
	for (int c = 1; c <= T; c++)
	{
		int n;
		cin >> n;
		vector<vector<pair<char, int > > > data;
		data.resize(n);
		for (int i = 0; i < n; i++)
		{
			string tmp;
			cin >> tmp;
			convert(tmp, data[i]);
		}
		bool able = true;
		for (int j = 1; j < n; j++)
		if (data[j].size() != data[0].size())
		{
			able = false;
			break;
		}
		if (able)
		for (int i = 0; i < data[0].size(); i++)
		{
			for (int j = 1; j < n; j++)
			if (data[j][i].first != data[0][i].first)
			{
				able = false;
				break;
			}
			if (able == false)
				break;
		}

		cout << "Case #" << c << ": ";
		if (able)
		{
			int ans = 0;
			vector<int> cnt;
			cnt.resize(n);
			for (int i = 0; i < data[0].size(); i++)
			{
				for (int j = 0; j < n; j++)
					cnt[j] = data[j][i].second;
				sort(cnt.begin(), cnt.end());
				for (int j = 0; j < n; j++)
					ans += abs(cnt[j] - cnt[(n - 1) / 2]);
			}
			cout << ans << endl;
		}
		else
			cout << "Fegla Won" << endl;
	}
	return 0;
}