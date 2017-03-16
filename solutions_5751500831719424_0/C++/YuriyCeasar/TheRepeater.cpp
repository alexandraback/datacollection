// TheRepeater.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Character
{
	char c;
	int count;
};

typedef vector<Character> Line;

vector<string> textLines;

int Solve()
{
	vector<Line> lines;
	for (int i = 0; i < textLines.size(); ++i)
	{
		Line line;

		Character c;
		c.c = 0;
		c.count = 0;
		for (int j = 0; j < textLines[i].size(); ++j)
		{
			if (c.c == 0)
			{
				c.c = textLines[i][j];
				c.count++;
			}
			else
			{
				if (textLines[i][j] == c.c)
					c.count++;
				else
				{
					line.push_back(c);
					c.c = textLines[i][j];
					c.count = 1;
				}
			}
		}
		line.push_back(c);

		lines.push_back(line);
	}

	for (int i = 1; i < lines.size(); ++i)
	{
		if (lines[i].size() != lines[i-1].size())
			return -1;
	}

	for (int i = 0; i < lines[0].size(); ++i)
	{
		if (lines[0][i].c != lines[1][i].c)
			return -1;
	}

	int minimumCount = 0;
	for (int i = 0; i < lines[0].size(); ++i)
	{
		minimumCount += abs(lines[1][i].count - lines[0][i].count);
	}

	return minimumCount;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream inputFile("A-small-attempt1.in"/*"1.txt"*/);
	if (!inputFile.is_open())
	{
		cerr << "Error reading file" << endl;
		return 1;
	}

	int T;
	inputFile >> T;

	ofstream outputFile("output.txt");
	ostream &output = outputFile;//cout;
	for (int i = 0; i < T; ++i)
	{
		int N;
		textLines.clear();
		inputFile >> N;

		for (int j = 0; j < N; ++j)
		{
			string line;
			inputFile >> line;
			textLines.push_back(line);
		}

		int solution = Solve();
		output << "Case #" << (i+1) << ": ";
		if (solution < 0)
			output << "Fegla Won";
		else
			output << solution;
		output << endl;
	}

	return 0;
}

