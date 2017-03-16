#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;



void input()
{
	vector<int> sa, sb;
	int a, x;
	scanf("%d", &a);
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			scanf("%d", &x);
			if (i == a)
			{
 				sa.push_back(x);
			}
		}
	}

	scanf("%d", &a);
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			scanf("%d", &x);
			if (i == a)
			{
 				sb.push_back(x);
			}
		}
	}

	vector<int> ret;
	for (int i = 0; i < sa.size(); ++i)
	{
		
		for (int j = 0; j < sb.size(); ++j)
		{
			if (sa[i] == sb[j]) ret.push_back(sa[i]);
		}
	}

	if (ret.size() == 0)
	{
		printf("Volunteer cheated!\n");
	}
	else if (ret.size() == 1)
	{
		printf("%d\n", ret[0]);
	}
	else
	{
		printf("Bad magician!\n");
	}
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T;
	scanf("%d", &T);

	for (int test = 1; test <= T; ++test)
	{
		printf("Case #%d: ", test);
		input();
	}

	return 0;
}