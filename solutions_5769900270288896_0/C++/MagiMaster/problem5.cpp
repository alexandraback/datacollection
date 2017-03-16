#include "problem5.h"

#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <array>
using namespace std;

void problem5(string filename) {
	ifstream infile(filename + ".in");
	ofstream outfile(filename + ".out");

	int t;
	infile >> t;

	for(int z = 1; z <= t; ++z) {
		int r, c, t;
		infile >> r >> c >> t;

		vector<vector<int>> grid(r, vector<int>(c, 0));

		if(t <= (r*c + 1) / 2) {
			outfile << "Case #" << z << ": " << 0 << endl;
			continue;
		}

		t -= 4;
		grid[0][0] = 1;
		grid[0][c - 1] = 1;
		grid[r - 1][0] = 1;
		grid[r - 1][c - 1] = 1;

		int p = 0;
		for(int y = 0; y < r && p < t; ++y) {
			for(int x = 0; x < c && p < t; ++x) {
				if(grid[y][x] == 0) {
					grid[y][x] = 1;
					++p;
				}
			}
		}

		int u;
		while(true) {
			int best = 99, fromx, fromy, tox, toy;

			for(int y1 = 0; y1 < r; ++y1) {
				for(int x1 = 0; x1 < c; ++x1) {
					if(grid[y1][x1] != 0)
						continue;

					for(int y2 = 0; y2 < r; ++y2) {
						for(int x2 = 0; x2 < c; ++x2) {
							if(grid[y2][x2] != 1)
								continue;

							grid[y2][x2] = 0;
							
							u = 0;
							if(x2 > 0) u -= grid[y2][x2 - 1];
							if(y2 > 0) u -= grid[y2 - 1][x2];
							if(x2 < c - 1) u -= grid[y2][x2 + 1];
							if(y2 < r - 1) u -= grid[y2 + 1][x2];
							if(x1 > 0) u += grid[y1][x1 - 1];
							if(y1 > 0) u += grid[y1 - 1][x1];
							if(x1 < c - 1) u += grid[y1][x1 + 1];
							if(y1 < r - 1) u += grid[y1 + 1][x1];

							grid[y2][x2] = 1;

							if(u < best) {
								best = u;
								fromx = x2;
								fromy = y2;
								tox = x1;
								toy = y1;
							}
						}
					}
				}
			}

			if(best >= 0)
				break;

			grid[toy][tox] = 1;
			grid[fromy][fromx] = 0;
		}

		u = 0;
		for(int y = 1; y < r; ++y) {
			for(int x = 0; x < c; ++x)
				u += grid[y][x] * grid[y - 1][x];
		}
		for(int y = 0; y < r; ++y) {
			for(int x = 1; x < c; ++x)
				u += grid[y][x] * grid[y][x - 1];
		}

		outfile << "Case #" << z << ": " << u << endl;
	}
}