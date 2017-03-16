// CodeJam 2014
// Autor: Benjamín de la Fuente Ranea

#include <stdarg.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

#include "BigIntegerLibrary.hh"

#define FILE_INPUT	"A-small-attempt0"

void main()
{
	freopen(FILE_INPUT".in", "r", stdin);
	freopen(FILE_INPUT".out", "w", stdout);

	unsigned numCases;
	scanf("%d\n", &numCases);
	for (unsigned j = 1; j <= numCases; ++j)
	{
		unsigned firstRow;
		scanf("%d\n", &firstRow);
		unsigned row1[4];
		for (unsigned i = 0; i < 4; ++i)
		{
			if (firstRow == i+1)
				scanf("%d %d %d %d\n", &row1[0], &row1[1], &row1[2], &row1[3]);
			else
				scanf("%*d %*d %*d %*d\n");
		}

		unsigned secondRow;
		scanf("%d\n", &secondRow);
		unsigned row2[4];
		for (unsigned i = 0; i < 4; ++i)
		{
			if (secondRow == i+1)
				scanf("%d %d %d %d\n", &row2[0], &row2[1], &row2[2], &row2[3]);
			else
				scanf("%*d %*d %*d %*d\n");
		}

		unsigned count = 0;
		unsigned value = 0;
		for (unsigned i = 0; i < 4; ++i)
		{
			for (unsigned k = 0; k < 4; ++k)
			{
				if (row1[i] == row2[k])
				{
					++count;
					value = row1[i];
				}
			}
		}

		if (count == 0)
			printf("Case #%d: Volunteer cheated!\n", j);
		else if (count == 1)
			printf("Case #%d: %d\n", j, value);
		else
			printf("Case #%d: Bad magician!\n", j);
	}
}
