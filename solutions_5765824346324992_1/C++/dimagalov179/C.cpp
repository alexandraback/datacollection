#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#define int long long int

using namespace std;

main()
{
	int TESTS;
	cin >> TESTS;
	for (int test = 0; test < TESTS; ++test)
	{
		int n, k;
		cin >> n >> k;
		vector<int> A(n);
		for (int i = 0; i < n; ++i)
			cin >> A[i];

		int L = 0LL, R = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;

		while (R - L > 100LL)
		{
			int M = (L + R) / 2;
			int amount = 0LL;
			for (int i = 0; i < n; ++i)
				amount += M / A[i] + 1;
			if (amount >= k)
				R = M;
			else
				L = M;
		}
		int our;
		for (int M = L; M <= R; ++M)
		{
			int amount = 0LL;
			for (int i = 0; i < n; ++i)
				amount += M / A[i] + 1;
			if (amount >= k)
			{
				our = M;
				break;
			}
		}

		// cout << our << endl;
		// return 0;
		for (int i = 0; i < n; ++i)
			k -= (our + A[i] - 1) / A[i];
		// cout << k << endl;
		for (int i = 0; i < n; ++i)
			if (our % A[i] == 0)
			{
				// cout << i << endl;
				k -= 1;
				if (k == 0)
				{
					cout << "Case #" << test + 1 << ": " << i + 1 << endl;
					break;
				}
			}


	}	
}