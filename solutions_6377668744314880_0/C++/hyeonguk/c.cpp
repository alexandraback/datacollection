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

set<pair<int, int>> convexHull(vector<pair<int, int>> p)
{
	int n = p.size(), k = 0;
	vector<pair<int, int>> h(n * 2);

	sort(p.begin(), p.end());

	for (int i = 0; i < n; i++)
	{
		while (k >= 2 && cross(h[k - 2], h[k - 1], p[i]) < 0)
		{
			k--;
		}
		h[k++] = p[i];
	}

	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && cross(h[k - 2], h[k - 1], p[i]) < 0)
		{
			k--;
		}
		h[k++] = p[i];
	}

	h.resize(k);

	set<pair<int, int>> result;
	for (int i = 0; i < h.size(); i++)
	{
		result.insert(h[i]);
	}
	return result;
}

void solve(int current)
{
	if (current == data.size())
	{
		vector<pair<int, int>> points;
		for (int i = 0; i < data.size(); i++)
		{
			if (select[i])
			{
				points.push_back(data[i]);
			}
		}

		int removed = data.size() - points.size();
		if (removed == data.size())
		{
			return;
		}

		auto result = convexHull(points);
		for (int i = 0; i < data.size(); i++)
		{
			if (result.count(data[i]) == 1)
			{
				answer[i] = min(answer[i], removed);
			}
		}

		return;
	}

	select[current] = true;
	solve(current + 1);
	select[current] = false;
	solve(current + 1);
}

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

	solve(0);

	for (int i = 0; i < data.size(); i++)
	{
		cout << answer[i] << endl;
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
