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

ofstream fout("mushroom.out");
ifstream fin("mushroom.in");

const int MAX_N = 1000;
int n;
int numPancakes[MAX_N];

int resInf, resFixed;

void solve()
{
	resInf = 0;
	int maxD = 0;
	for (int i = 1; i < n; i++)
	{
		int d = numPancakes[i - 1] - numPancakes[i];
		if (d > 0) resInf += d;
		maxD = max(maxD, d);
	}
	resFixed = 0;
	for (int i = 0; i < n - 1; i++)
	{
		resFixed += min(maxD, numPancakes[i]);
	}
	
}

int main()
{
	int numTests;
	fin >> numTests;
	for (int test = 1; test <= numTests; test++)
	{
		fin >> n;
		for (int i = 0; i < n; i++)
		{
			fin >> numPancakes[i];
		}
		solve();
		fout << "Case #" << test << ": " << resInf << " " << resFixed << endl;
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