#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cfloat>

using namespace std;

typedef long long ll;

ofstream fout("berber.out");
ifstream fin("berber.in");

const int MAX_B = 1000;

int n, b;
int times[MAX_B];

int busy[MAX_B];
int solve()
{
	ll begin = 0;
	ll inc = 1;
	while (inc > 0)
	{
		ll now = begin + inc;
		ll passed = 0;
		for (int i = 0; i < b; i++)
		{
			passed += (int)(now / times[i]);
		}
		if (passed < n - 2 * b)
		{
			begin = now;
			inc *= 2;
		}
		else
		{
			inc /= 2;
		}
	}

	int passed = 0;
	for (int i = 0; i < b; i++)
	{
		passed += (int)(begin / times[i]);
		passed++;
	}
	
	for (int i = 0; i < b; i++)
	{
		busy[i] = (int)(begin % times[i]);
		if (busy[i] == 0) passed--;
	}

	n -= passed;

	int atCustomer = 0;
	while (true)
	{
		int forward = busy[0];
		for (int i = 0; i < b; i++)
		{
			if (busy[i] == 0)
			{
				atCustomer++;
				if (atCustomer == n) return i + 1;
				busy[i] = times[i];
			}
			forward = min(forward, busy[i]);
		}
		for (int i = 0; i < b; i++)
		{
			busy[i] -= forward;
		}
	}
}

int main()
{
	int numTests;
	fin >> numTests;
	for (int test = 1; test <= numTests; test++)
	{
		fin >> b >> n;
		for (int i = 0; i < b; i++)
		{
			fin >> times[i];
		}
		fout << "Case #" << test << ": " << solve() << endl;
	}

	return 0;
}

/*
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cfloat>

using namespace std;

typedef long long ll;

int main()
{

return 0;
}
*/

/*



*/