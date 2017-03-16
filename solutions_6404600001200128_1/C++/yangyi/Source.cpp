#pragma warning(disable: 4996)
#include <string>
#include <cctype>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <memory.h>
#include <assert.h>
using namespace std;

//A. Mushroom

int m[1050];
int n;
int res1,res2;


//method 1: diff add
//method 2: biggest diff is the rate

int main(void)
{
	freopen("A-large.in", "r", stdin);
	freopen("Alarge.out", "w", stdout);
	int nTest;

	scanf("%d", &nTest);
	for (int tc = 0; tc < nTest; tc++)
	{
		scanf("%d", &n);
		res1 = 0;
		res2 = 0;
		int maxrate = 0;
		for (int i = 0; i < n ; i++)
		{
			scanf("%d", m + i);
			if (i)
			{
				res1 += max (m[i-1] - m[i ], 0);
				maxrate = max(maxrate, m[i - 1] - m[i]);
			}
		}

		for (int i = 0; i < n-1; i++)
		{
			res2 += min(maxrate, m[i]);
		}

		cout << "Case #" << tc+1 << ": " << res1 << " " << res2 << endl;
		fflush(stdout);

	}

	return 1;
}