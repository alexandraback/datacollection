#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <tuple>
#include <queue>

using namespace std;

ifstream input;
ofstream output;

long long poww(long long base, long long exp)
{
	if (exp == 0)
		return 1;
	return poww(base,exp-1) * base;
}


void solve()
{
	int tot = 0;
	int n;
	input >> n;
	priority_queue<pair<int, char> > P;
	for (char a = 'A'; a < 'A' + n; a++)
	{
		int x;
		input >> x;
		P.push({ x, a });
		tot += x;
	}
	while (!P.empty())
	{
		auto party1 = P.top();
		P.pop();
		party1.first--;
		tot--;
		output << " " << party1.second;

		if (!P.empty())
		{
			auto party2 = P.top();
			if (party2.first * 2 > tot)
			{
				P.pop();
				party2.first--;
				tot--;
				output << party2.second;
				if (party2.first > 0)
					P.push(party2);
			}
		}
		if (party1.first > 0)
			P.push(party1);
	}
}

int main()
{
	input.open("input.txt");
	output.open("output.txt");
	int T;
	input >> T;
	for (int cc = 0; cc < T; cc++)
	{
		output << "Case #" << cc + 1 << ":";
		solve();
		output << endl;
	}
	input.close();
	output.close();
}