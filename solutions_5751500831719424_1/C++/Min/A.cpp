// CodeJam 2014
// Autor: Benjamín de la Fuente Ranea

#include "BigIntegerLibrary.hh"

#include <stdarg.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <math.h>

using namespace std;

#define FILE_INPUT	"A-large"

bool allNotEmpty(const vector<string>& strings)
{
	for (unsigned i = 0; i < strings.size(); ++i)
	{
		if (strings[i].empty())
			return false;
	}

	return true;
}

bool allEmpty(const vector<string>& strings)
{
	for (unsigned i = 0; i < strings.size(); ++i)
	{
		if (!strings[i].empty())
			return false;
	}

	return true;
}

unsigned allSameChar(const vector<string>& strings, char _curChar)
{
	unsigned diff = 0;
	for (unsigned i = 0; i < strings.size(); ++i)
	{
		if (_curChar != strings[i][0])
			++diff;
	}

	return diff;
}

void removeFrist(vector<string>& strings)
{
	for (unsigned i = 0; i < strings.size(); ++i)
		strings[i].erase(strings[i].begin());
}

void removeFristChar(vector<string>& strings, char _c)
{
	for (unsigned i = 0; i < strings.size(); ++i)
	{
		if (strings[i][0] == _c)
			strings[i].erase(strings[i].begin());
	}
}

bool changeChar(const vector<string>& strings, char _lastChar)
{
	for (unsigned i = 0; i < strings.size(); ++i)
	{
		if (!strings[i].empty() && strings[i][0] == _lastChar)
			return false;
	}

	return true;
}

int makeMoves(vector<string>& strings)
{
	int moves = 0;
	unsigned i = 0;
	char lastChar = strings[0][0];
	bool bCanMove = false;
	while (bCanMove || allNotEmpty(strings))
	{
		const unsigned diff = allSameChar(strings, lastChar);
		if (diff == strings.size())
			return -1;
		else if (diff == 0)
		{
			bCanMove = true;
			removeFrist(strings);
		}
		else if (bCanMove)
		{
			moves += min(diff, strings.size() - diff);
			removeFristChar(strings, lastChar);
		}
		else
			return -1;

		if (!strings[0].empty() && changeChar(strings, lastChar))
		{
			lastChar = strings[0][0];
			bCanMove = false;
		}
		else if (allEmpty(strings))
			return moves;
	}

	if (allEmpty(strings))
		return moves;
	else
		return -1;
}

void main()
{
	freopen(FILE_INPUT".in", "r", stdin);
	freopen(FILE_INPUT".out", "w", stdout);

	unsigned numCases;
	scanf("%d\n", &numCases);
	for (unsigned j = 1; j <= numCases; ++j)
	{
		unsigned N;
		scanf("%d\n", &N);

		vector<string> strings;
		strings.reserve(N);
		for (unsigned i = 0; i < N; ++i)
		{
			char str[101];
			scanf("%[^\n]\n", str);
			strings.push_back(str);
		}

		const int moves = makeMoves(strings);
		if (moves >= 0)
			printf("Case #%d: %d\n", j, moves);
		else
			printf("Case #%d: Fegla Won\n", j);
	}
}
