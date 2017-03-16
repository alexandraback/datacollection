#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ifstream fin("1.in");
ofstream fout("1.out");

int t, n;

struct Sen
{
	char p;
	int c;
};

bool cmp(const Sen &s1, const Sen &s2)
{
	return s1.c > s2.c;
}

int main()
{
	fin >> t;
	Sen *a = new Sen[10000];
	for (int qq = 0; qq < t; qq++)
	{
		fout << "Case #" << qq + 1 << ": ";
		fin >> n;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			fin >> a[i].c;
			a[i].p = i + 'A';
			count += a[i].c;
		}
		sort(a, a + n, cmp);
		a[n] = {-1, -1};
		int j = 0;
		while (a[j].c > 1)
		{
			while (a[j].c == a[j + 1].c)
				j++;
			for (int i = 1; i <= j; i += 2)
			{
				fout << a[i - 1].p << a[i].p << ' ';
				a[i - 1].c--;
				a[i].c--;
			}
			if ((j % 2) == 0)
			{
				fout << a[j].p << ' ';
				a[j].c--;
			}
		}
		int st = 0;
		if ((n % 2) == 1)
		{
			st = 1;
			fout << a[0].p << ' ';
		}
		for (int i = st; i < n; i += 2)
			fout << a[i].p << a[i + 1].p << ' ';
		fout << "\n";
	}
	return 0;
}
