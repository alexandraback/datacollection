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
	vector<int> data;

	void input()
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int j;
			cin >> j;
			data.push_back(j);
		}
		if (data.size() == 2)
		{
			data.push_back(0);
		}
	}
	
	bool went[10][10][10];
	bool valid[10][10][10];
	int left[10][10][10];
	int right[10][10][10];

	string answer;

	bool solve(vector<int> &vect)
	{
		const auto i = vect[0];
		const auto j = vect[1];
		const auto k = vect[2];

		// cout << i <<  " " << j  <<  " " << k << endl;

		if (valid[i][j][k])
		{
			return true;
		}
		if (went[i][j][k])
		{
			return valid[i][j][k];
		}
		went[i][j][k] = true;

		int sum = i + j + k;
		for (int p = 0; p < 3; p++)
		{
			if (vect[p] + vect[p] > sum)
			{
				valid[i][j][k] = false;
				return false;
			}
		}

		for (int p = 0; p < 3; p++)
		{
			if (vect[p] == data[p])
			{
				continue;
			}
			vect[p]++;
			for (int q = -1; q < 3; q++)
			{
				if (q >= 0 && vect[q] == data[q])
				{
					continue;
				}
				if (q >= 0)
					vect[q]++;
				if (solve(vect))
				{
					left[i][j][k] = p;
					right[i][j][k] = q;
					valid[i][j][k] = true;
					return true;
				}
				if (q >= 0)
					vect[q]--;
			}
			vect[p]--;
		}
		valid[i][j][k] = false;
		return false;
	}

	void process()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int k = 0; k < 10; k++)
				{
					valid[i][j][k] = false;
					went[i][j][k] = false;
					left[i][j][k] = right[i][j][k] = -1;
				}
			}
		}

		valid[data[0]][data[1]][data[2]] = true;
		vector<int> vect(3, 0);
		solve(vect);

		vect = vector<int>(3, 0);
		for (;;)
		{
			bool end = true;
			for (int i = 0; i < 3; i++)
			{
				if (vect[i] != data[i])
				{
					end = false;
					break;
				}
			}
			if (end)
			{
				break;
			}

			int p = -1, q = -1;
			if (left[vect[0]][vect[1]][vect[2]] >= 0)
			{
				p = left[vect[0]][vect[1]][vect[2]];
				answer += (char)(left[vect[0]][vect[1]][vect[2]] + 'A');
			}
			if (right[vect[0]][vect[1]][vect[2]] >= 0)
			{
				q = right[vect[0]][vect[1]][vect[2]];
				answer += (char)(right[vect[0]][vect[1]][vect[2]] + 'A');
			}
			answer += " ";

			if (p >= 0)
			{
				vect[p]++;
			}
			if (q >= 0)
			{
				vect[q]++;
			}
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
