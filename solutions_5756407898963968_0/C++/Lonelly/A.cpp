#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

void solve(int index)
{
	int n = 4, m = 4;
	int map1[4][4], map2[4][4];
	int line1, line2;
	set<int> numbers, numbers2;
	cin >> line1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map1[i][j];
			if (i + 1 == line1)
			{
				numbers.insert(map1[i][j]);
			}
		}
	}
	cin >> line2;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map2[i][j];
			if (i + 1 == line2)
			{
				if (numbers.find(map2[i][j]) != numbers.end())
				{
					numbers2.insert(map2[i][j]);
				}
			}
		}
	}
	cout << "Case #" << index + 1 << ": ";
	if (numbers2.size() > 1)
	{
		cout << "Bad magician!";
	}
	else if (numbers2.size() == 0)
	{
		cout << "Volunteer cheated!";
	}
	else
	{
		cout << *numbers2.begin();
	}
	cout << endl;
}

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		solve(i);
	}
	return 0;
}