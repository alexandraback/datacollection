#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cmath>
#include <ctime>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		vector<int>a(k);
		int sum = 0;
		for (int i = 0; i < k; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		cout << "Case #"<<i+1<<": " ;
		while (sum > 0)
		{
			int max1 = 0;
			int max2 = 0;
			if (a[1] > a[0])
			{
				max1 = 1;
				max2 = 0;
			}
			else
			{
				max1 = 0;
				max2 = 1;
			}
			for (int i = 2; i < k; i++)
			{
				if (a[i] > a[max1])
				{
					max2 = max1;
					max1 = i;
					continue;
				}
				if (a[i] > a[max2])
				{
					max2 = i;
				}
			}
			if (a[max1] > 1)
			{
				a[max1] -= 2;
				sum -= 2;
				bool k = true;
				for (int i = 0; i < a.size(); i++)
				{
					if (a[i] * 2 > sum)
					{
						k = false;
					}
				}
				if (k) { cout << (char)('A' + max1) << (char)('A' + max1) << " ";  continue; }
				if (!k)
				{
					a[max1] += 2;
					sum += 2;
				}
			}
			if (a[max1] > 0&&a[max2]>0)
			{
				a[max1] --;
				a[max2]--;
				sum -= 2;
				bool k = true;
				for (int i = 0; i < a.size(); i++)
				{
					if (a[i] * 2 > sum)
					{
						k = false;
					}
				}
				if (k) { cout << (char)('A' + max1) << (char)('A' + max2) << " "; continue; }
				if (!k)
				{
					a[max1]++;
					a[max2]++;
					sum += 2;
				}
			}
			cout << (char)('A' + max1) << " ";
			a[max1]--;
			sum--;
		}
		cout << endl;
	}
	return 0;
}