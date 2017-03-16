// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

const int maxn = 26;
int p[maxn];
int order[maxn];


bool mycmp(int x, int y)
{
	if (p[order[x]] < p[order[y]]) return true;
	else return false;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n = 0, tot = 0;
		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			cin >> p[j];
			order[j] = j;
			tot += p[j];
		}
		sort(order, order + n, mycmp);
		cout << "Case #" << i + 1 << ":";
		while (tot != 0)
		{
			while (2 * p[order[n - 1]] <= tot - 1)
			{
				for (int j = 0; j < n; ++j) if (p[order[j]] != 0)
				{
					cout << " " << (char)('A' + order[j]);
					p[order[j]] --;
					break;
				}
				tot--;
			}
			if (p[order[n - 1]] == p[order[n - 2]])
			{
				cout << " " << (char)('A' + order[n - 1]) << (char)('A' + order[n - 2]);
				p[order[n - 1]] --;
				p[order[n - 2]] --;
				tot -= 2;
			}
			else
			{
				cout << " " << (char)('A' + order[n - 1]);
				p[order[n - 1]] --;
				tot--;
			}
		}
		cout << endl;
	}
	
	return 0;
}

