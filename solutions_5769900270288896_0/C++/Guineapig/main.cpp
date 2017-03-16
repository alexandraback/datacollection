#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <limits>
using namespace std;

// #pragma warning(disable: 4018)
// #include "../my_header.h"


struct solver
{
	int solve(int R, int C, int N)
	{
		int min_unhappiness = 100000;
		int Na = R * C;
		for (int mask=0 ; mask < (1 << Na) ; mask++)
		{
			bool cells[16][16];
			for (int i=0 ; i < 16 ; i++)
				for (int j=0 ; j < 16 ; j++)
					cells[i][j] = false;
			int count = 0;
			for (int i=0 ; i < 16 ; i++)
				if ((mask >> i) & 1)
				{
					int row = i / C;
					int col = i % C;
					cells[row][col] = true;
					count++;
				}
			if (count == N)
			{
				int unhappiness = 0;
				for (int r=0 ; r < R ; r++)
					for (int c=0 ; c < C-1 ; c++)
						if (cells[r][c] && cells[r][c+1])
							unhappiness++;
				for (int c=0 ; c < C ; c++)
					for (int r=0 ; r < R-1 ; r++)
						if (cells[r][c] && cells[r+1][c])
							unhappiness++;
				if (unhappiness < min_unhappiness)
					min_unhappiness = unhappiness;
			}
		}
		return min_unhappiness;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
	int R, C, N;

	ifs >> R >> C >> N;

	long long res = solver().solve(R, C, N);

	cout << "Case #" << case_num << ": " << res << endl;
	ofs << "Case #" << case_num << ": " << res << endl;
}

/*************************************************************************************/

int main(int argc, char **argv)
{
	if (argc != 3) {
		cout << "Usage: runme <input file> <output file>" << endl;
		return 1;
	}

	ifstream ifs(argv[1], ifstream::in);
	ofstream ofs(argv[2]);

	ofs.precision(7);
	ofs << fixed;


	int n; // = to_int(get_line(ifs));
	ifs >> n;
	// assert(n > 0 && n < 200);

	cerr << n << endl;
	
	for (int i=0 ; i < n ; i++)
	{
		// if (i > 0)
		// 	cout << "\n---------------------------------------------\n\n";
		process_test_case(i+1, ifs, ofs);
	}

	return 0;
}
