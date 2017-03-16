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
/*
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
*/

//B. Haircut

int B[1020];

int gcd(int a, int b)
{
	for (;;)
	{
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}

int lcm(int a, int b)
{
	int temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}
int ArrayGCD(int *a, int first, int last)
{
	int x = 0, y = 0, gcd = 0;
	if (first == last)
	{
		gcd = a[first];
		return gcd;
	}
	else
	{
		x = ArrayGCD(a, first, (first + last) / 2);
		y = ArrayGCD(a, (first + last) / 2 + 1, last);
		if (x < 0)
		{
			x = -x;
		}
		if (y < 0)
		{
			y = -y;
		}
		while (x != y)
		{
			if (x > y)
			{
				x = x - y;
			}
			else
			{
				y = y - x;
			}
		}
		gcd = x;
		return gcd;
	}
}

int main(void)
{
	freopen("B-small-attempt0 (1).in", "r", stdin);
	//freopen("1.txt", "r", stdin);
	freopen("Bsmall.out", "w", stdout);
	int nTest;
	int numOfB;
	int waitP;
	scanf("%d", &nTest);
	for (int tc = 0; tc < nTest; tc++)
	{
		scanf("%d", &numOfB);
		scanf("%d", &waitP);
		for (int i = 0; i < numOfB; i++)
		{
			scanf("%d", B + i);
		}

		int LargeCM = std::accumulate(B, B + numOfB, 1, lcm);

		int groupCustomer=0;

		for (int i = 0; i < numOfB; i++)
		{
			groupCustomer += LargeCM / B[i];
		}
		waitP = waitP%groupCustomer;
		if (waitP==0)
		{
			waitP = groupCustomer;
		}

		//start simulation
		int GCDCM = ArrayGCD(B, 0, numOfB - 1);

		int time = 0;
		int finished=0;
		int found = false;
		int res = 0;
		while (!found)
		{
			for (int i = 0; i < numOfB ; i++)
			{
				if (time%B[i] == 0)
				{
					finished++;
					if (finished==waitP)
					{
						res = i + 1;
						found = true;
						break;
					}
				}
			}


			time += GCDCM;
		}



		cout << "Case #" << tc + 1 << ": " << res  << endl;
		fflush(stdout);

	}

	return 1;
}