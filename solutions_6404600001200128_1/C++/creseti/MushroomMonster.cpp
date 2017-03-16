#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <hash_set>
#include <array>

#define FILE_BUF_SIZE 512
#define MAX_PLATE 1000

using namespace std;



int main()
{
	// Prepare file
	FILE* inputFile;
	fopen_s(&inputFile, "A-large.in", "r");
	if (inputFile == nullptr)
	{
		printf("Input file open error!\n");
	}

	FILE* outputFile;
	fopen_s(&outputFile, "Large-Output.txt", "w");
	if (outputFile == nullptr)
	{
		printf("Output file open error!\n");
	}

	// Read count of test case
	char fileBuf[FILE_BUF_SIZE + 1];
	fgets(fileBuf, FILE_BUF_SIZE + 1, inputFile);
	int countOfTestCase = atoi(fileBuf);
		
	int countOfMushroom[MAX_PLATE];
	for (int caseNo = 1; caseNo <= countOfTestCase; caseNo++)
	{
		memset(countOfMushroom, -1, sizeof(countOfMushroom));

		// Read count of plate
		fgets(fileBuf, FILE_BUF_SIZE + 1, inputFile);
		int countOfPlate = atoi(fileBuf);

		// Read count of mushroom
		for (int i = 0; i < countOfPlate; i++)
		{
			fscanf(inputFile, "%d", &countOfMushroom[i]);
		}
		fgets(fileBuf, FILE_BUF_SIZE + 1, inputFile);

		// Calculate x
		int x = 0;
		int maxGap = 0;
		for (int i = 0; i < countOfPlate - 1; i++)
		{
			int gap = countOfMushroom[i] - countOfMushroom[i + 1];			
			if (gap > 0)
			{
				x += gap;
				maxGap = max(maxGap, gap);
			}
		}

		// Calculate y
		int y = 0;
		for (int i = 0; i < countOfPlate - 1; i++)
		{
			y += min(countOfMushroom[i], maxGap);
		}

		fprintf(outputFile, "Case #%d: %d %d\n", caseNo, x, y);
		INT_MAX;
	}

	return 1;
}
