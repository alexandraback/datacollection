#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <cstdio>

using namespace std;

void compact(vector<vector<pair<char, int> > >& compactWords, int N, vector<string>& words)
{
	for (int i = 0; i < N; ++i)
	{
		string& w = words[i];
		for (int j = 0; j < w.length(); ++j)
		{
			if (j == 0 || w[j] != w[j-1])
			{
				compactWords[i].push_back(make_pair(w[j], 0));
			}

			compactWords[i].back().second++;
		}
	}
}

bool existsSolution(vector<vector<pair<char, int> > >& compactWords, int N)
{
	for (int i = 0; i < compactWords[0].size(); ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (compactWords[j].size() != compactWords[0].size())
			{
				return false;
			}

			if (compactWords[j][i].first != compactWords[0][i].first)
			{
				return false;
			}
		}
	}
	return true;
}

int updateWords(vector<vector<pair<char, int> > >& compactWords, int N)
{
	int changes = 0;
	int l = 0;
	while (true)
	{
		double avg = 0;
		for (int i = 0; i < N; ++i)
			avg += compactWords[i][l].second;
		avg /= N;
		//cout << "l: " << l << ", avg: " << avg << endl;
		//cout << "(";
		double maxDifAvg = 0;
		int maxDifAvgIndex = 0;
		for (int i = 0; i < N; ++i)
		{
			double difAvg = (double)(avg - (double)compactWords[i][l].second);
			//cout << difAvg << ", ";
			if (fabs(difAvg) > fabs(maxDifAvg))
			{
				maxDifAvg = difAvg;
				maxDifAvgIndex = i;
			}
		}
		//cout << ")" << endl;
		//cout << "maxDifAvg: " << maxDifAvg << ", index: " << maxDifAvgIndex << endl << endl;
		if (maxDifAvg == 0)
		{
			++l;
			if (l == compactWords[0].size())
				break;
			continue;
		}

		compactWords[maxDifAvgIndex][l].second += (maxDifAvg > 0 ? 1 : -1);

		++changes;
	}
	return changes;
}

void solveCase(int t)
{
	int N;
	cin >> N;
	vector<string> words(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> words[i];
	}

	vector<vector<pair<char, int> > > compactWords(N);
	compact(compactWords, N, words);
	if (!existsSolution(compactWords, N))
	{
		cout << "Fegla Won";
	}
	else
	{
		int changes = updateWords(compactWords, N);
		cout << changes;
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{	
		cout << "Case #" << t << ": ";
        solveCase(t);
        cout << endl;
	}
	
	return 0;
}