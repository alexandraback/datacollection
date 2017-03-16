#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>

#define max(a,b) (a) > (b) ? (a) : (b)
#define min(a,b) (a) < (b) ? (a) : (b)

using namespace std;

unordered_set<string> dev;

void calc()
{
	static int caseno = 0;
	caseno++;
	cerr << "Case #" << caseno << endl;

	// code begin
	int n;
	cin >> n;

	vector<char> vc;
	vector<vector<int>> vvcount(n, vector<int>(100,0));
	bool impossible = false;

	for (int i = 0; i < n; i++)
	{
		string stmp;
		cin >> stmp;

		if (impossible) continue;

		if (i == 0)
		{
			for (int j = 0; j < stmp.length(); j++)
			{
				if (!vc.size() || vc[vc.size() - 1] != stmp[j])
				{
					vc.push_back(stmp[j]);
				}
				vvcount[i][vc.size() - 1]++;
			}
		}
		else
		{
			int index = 0;
			for (int j = 0; j < stmp.length(); j++)
			{
				if (impossible) break;
				while (index < vc.size() && vc[index] != stmp[j])
				{
					if (!vvcount[i][index]) impossible = true;
					index++;
				}
				if (index >= vc.size())
					impossible = true;
				else
					vvcount[i][index]++;
			}
			if (index < vc.size() - 1) impossible = true;
		}
	}

	vector<int> vcost(vc.size(), 10000000);
	int totalcost = 0;
	if (!impossible)
	{
		for (int k = 0; k < vc.size(); k++)
		{
			for (int i = 1; i <= 100; i++)
			{
				int cost = 0;
				for (int j = 0; j < n; j++)
				{
					cost += abs(vvcount[j][k] - i);
				}
				if (cost < vcost[k]) vcost[k] = cost;
			}
			totalcost += vcost[k];
		}
	}


	// code end

	cout << "Case #" << caseno << ": ";
	if (impossible)
		cout << "Fegla Won";
	else
		cout << totalcost;
	cout << endl;
}

int main()
{
	int k = 1;
	cin >> k;
	while (k-- > 0)
	{
		calc();
	}

	return 0;
}

