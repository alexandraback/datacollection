#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;

vector<pair<char, int> > process_str(string s)
{
	vector<pair<char, int> > res;
	int ptr = 0;
	while (ptr < s.size())
	{
		int cnt = 0;
		while (ptr + cnt < s.size() && s[ptr + cnt] == s[ptr]) cnt++;
		res.push_back(make_pair(s[ptr], cnt));
		ptr += cnt;
	}
	return res;
}

int div_round(int a, int b)
{
	return a / b + (a % b > b / 2 ? 1 : 0);
}

void test(int t)
{
	int n; cin >> n;
	vector<vector<pair<char, int> > > data(n);
	bool fail = false;
	for (int i = 0; i < n && !fail; i++)
	{
		string s;
		cin >> s;
		data[i] = process_str(s);
		if (i > 0 && data[i].size() != data[i-1].size())
			fail = true;
	}
	if (!fail)
	{
		vector<pair<char, int> > average;
		for (int i = 0; i < n && !fail; i++)
		{
			average.resize(data[i].size());
			for (int j = 0; j < data[i].size() && !fail; j++)
			{
				if (i == 0)
					average[j].first = data[i][j].first;
				else if (average[j].first != data[i][j].first)
					fail = true;
				average[j].second += data[i][j].second;
			}
		}
		if (!fail)
		{
			for (int i = 0; i < average.size(); i++)
				average[i].second = div_round(average[i].second, n);
			int res = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < data[i].size(); j++)
					res += abs(average[j].second - data[i][j].second);
			cout << "Case #" << t << ": " << res << endl;
		}
		else
			cout << "Case #" << t << ": Fegla Won\n";
	}
	else
		cout << "Case #" << t << ": Fegla Won\n";
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		test(i);
}
