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

	int lineWidth = lines[0].size();
	for (int i = 0; i < lineWidth; ++i)
	{
		for (int j = 1; j < lines.size(); ++j)
		{
			if (lines[j][i].c != lines[j-1][i].c)
				return -1;
		}		
	}

	int minimumCount = 0;
	for (int i = 0; i < lineWidth; ++i)
	{
		int maxmimumCharacters = 0;
		for (int j = 0; j < lines.size(); ++j)
		{
			maxmimumCharacters = max(maxmimumCharacters, lines[j][i].count);
		}

		int localMimimum = -1;
		for (int j = 1; j <= maxmimumCharacters; ++j)
		{
			int minimum = 0;
			for (int line = 0; line < lines.size(); ++line)
			{
				minimum += abs(lines[line][i].count - j);
			}
			if (localMimimum < 0)
				localMimimum = minimum;
			else
				localMimimum = min(localMimimum, minimum);
		}

		minimumCount += localMimimum;
	}

	return minimumCount;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream inputFile("A-large.in"/*"1.txt"*/);
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

