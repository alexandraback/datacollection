// probA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <algorithm>

using namespace std;

struct senat
{
	int val;
	int pos;
};

senat a[10000];

bool comp(senat a, senat b)
{
	if (a.val > b.val) return true;
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("data.in");
	ofstream fout("data.out");
	int t,j;
	fin >> t;
	for (j = 1; j <= t; j++)
	{
		int n;
		fin >> n;
		int nr;
		int tot = 0;
		for (int i = 0; i < n; i++)
		{
			fin >> nr;
			a[i].val = nr;
			a[i].pos = i;
			tot += nr;
		}
		fout << "Case #" << j << ": ";
		while (tot > 0)
		{
			sort(a, a + n, comp);
			if (tot == 2)
			{
				fout << (char)('A' + a[0].pos) << (char)('A' + a[1].pos) << '\n';
				tot = 0;
			}
			else
			{
				if ((tot - 1) / 2 < a[1].val)
				{
					fout << (char)('A' + a[0].pos) << (char)('A' + a[1].pos) << ' ';
					a[0].val--;
					tot--;
					a[1].val--;
					tot--;
				}
				else
				{
					fout << (char)('A' + a[0].pos) << ' ';
					a[0].val--;
					tot--;
				}
			}
		}
	}
	return 0;
}

