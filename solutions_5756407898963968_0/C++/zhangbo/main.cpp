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

using namespace std;

void calc()
{
	static int caseno = 0;
	caseno++;

	set<int> s1;
	vector<int> s2;
	int r1, r2;
	cin >> r1;
	for (int r = 1; r <= 4; r++)
	{
		for (int c = 1; c <= 4; c++)
		{
			int v;
			cin >> v;
			if (r == r1) s1.insert(v);
		}
	}
	cin >> r2;
	for (int r = 1; r <= 4; r++)
	{
		for (int c = 1; c <= 4; c++)
		{
			int v;
			cin >> v;
			if (r == r2 && s1.count(v)) s2.push_back(v);
		}
	}

	cout << "Case #" << caseno << ": ";
	if (s2.size() == 0)
	{
		cout << "Volunteer cheated!";
	}
	else if (s2.size() == 1)
	{
		cout << s2[0];
	}
	else
	{
		cout << "Bad magician!";
	}
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

