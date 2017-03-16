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

ofstream fout("sincap.out");
ifstream fin("sincap.in");

const int MAX_N = 15;

struct P
{
	double x, y, a;
	int i;
};

bool ccw(P p1, P p2, P p3)
{
	return (p2.x - p1.x) * (p3.y - p1.y) < (p2.y - p1.y) * (p3.x - p1.x);
}

bool sf(P a, P b)
{
	return a.a < b.a;
}

int numPs;
P inps[MAX_N];

bool standing[MAX_N];
vector<P> graham()
{
	vector<P> ps;
	for (int i = 0; i < numPs; i++)
	{
		if (standing[i])
		{
			ps.push_back(inps[i]);
		}
	}
	int n = ps.size();

	P lowest;
	lowest.y = FLT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (ps[i].y < lowest.y)
		{
			lowest = ps[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		ps[i].a = atan2(ps[i].y - lowest.y, ps[i].x - lowest.x);
	}
	sort(ps.begin(), ps.end(), sf);

	ps.resize(n + 1);
	ps.back() = ps.front();

	int m = 1;
	for (int i = 2; i <= n; i++)
	{
		while (ccw(ps[m - 1], ps[m], ps[i]))
		{
			if (m > 1) m--;
			else if (i == n) break;
			else i++;
		}
		m++;
		swap(ps[m], ps[i]);
	}

	ps.resize(m);

	P p0 = ps.back();
	for (int i = 0; i < m; i++)
	{
		P p1 = ps[i];
		
		for (int j = 0; j < numPs; j++)
		{
			if (standing[j])
			{
				if ((p1.x - p0.x) * (inps[j].y - p0.y) == (p1.y - p0.y) * (inps[j].x - p0.x))
				{
					bool isIncluded = false;
					for (const P& p : ps)
					{
						if (p.i == j)
						{
							isIncluded = true;
							break;
						}
					}
					if (!isIncluded)
					{
						ps.push_back(inps[j]);
					}
				}
			}
		}

		p0 = p1;
	}

	return ps;
}

int res[MAX_N];
void solve()
{
	if (numPs <= 3)
	{
		for (int i = 0; i < numPs; i++)
		{
			res[i] = 0;
		}
		return;
	}

	for (int i = 0; i < numPs; i++)
	{
		res[i] = numPs;
	}

	for (int i = 0; i < (1 << numPs); i++)
	{
		int numCut = 0;
		for (int j = 0; j < numPs; j++)
		{
			if (i & (1 << j))
			{
				standing[j] = true;
			}
			else
			{
				standing[j] = false;
				numCut++;
			}
		}
		if (numCut <= numPs - 3)
		{
			vector<P> ps = graham();
			for (const P& p : ps)
			{
				int index = p.i;
				res[index] = min(res[index], numCut);
			}
		}
	}
}

int main()
{
	int numTests;
	fin >> numTests;
	for (int test = 1; test <= numTests; test++)
	{
		fin >> numPs;
		for (int i = 0; i < numPs; i++)
		{
			fin >> inps[i].x >> inps[i].y;
			inps[i].i = i;
		}
		solve();
		fout << "Case #" << test << ":" << endl;
		for (int i = 0; i < numPs; i++)
		{
			fout << res[i] << endl;
		}
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