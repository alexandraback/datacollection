// Q2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define FO(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;

using namespace std;

int getMin(int arr[], int count)
{
	int min = arr[0];
	for (int i = 1; i < count; i++)
		if (arr[i] < min)
			min = arr[i];

	return min;
}

int getMax(int arr[], int count)
{
	int max = arr[0];
	for (int i = 1; i < count; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}

void SortAsc(int arr[], int count)
{
    int temp;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void SortDesc(int arr[], int count)
{
    int temp;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("q2.in", "r", stdin);
	freopen("q2.out", "w", stdout);

	int t;
	cin >> t;

	FO(i, 0, t)
	{
		cout << "Case #" << i + 1 << ": ";

		int r, c ,n;
		cin >> r >> c >> n;

		if (r > c)
			swap (r, c);

		long totalWalls = (r - 1) * c + (c - 1) * r;
		long solution = 0;

		if (n == r * c)
			solution = totalWalls;

		else if (r == 1)
			solution = totalWalls - (c - n) * 2 > 0? totalWalls - (c - n) * 2 : 0;

		else if (r == 2)
		{
			if (c >= n)
				solution = 0;
			else
			{
				if (n - c <= 2)
					solution = 2 * (n - c);
				else
					solution = 3 * (n - c - 2) + 4;
			}
		}

		else if (r == 3)
		{
			if ((c % 2 == 0 && n <= r * c / 2) || (c % 2 == 1 && n <= r * c / 2 + 1))
				solution = 0;
			else
			{
				if (c == 3)
				{
					if (n == 6)
						solution = 3;
					if (n == 7)
						solution = 6;
					if (n == 8)
						solution = 8;
				}
				if (c == 4)
				{
					if (n == 7)
						solution = 2;
					if (n == 8)
						solution = 4;
					if (n == 9)
						solution = 7;
					if (n == 10)
						solution = 10;
					if (n == 11)
						solution = 13;
				}
				if (c == 5)
				{
					if (n == 9)
						solution = 3;
					if (n == 10)
						solution = 6;
					if (n == 11)
						solution = 8;
					if (n == 12)
						solution = 11;
					if (n == 13)
						solution = 14;
					if (n == 14)
						solution = 18;
				}
			}
		}

		else if (r == 4)
		{
			if (n <= r * c / 2)
				solution = 0;
			else
			{
				if (n == 9)
					solution = 2;
				if (n == 10)
					solution = 4;
				if (n == 11)
					solution = 7;
				if (n == 12)
					solution = 10;
				if (n == 13)
					solution = 13;
				if (n == 14)
					solution = 16;
				if (n == 15)
					solution = 20;
			}
		}
		
		cout << solution << endl;
	}

	return 0;
}

