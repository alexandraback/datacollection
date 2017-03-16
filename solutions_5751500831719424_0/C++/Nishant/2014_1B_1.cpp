 // CookieClicker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

vector< vector<int>* > COUNTS;
vector< vector<char>* > CHARS;

int GetMin(int j, int N)
{
	int m = 20000;
	for (int i = 0; i < N; ++i)
	{
		int v = (*COUNTS[i])[j];
		if (m > v)
		{
			m = v;
		}
	}

	return m;
}

int GetMax(int j, int N)
{
	int m = 0;
	for (int i = 0; i < N; ++i)
	{
		int v = (*COUNTS[i])[j];
		if (m < v)
		{
			m = v;
		}
	}

	return m;
}

string Solve(int  N)
{
	string ret = "Fegla Won";
	int minVal = 0;

	for (int i = 0; i < N -1; ++i)
	{
		if ((*CHARS[i]).size() != (*CHARS[i+1]).size())
			return ret;
	}

	const vector<int>& curCount = *COUNTS[0];
	const vector<char>& curChar = *CHARS[0];
	for (int j = 0; j < curChar.size(); ++j)
	{
		/*int minCount = GetMin(j, N);
		int maxCount = GetMax(j, N);

		int numMovesMin = 0;
		for (int i = 0; i < N; ++i)
		{
			if ((*CHARS[i])[j] == curChar[j])
				numMovesMin += (*COUNTS[i])[j] - minCount;
			else
				return ret;
		}

		int numMovesMax = 0;
		for (int i = 0; i < N; ++i)
		{
			if ((*CHARS[i])[j] == curChar[j])
				numMovesMax += maxCount - (*COUNTS[i])[j];
			else
				return ret;
		}

		minVal += (numMovesMax > numMovesMin) ? numMovesMin : numMovesMax;*/

		int numMovesMin = 20000;
		for (int i = 0; i < N; ++i)
		{
			if ((*CHARS[i])[j] != curChar[j])
				return ret;
			
			int numMoves = 0;
			for (int k = 0; k < N; ++k)
			{
				numMoves += abs((*COUNTS[k])[j] - (*COUNTS[i])[j]);
			}
			if (numMovesMin > numMoves)
				numMovesMin = numMoves;
		}

		minVal += numMovesMin;
	}

	ret = std::to_string(minVal);

	return ret;
}

int _tmain(int argc, _TCHAR* argv [])
{
	ifstream ifs;
	ofstream ofs;
	ifs.open("c:\\GCJ_Inputs\\2014_1B_1\\input.in", ifstream::in);
	ofs.open("c:\\GCJ_Inputs\\2014_1B_1\\output.out", ifstream::out);

	if (!ifs)
	{
		cout << "Error reading input" << endl;
		return 0;
	}

	if (!ofs)
	{
		cout << "Error opening output" << endl;
		return 0;
	}

	cout << "STARTING" << endl;

	unsigned int numTests = 0;
	ifs >> numTests;

	for (unsigned int t = 0; t < numTests; ++t)
	{
		cout << "..";

		int N = 0;
		ifs >> N;

		COUNTS.clear();
		CHARS.clear();
		for (int i = 0; i < N; ++i)
		{
			string s;
			ifs >> s;
			vector<int>* newCount = new vector<int>();
			vector<char>* newChars = new vector<char>();
			COUNTS.push_back(newCount);
			CHARS.push_back(newChars);
			for (int j = 0; j < s.length(); ++j)
			{
				int count = 0;
				char c = s[j];
				CHARS[i]->push_back(c);
				while (s[j] == c && j<s.length())
				{
					++count;
					++j;
				}

				if (j != s.length())
					--j;

				COUNTS[i]->push_back(count);
			}

		}

		string ret = Solve(N);
		ofs << "Case #" + std::to_string(t + 1) + ": ";
		ofs << ret << endl;
	}

	cout << endl;
	cout << "COMPLETE" << endl;

	ofs.close();
	ifs.close();

	return 0;
}


