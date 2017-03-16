#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "InputData.h"
#include "ResultData.h"

using namespace std;

int testRowsForRules(int* row1, int* row2)
{
	int numberOfResults = 0;
	int foundOccurence = 0;
	for (int i1=0; i1 < 4; i1++) {
		for (int i2 = 0; i2 < 4; i2++)
		{
			if (row1[i1] == row2[i2])
			{
				numberOfResults++;
				foundOccurence = row1[i1];
			}
		}
	}

	if (numberOfResults == 0)
		return VOLUNTEER_CHEATED;

	if (numberOfResults == 1)
		return foundOccurence;

	if (numberOfResults > 1)
		return BAD_MAGICIAN;
}

void processTestCase(TestCase& testCase, TestCaseResult& result)
{
	int firstChosenRow[4];
	for (int i = 0; i < 4; i++)
	{
		int index = (testCase.firstAnswerForRowNumber - 1) * 4 + i;
		firstChosenRow[i] = testCase.firstArrangement[index];
	}
	
	int secondChosenRow[4];
	for (int i = 0; i < 4; i++)
	{
		int index = (testCase.secondAnswerForRowNumber - 1) * 4 + i;
		secondChosenRow[i] = testCase.secondArrangement[index];
	}

	result.answer = testRowsForRules(firstChosenRow, secondChosenRow);
}

void processInputData(InputData& inputData, ResultData& resultData)
{
	int numberOfTestCases = inputData.getNumberOfTestCases();
	for (int testCaseIndex = 0; testCaseIndex < numberOfTestCases; testCaseIndex++)
	{
		TestCase testCase = inputData.getTestCase(testCaseIndex);
		TestCaseResult result;
		processTestCase(testCase, result);
		resultData.addResult(testCaseIndex, result);
	}
}

void main(int argc, char* argv[])
{
	// Check command line arguments
	if (argc < 3)
	{
		cerr << "Incorrect parameters. Usage: magic-trick.exe <input file path> <output file path>" << endl;
		return;
	}

	// Prepare data structures
	string inputFilePath = argv[1];
	InputData inputData(inputFilePath);
	ResultData resultData;

	// Process data
	processInputData(inputData, resultData);

	// Write results
	string outputFilePath = argv[2];
	resultData.writeOutputFile(outputFilePath);
}