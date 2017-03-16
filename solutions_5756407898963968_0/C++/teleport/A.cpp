#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define y0 isdnfviu
#define y1 asinhiv
#define fst first
#define snd second
#define count sdifnsugh

int c[22];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	for (int g = 1; g <= q; g++)
	{
		memset(c, 0, sizeof(c));
		int num1, num2;
		cin >> num1;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				int x;
				cin >> x;
				if (i == num1)
					c[x]++;
			}
		cin >> num2;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				int x;
				cin >> x;
				if (i == num2)
					c[x]++;
			}
		cout << "Case #" << g << ": ";
		int kol = 0, num = -1;
		for (int i = 1; i <= 16; i++)
			if (c[i] == 2)
				kol++, num = i;
		if (kol == 0)
			cout << "Volunteer cheated!\n";
		else if (kol > 1)
			cout << "Bad magician!\n";
		else
			cout << num << endl;
	}
	cin >> q;
	return 0;
}
