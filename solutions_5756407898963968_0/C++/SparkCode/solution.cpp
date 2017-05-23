#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:64000000")
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#include <memory.h>
#include <limits.h>
#include <queue>

using namespace std;

void prepare(string s)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	if (s.size() != 0)
	{
		freopen((s + ".in").c_str(), "r", stdin);
		freopen((s + ".out").c_str(), "w", stdout);
	}
#endif
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
}

map <int, bool> used;

int main()
{
	prepare("");
	int T;
	cin >> T;
	for (size_t i = 0; i < T; i++)
	{
		int row;
		cin >> row;
		row--;
		for (size_t j = 0; j < 4; j++)
		{
			for (size_t q = 0; q < 4; q++)
			{
				int temp;
				cin >> temp;
				if (j == row)
				{
					used[temp] = 1;
				}
			}
		}

		cin >> row;
		row--;
		bool flag = 1;
		int res = -1;
		for (size_t j = 0; j < 4; j++)
		{
			for (size_t q = 0; q < 4; q++)
			{
				int temp;
				cin >> temp;
				if (j == row && used[temp] == 1)
				{
					if (res == -1)
					{
						res = temp;
					}
					else
						flag = 0;
					
				}
				
			}
		}
		used.clear();

		cout << "Case #" << i + 1 << ": ";
		if (!flag)
		{
			cout << "Bad magician!\n";
			continue;
		}
		else
		if (flag && res == -1)
		{
			cout << "Volunteer cheated!\n";
			continue;
		}
		else
			cout << res << endl;
		
		
	}
	return 0;
}
