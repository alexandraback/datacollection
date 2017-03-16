//NTheo 2015

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::vector;

int minimum(vector<vector<bool>>& v, int i, int R, int C, int N)
{
	if (i == R*C)
	{
		int count = 0;
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				count += int(v[r][c]);
		if (count != N)
			return INT_MAX;
		int w = 0;
		for (int r = 1; r < R; r++)
			for (int c = 0; c < C; c++)
				if (v[r][c] && v[r - 1][c])
					w++;
		for (int r = 0; r < R; r++)
			for (int c = 1; c < C; c++)
				if (v[r][c] && v[r][c-1])
					w++;
		return w;
	}
	int r = i / C;
	int c = i % C;
	v[r][c] = false;
	int mini1 = minimum(v, i + 1, R, C, N);
	v[r][c] = true;
	int mini2 = minimum(v, i + 1, R, C, N);
	return std::min(mini1, mini2);
}
int main(int, char**)
{
	for (;;)
	{
		std::string inname;
		std::string outname;
		std::cout << "input file?" << std::endl;
		std::cin >> inname;
		std::cout << "output file?" << std::endl;
		std::cin >> outname;
		if (outname.empty())
			outname = inname.substr(0, inname.length() - 3) +
			std::string(".out");
		std::ifstream input(inname);
		std::ofstream output(outname);
		int T;
		input >> T;
		for (int t = 0; t < T; t++)
		{
			int R, C, N;
			input >> R >> C >> N;
			std::vector<std::vector<bool>> grid;
			for (int r = 0; r < R; r++)
			{
				std::vector<bool> x;
				for (int c = 0; c < C; c++)
					x.push_back(false);
				grid.push_back(x);
			}
			int w = minimum(grid, 0, R, C, N);
			output << "Case #" << (t + 1) << ": " << w << std::endl;
		}
		std::cout << "done" << std::endl;
	}
	return 0;
}