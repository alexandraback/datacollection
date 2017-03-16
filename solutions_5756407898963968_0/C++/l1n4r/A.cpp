
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <memory.h>
using namespace std;

int a[4][4];
int b[4][4];

int main()
{
	string name = "A-small";
	string path = "";
	//string path = "/Users/linar/Downloads/";

	freopen((path + name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);

	int test_cases;
	scanf("%d", &test_cases);

	for (int test_case = 1; test_case <= test_cases; test_case++)
	{
		int x, y;

		scanf("%d", &x);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		scanf("%d", &y);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				scanf("%d", &b[i][j]);
			}
		}

		x--;
		y--;

		vector<int> c(17, 0);

		for (int j = 0; j < 4; j++)
		{
			c[a[x][j]]++;
			c[b[y][j]]++;
		}

		int ans;
		int n = 0;
		for (int i = 1; i <= 16; i++)
		{
			if (c[i] == 2)
			{
				n++;
				ans = i;
			}
		}

		if (n == 1)
		{
			printf("Case #%d: %d\n", test_case, ans);
		}
		else if (!n)
		{
			printf("Case #%d: Volunteer cheated!\n", test_case);
		}
		else
		{
			printf("Case #%d: Bad magician!\n", test_case);
		}
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}
