#include <iostream>
#include <string>
#include <vector>
using namespace std;

string minimize(const string &s)
{
	string minimal;
	minimal += s[0];
	for (int i = 1; i < s.length(); ++i)
		if (s[i] != minimal[minimal.length() - 1])
			minimal += s[i];
	return minimal;
}

void counts(const string &s, const string &chars, vector<int> &c)
{
	c.clear();
	c.push_back(0);
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == chars[c.size() - 1])
			++c[c.size() - 1];
		else
			c.push_back(1);
	}
	if (c.size() != chars.length())
		cerr << "*** ERROR IN COUNTS!" << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		int N;
		cin >> N;
		vector<string> s(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> s[i];
			cerr << i << ": " << s[i] << endl;
		}

		string chars = minimize(s[0]);
		cerr << "=> " << chars << endl;

		bool fegla = false;
		for (int i = 1; i < N; ++i)
			if (minimize(s[i]) != chars)
				fegla = true;

		if (fegla)
		{
			cout << "Case #" << case_num << ": Fegla Won" << endl;
			continue;
		}

		vector< vector<int> > c(N);
		for (int i = 0; i < N; ++i)
		{
			counts(s[i], chars, c[i]);
			for (int k = 0; k < c[i].size(); ++k)
				cerr << c[i][k] << " ";
			cerr << endl;
		}

		int total_moves = 0;
		for (int i = 0; i < chars.length(); ++i)
		{
			int min_moves = 1000000;
			for (int j = 1; j <= 100; ++j)
			{
				int num_moves = 0;
				for (int k = 0; k < N; ++k)
				{
					if (c[k][i] < j)
						num_moves += (j - c[k][i]);
					else if (c[k][i] > j)
						num_moves += (c[k][i] - j);
				}
				if (num_moves < min_moves)
					min_moves = num_moves;
			}
			cerr << i << chars[i] << ":" << min_moves << " ";
			total_moves += min_moves;
		}
		cerr << endl;
		cout << "Case #" << case_num << ": " << total_moves << endl;
	}
	return 0;
}