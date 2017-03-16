#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <limits>
#include <functional>
using namespace std;

long long cross(pair<int, int> o, pair<int, int> a, pair<int, int> b)
{
	return ((long long)a.first - o.first) * ((long long)b.second - o.second) - ((long long)a.second - o.second) * ((long long)b.first - o.first);
}

vector<pair<int, int>> data;
vector<bool> select;
vector<int> answer;

void testCase()
{
	int n;
	cin >> n;

	data.clear();
	select = vector<bool>(n, false);
	answer = vector<int>(n, numeric_limits<int>::max());
	
	while (n--)
	{
		int i, j;
		cin >> i >> j;
		data.push_back({i, j});
	}

	if (data.size() <= 3)
	{
		for (int i = 0; i < data.size(); i++)
		{
			printf("0\n");
		}
		return;
	}

	for (int i = 0; i < data.size(); i++)
	{
		for (int j = i + 1; j < data.size(); j++)
		{
			int left = 0, right = 0;

			for (int k = 0; k < data.size(); k++)
			{
				auto p = data[i];
				auto q = data[j];

				auto t = data[k];

				auto c = cross(p, q, t);
				if (c < 0)
				{
					left++;
				}
				else if (c > 0)
				{
					right++;
				}
			}
			answer[i] = min(answer[i], min(left, right));
			answer[j] = min(answer[j], min(left, right));
		}
	}

	for (auto &&i : answer)
	{
		cout << i << endl;
	}
}

int main()
{
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ":" << endl;
		testCase();
	}

	return 0;
}
