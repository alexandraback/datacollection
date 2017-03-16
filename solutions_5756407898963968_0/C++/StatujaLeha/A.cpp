// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <set>

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream in("A-small.in");
	int T;
	in >> T;
	for (int i = 0; i < T; ++i)
	{
		int a1, a2, R1[4][4], R2[4][4];
		in >> a1;
		for (int x = 0; x < 4; ++x)
			for (int y = 0; y < 4; ++y)
				in >> R1[x][y];

		in >> a2;
		for (int x = 0; x < 4; ++x)
			for (int y = 0; y < 4; ++y)
				in >> R2[x][y];

		std::set<int> common;
		for (int x1 = 0; x1 < 4; ++x1)
			for (int x2 = 0; x2 < 4; ++x2)
				if (R1[a1 - 1][x1] == R2[a2 - 1][x2]) common.insert(R2[a2 - 1][x2]);

		if (0 == common.size())
			std::cout << "Case #" << (i + 1) << ": Volunteer cheated!\n";
		else if (1 == common.size())
			std::cout << "Case #" << (i + 1) << ": " << (*common.begin()) <<"\n";
		else
			std::cout << "Case #" << (i + 1) << ": Bad magician!\n";
	}
	return 0;
}

