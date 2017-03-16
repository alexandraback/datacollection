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

int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
int lcm(int a, int b) {return a * b / gcd(a, b); }

int busy[MAX_B];
int solve()
{
	int l = 1;
	for (int i = 0; i < b; i++)
	{
		l = lcm(l, times[i]);
	}
	int mod = 0;
	for (int i = 0; i < b; i++)
	{
		mod += l / times[i];
	}
	n = (n - 1) % mod + 1;

	for (int i = 0; i < b; i++)
	{
		busy[i] = 0;
	}

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