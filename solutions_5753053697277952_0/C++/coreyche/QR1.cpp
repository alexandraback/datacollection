// QR1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int a[26];
int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) 
	{
		for (int i = 0; i < 26; i++)
		{
			a[i] = 0;
		}
		int p;
		cin >> p;
		int count = 0;
		for (int i = 0; i < p; i++)
		{
			int temp;
			cin >> temp;
			a[i] = temp;
			count += temp;
		}
		cout << "Case #" << tc<<":";
		while (count>0)
		{
			if (count % 2 == 0)
			{
				int max = 0;
				int index = 0;
				for (int i = 0; i < 26; i++)
				{
					if (a[i] > max)
					{
						max = a[i];
						index = i;
					}
				}
				a[index]--;

				int max1 = 0;
				int index1 = 0;
				for (int i = 0; i < 26; i++)
				{
					if (a[i] > max1)
					{
						max1 = a[i];
						index1 = i;
					}
				}
				a[index1]--;
				char h = 'A';
				h = h + index;
				char h1 = 'A' + index1;
				cout << " " << h<<h1;
				count=count-2;
			}
			else
			{
				int max = 0;
				int index = 0;
				for (int i = 0; i < 26; i++)
				{
					if (a[i] > max)
					{
						max = a[i];
						index = i;
					}
				}
				a[index]--;
				char h = 'A';
				h = h + index;
				cout << " " << h;
				count--;
			}
		}
		cout << endl;	
	}
	return 0;
}

