// problem_a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Res
{
	Res() { f = 0; s = 0; }
	int f;
	int s;
};

Res Case(std::ifstream& in)
{
	int M = 0;
	in >> M;

	std::vector<int> mush;
	mush.reserve(M);

	for (int i = 0; i < M; i++)
	{
		int mi = 0;
		in >> mi;
		mush.push_back(mi);
	}

	Res r;
	int max = 0;
	for (int i = 0; i + 1 < M; ++i)
	{
		r.f += std::max(0, mush[i] - mush[i+1]);
		max = std::max(max, mush[i] - mush[i + 1]);
	}

	for (int i = 0; i < M-1; ++i)
	{
		r.s += std::min(max, mush[i]);
	}

	return r;
}

void Run(const char* in, const char* out)
{
	std::ifstream input;
	input.open(in);

	int cases = 0;
	input >> cases;

	std::vector<Res> res;
	for (int i = 0; i < cases; ++i)
		res.push_back(Case(input));

	input.close();

	std::ofstream output;
	output.open(out);
	for (int i = 0; i < cases; ++i)
		output << "Case #" << i + 1 << ": " << res[i].f << " " << res[i].s << "\n";
	output.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Run("A-small-attempt0.in", "output");
	return 0;
}

