// gj.cpp
//

#include <assert.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned __int64 uint64;

#define EPS (1E-10)
#define PI 3.1415926535897932384626433832795

uint f[4][4],
	 s[4][4];

int main(int argc, char* argv[])
{
	uint64 cases;
	cin >> cases;

	for (uint64 i = 1; i <= cases; ++i)
	{
		uint rf;
		cin >> rf;
		--rf;

		for (uint j = 0; j < 4; ++j)
			for (uint jj = 0; jj < 4; ++jj)
				cin >> f[j][jj];

		uint rs;
		cin >> rs;
		--rs;

		for (uint j = 0; j < 4; ++j)
			for (uint jj = 0; jj < 4; ++jj)
				cin >> s[j][jj];

		uint ne = 0,
			 ix = -1;
		for (uint j = 0; j < 4; ++j)
		{
			for (uint jj = 0; jj < 4; ++jj)
			{
				if (f[rf][j] == s[rs][jj])
				{
					++ne;
					ix = j;
				}
			}
		}

		if (ne == 0)
			cout << "Case #" << i << ": Volunteer cheated!" << endl;
		else if (ne > 1)
			cout << "Case #" << i << ": Bad magician!" << endl;
		else
			cout << "Case #" << i << ": " << f[rf][ix] << endl;
	}

	return 0;
}
