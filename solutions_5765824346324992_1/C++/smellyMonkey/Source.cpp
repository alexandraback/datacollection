#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <functional>
#include <string>
#include <cstdlib>
#include <set>
#include <stdio.h>
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("data.in");
	outFile.open("data.out");

	
	int T;
	inFile >> T;

	for (int ca = 1; ca <= T; ++ca)
	{
		int b, n;
		inFile >> b >> n;

		vector<int> m(b);
		for (int i = 0; i < b; ++i)
		{
			inFile >> m[i];
		}


		long long int left = 0, right = 1000000000000000;
		long long int before = 0;

		while (left <= right)
		{
			long long int mid = (left + right) >> 1;

			long long int total = 0;
			long long int exaxt = 0;

			for (int i = 0; i < b; ++i)
			{
				total += mid / m[i] + 1;				
			}


			if (total < n)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}

		}

		long long int t = left;

		for (int i = 0; i < b; ++i)
		{
			before += t / m[i] + 1;
			if (t % m[i] == 0)
				before--;
		}

		int ans = -1;

		for (int i = 0; i < b; ++i)
		{
			if (t % m[i] == 0)
			{
				if (before == n - 1)
				{
					ans = i;
					break;
				}
				else
				{
					before++;
				}
			}
		}

		
		outFile << "Case #" << ca << ": " << ans+1 << endl;
		//cout << ans << endl;
	}


	inFile.close();
	outFile.close();

	return 0;
}
