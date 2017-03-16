#include <stdio.h>
#include <iostream>

using namespace std;

int t;
FILE *inputFile, *outputFile;
int *firstLine, *secondLine, *junkLine;

void readTestCaseLine(int *line)
{
	int rowNumber;
	fscanf(inputFile, "%d", &rowNumber);
	
	for (int j = 0; j < rowNumber-1; j++)
	{
		fscanf(inputFile, "%d %d %d %d", &junkLine[0], &junkLine[1], &junkLine[2], &junkLine[3]);
	}
	fscanf(inputFile, "%d %d %d %d", &line[0], &line[1], &line[2], &line[3]);
	for (int j = rowNumber; j < 4; j++)
	{
		fscanf(inputFile, "%d %d %d %d", &junkLine[0], &junkLine[1], &junkLine[2], &junkLine[3]);
	}
}

int findCommon(int *firstLine, int *secondLine)
{
	int common = -2;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (firstLine[i] == secondLine[j])
			{
				if (common == -2)
				{
					common = firstLine[i];
				}
				else
				{
					return -1;
				}
			}
		}
	}

	return common;
}

int main(int argc,char *argv[])
{
	firstLine = new int[4];
	secondLine = new int[4];
	junkLine = new int[4];

	inputFile = fopen(argv[1], "r");
	outputFile = fopen(argv[2], "w");

	fscanf(inputFile, "%d", &t);

	for (int i = 0; i < t; i++)
	{
		readTestCaseLine(firstLine);
		readTestCaseLine(secondLine);

		int result = findCommon(firstLine, secondLine);
		if (result > 0)
		{
			fprintf(outputFile, "Case #%d: %d\n", i+1, result);
		}
		else
		{
			if (result == -1)
			{
				fprintf(outputFile, "Case #%d: Bad magician!\n", i+1);
			}
			else if (result == -2)
			{
				fprintf(outputFile, "Case #%d: Volunteer cheated!\n", i+1);
			}
		}
	}
}