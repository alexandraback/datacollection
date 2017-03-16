#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORI(i, a, n) for(int i = (int)(a); i < (int)(n); i++)


int parties[27];


int getMax(int numOfParties)
{
	int max = 0;
	int which = -1;
	FOR(i, numOfParties)
	{
		if (parties[i] > max)
		{
			max = parties[i];
			which = i;
		}
	}

	return which;
}



int main()
{
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("A-small-attempt2.out", "wb", stdout);

	int numOfTestcases;
	std::cin >> numOfTestcases;

	FOR(i, numOfTestcases)
	{
		std::cout << "Case #" << (i + 1) << ":";

		FOR(j, 27) parties[j] = 0;

		int numOfParties;
		std::cin >> numOfParties;

		int total = 0;
		FOR(j, numOfParties)
		{
			std::cin >> parties[j];
			total += parties[j];
		}

		if (total % 2 == 1)
		{
			int idx = getMax(numOfParties);
			parties[idx]--;
			total--;
			std::cout << " " << (char)(idx + 65);
		}

		while (total > 0)
		{
			int idx = getMax(numOfParties);
			parties[idx]--;
			total--;
			std::cout << " " << (char)(idx + 65);

			idx = getMax(numOfParties);
			parties[idx]--;
			total--;
			std::cout << (char)(idx + 65);
		}


		std::cout << std::endl;
	}

	return 0;
}