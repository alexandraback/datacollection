#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const char inFileName[] = "A-small.in";
const char outFileName[] = "A-small.out";

const int MaxN = 200;

int T, r1, r2;
int a1[5][5], a2[5][5];

int main() {
	
	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++) 
	{
		fscanf(inFile, "%d", &r1);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				fscanf(inFile, "%d", &a1[i][j]);

		fscanf(inFile, "%d", &r2);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				fscanf(inFile, "%d", &a2[i][j]);

		int count = 0;
		int ind = 0;
		for (int i = 1; i <= 4; i++)
		{
			bool found = false;
			for (int j = 1; j <= 4 && !found; j++)
			{
				if (a2[r2][j] == a1[r1][i])
					found = true;
			}
			if (found) 
			{
				count++;
				ind = a1[r1][i];
			}
		}

		if (count == 0)
			fprintf(outFile, "Case #%d: Volunteer cheated!\n", t + 1);
		if (count == 1)
			fprintf(outFile, "Case #%d: %d\n", t + 1, ind);
		if (count > 1)
			fprintf(outFile, "Case #%d: Bad magician!\n", t + 1);
	}	
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
