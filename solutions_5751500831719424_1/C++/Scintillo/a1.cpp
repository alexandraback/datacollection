#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int bigNum = 99999999;

int diff(int a, int b)
{
	return a > b ? a - b : b - a;
}


int solveCase()
{
	int n;
	cin >> n;

	vector<string> strs(n);

	for(string& str : strs)
	{
		cin >> str;
	}

	int total = 0;

	while(true)
	{
		char c = strs[0][0];

		vector<int> counts;

		for(auto& str : strs)
		{
			if(str.length() == 0 || str[0] != c)
				return -1;

			int count = 0;
			while(count < str.length() && str[count] == c)
				count++;

			str = str.substr(count);

			counts.push_back(count);
		}

		sort(counts.begin(), counts.end());

		int minNum = bigNum;

		for(int i = counts.front(); i <= counts.back(); i++)
		{
			int num = 0;
			for(int j : counts)
			{
				num += diff(j, i);
			}

			minNum = min(minNum, num);
		}

		total += minNum;

		bool allEmpty = true;
		for(auto const& str : strs)
		{
			if(str.length() != 0)
			{
				allEmpty = false;
				break;
			}
		}
		if(allEmpty)
			break;
	}

	return total;
}

int main()
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		int res = solveCase();

		cout << "Case #" << i << ": ";
		if(res == -1)
			cout << "Fegla Won";
		else
			cout << res;
		cout << endl;
	}

	return 0;
}