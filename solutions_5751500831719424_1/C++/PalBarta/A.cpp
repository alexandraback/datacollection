#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include "gmpxx.h"
typedef mpz_class bigint; 
using namespace std;

// PART I. - INPUT-OUTPUT STRUCTURES

class TestCase 
{
public:
	int N;
	vector<string> s;

	TestCase()
	{
	
	}
	~TestCase()
	{
	
	}
	void readData(ifstream& inputFile)
	{
		inputFile >> N;

		string line;
		getline(inputFile, line);
		
		for (int i=0; i < N; i++)
		{
			getline(inputFile, line);
			s.push_back(line);
		}
	}
};

struct TestCaseResult
{
	int minMoves;
	TestCaseResult()
	{
		
	}

	void printResultToFile(ofstream& outputFile, int index)
	{
		outputFile << "Case #" << index + 1 << ": "; 
		
		if (minMoves == -1)
			outputFile << "Fegla Won";
		else
			outputFile << minMoves;
	}
};

// PART II. - PROBLEM SPECIFIC FUNCTIONS

bool comp (int i,int j) { return (i<j); }

void processTestCase(TestCase& t, TestCaseResult& r)
{
	vector<string> basewords;
	vector<vector<int>> chunks;
	int swi = -1;
	int swl = INT_MAX;
	for (int i = 0; i < t.N; i++)
	{
	// each word
		string word = t.s[i];
		if (word.length() < swl)
		{
			swl = word.length();
			swi = i;
		}
		string baseword = "";
		vector<int> chunksizes;
		char c = '.';
		int ctr = 0;
		for ( int ci = 0; ci < word.length(); ci++)
		{
			if (c == word[ci])
			{
				ctr++;
			}
			else
			{
				baseword.push_back(word[ci]);
				if (ci != 0)
					chunksizes.push_back(ctr);
				ctr = 1;
			}
			c = word[ci];
		}
		chunksizes.push_back(ctr);

		basewords.push_back(baseword);
		chunks.push_back(chunksizes);
	}

	for (int i = 1; i < basewords.size(); i++)
	{
		if (basewords[i-1] != basewords[i])
		{
			r.minMoves = -1;
			return;
		}
	}

	r.minMoves = 0;

	vector<int> refc;
	for (int ci = 0; ci < basewords[0].size(); ci++)
	{
		//vector<int> currc = chunks[i];
		int sum = 0;
		for ( int i = 0; i < chunks.size(); i++)
		{
			sum+=chunks[i].at(ci);
		}
		float rf = sum / t.N;
		int ss = (int)(rf + 0.5);
		refc.push_back(ss);
	}

	for (int i = 0; i < chunks.size(); i++)
	{
		vector<int> currc = chunks[i];

		for ( int ci = 0; ci < currc.size(); ci++)
		{
			int d = abs(refc[ci] - currc[ci]);
			r.minMoves += d;
		}
	}
}

// PART III. - BOILERPLATE CODE FOR INPUT-OUTPUT PROCESSING

class InputData
{
	vector<TestCase> testCases;

private:
	bool readInputFile(const string& inputFilePath);

public:
	InputData(const string& inputFilePath);
	
	int getNumberOfTestCases() { return testCases.size(); }
	TestCase& getTestCase(int index) { return testCases[index];}
};

class ResultData
{
	vector<TestCaseResult> testCaseResults;

public:
	
	bool writeOutputFile(const string& outputFilePath);
	void addResult(TestCaseResult result) { testCaseResults.push_back(result); }
	void addResult(int index, TestCaseResult result) { testCaseResults.insert(testCaseResults.begin() + index, result); }

};

bool ResultData::writeOutputFile(const string& outputFilePath)
{
	ofstream outputFile(outputFilePath);
	
	if (!outputFile.is_open())
		return false;

	for (unsigned int i=0; i < testCaseResults.size(); i++)
	{
		TestCaseResult testCaseResult = testCaseResults[i];
		testCaseResult.printResultToFile(outputFile, i);
		if (i != testCaseResults.size() - 1)
			outputFile << endl;
	}

	return true;
}

InputData::InputData(const string& inputFilePath)
{
	readInputFile(inputFilePath);
}

bool InputData::readInputFile(const string& inputFilePath)
{
	ifstream inputFile(inputFilePath);

	if (!inputFile.is_open())
		return false;

	string line;
	getline(inputFile, line);
	istringstream inputStringStream(line);
	int numOfTestCases = 0;
	inputStringStream >> numOfTestCases;

	for (int i = 0; i < numOfTestCases; i++)
	{
		TestCase testCase;
		testCase.readData(inputFile);
		testCases.push_back(testCase); 
	}

	return true;
}

void processInputData(InputData& inputData, ResultData& resultData)
{
	int numberOfTestCases = inputData.getNumberOfTestCases();
	for (int testCaseIndex = 0; testCaseIndex < numberOfTestCases; testCaseIndex++)
	{
		TestCase testCase = inputData.getTestCase(testCaseIndex);
		TestCaseResult result;
		cout << '\r' << "Test cases processed: " << testCaseIndex << "/" << numberOfTestCases;
		processTestCase(testCase, result);
		resultData.addResult(testCaseIndex, result);
	}
}

void main(int argc, char* argv[])
{
	// Check command line arguments
	if (argc < 3)
	{
		cerr << "Incorrect parameters. Usage: application.exe <input file path> <output file path>" << endl;
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