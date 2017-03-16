#include <cstdio>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <cctype>
#include <functional>
#include <future>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

struct TestCase
{
	int n;
	vector<pair<int, char>> data;

	void input()
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int j;
			cin >> j;
			data.push_back({j, i + 'A'});
		}
	}

	string answer;

	void process()
	{
		sort(data.begin(), data.end(), greater<pair<int, char>>());

		int sum = 0;
		for (auto &i : data)
		{
			sum += i.first;
		}

		int i = 0, j = 1;
		while (sum)
		{
			while (i < n && data[i].first == 0)
			{
				i++;
			}
			while (j < n && (data[j].first == 0 || i == j))
			{
				j++;
			}
			if (i < n && data[i].first)
			{
				data[i].first--;
				sum--;
				answer += data[i].second;
			}
			if (j < n && i != j && data[j].first)
			{
				data[j].first--;
				answer += data[j].second;
				sum--;
			}
			answer += " ";
		}
	}

	void output()
	{
		reverse(answer.begin(), answer.end());
		cout << answer.c_str() + 1;
	}
};

int main()
{
	int t;
	cin >> t;

	vector<TestCase> tc(t);
	vector<future<void>> f;
	for (int i = 0; i < t; i++) tc[i].input();
	for (int i = 0; i < t; i++)
		f.push_back(async(launch::async,
			[&](int p){ tc[p].process(); }, i));
	// for (int i = 0; i < t; i++) f[i].wait();
	for (int i = 0; i < t; i++)
	{
		f[i].wait();
		cout << "Case #" << i + 1 << ": ";
		tc[i].output();
		cout << endl;
	}
	return 0;
}
