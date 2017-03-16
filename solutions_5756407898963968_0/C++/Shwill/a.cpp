#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
vi a;
vi b;
vi c;

void solve()
{
	c = a;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vi::iterator newEnd = set_intersection(a.begin(), a.end(),
	                                       b.begin(), b.end(),
	                                       c.begin());
	c.resize(newEnd - c.begin());
}

int main()
{
	// Get number of cases
	int T; cin >> T;
	// Run each test case
	for (int caseNum = 1; caseNum <= T; caseNum++)
	{
		a.clear(); b.clear();
		// First set
		int row; cin >> row;
		for (int j = 1; j <= 4; j++)
		for (int i = 1; i <= 4; i++)
		{
			int temp; cin >> temp;
			if (j == row)
				a.push_back(temp);
		}
		// Second set
		cin >> row;
		for (int j = 1; j <= 4; j++)
		for (int i = 1; i <= 4; i++)
		{
			int temp; cin >> temp;
			if (j == row)
				b.push_back(temp);
		}
		// Get union
		solve();
		// Output solution
		if (c.size() == 0)
			printf("Case #%i: Volunteer cheated!\n", caseNum);
		else if (c.size() == 1)
			printf("Case #%i: %i\n", caseNum, c.front());
		else
			printf("Case #%i: Bad magician!\n", caseNum);
	/////////////////////////////////////
	}
	return 0;
}
