
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
#include <unordered_map>
#include <unordered_set>
#include <memory>
using namespace std;

char s[128];

vector<int> k[128];
vector<char> p[128];


int main()
{
	gets(s);
	int test_cases;
	sscanf(s, "%d", &test_cases);

	for (int test_case = 1; test_case <= test_cases; test_case++)
	{
		gets(s);
		int n;
		sscanf(s, "%d", &n);
		for (int i = 0; i < n; i++)
		{
			gets(s);

			k[i].clear();
			p[i].clear();

			char q = 0;
			for (char* c = s; *c != '\0'; c++)
			{
				if (*c == q)
				{
					k[i].back()++;
				}
				else
				{
					k[i].push_back(1);
					p[i].push_back(*c);
					q = *c;
				}
			}
		}

		bool f = false;
		for (int i = 1; i < n; i++)
		{
			if (k[i].size() != k[0].size())
			{
				f = true;
				break;
			}
		}

		vector<int> g(p[0].size());

		if (!f)
		{
			for (int j = 0; j < p[0].size(); j++)
			{
				int mk = k[0][0];

				for (int i = 1; i < n; i++)
				{
					if (p[0][j] != p[i][j])
					{
						f = true;
						break;
					}

					if (k[i][j] > mk)
					{
						mk = k[i][j];
					}
				}

				if (f)
				{
					break;
				}

				g[j] = mk;
			}
		}

		if (f)
		{
			printf("Case #%d: Fegla Won\n", test_case);
		}
		else
		{
			int ans = 0;

			for (int j = 0; j < p[0].size(); j++)
			{
				int ma = 1e9;
				for (int t = 1; t <= g[j]; t++)
				{
					int a = 0;
					for (int i = 0; i < n; i++)
					{
						a += std::abs(k[i][j] - t);
					}

					if (a < ma)
					{
						ma = a;
					}
				}
				ans += ma;
			}

			printf("Case #%d: %d\n", test_case, ans);
		}
	}

	return 0;
}