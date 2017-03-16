#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<char, int> > parse()
{
	string line;
	cin >> line;
	vector<pair<char, int>> ans;
	char cur = 0;
	for (auto k: line)
	{
		if (k == cur) ans.back().second++;
		else
		{
			ans.push_back(make_pair(k, 1));
			cur = k;
		}
	}
	return ans;
}

void doit(int casenum)
{
	cout << "Case #" << casenum << ": ";
	int N;
	cin >> N;
	vector<vector<pair<char, int> > > words;
	for (int i = 0; i < N; ++i)
	{
		words.push_back(parse());
	}
	unsigned len = words[0].size();
	for (auto w: words)
	{
		if (w.size() != len)
		{
			cout << "Fegla Won" << endl;
			return;
		}
	}

	unsigned moves = 0;
	for (unsigned i = 0; i < len; ++i)
	{
		vector<int> occs(N);
		char c = words[0][i].first;
		for (unsigned j = 0; j < words.size(); ++j)
		{
			if (words[j][i].first != c)
			{
				cout << "Fegla Won" << endl;
				return;
			}
			occs[j] = words[j][i].second;
		}
		sort(occs.begin(), occs.end());
		for (unsigned j = 0; j < words.size(); ++j)
		{
			moves += abs(occs[N/2] - words[j][i].second);
		}
	}

	cout << moves << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) doit(i);
	return 0;
}
