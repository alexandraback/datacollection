/*
 * $File: solve.cc
 * $Date: Sun May 03 00:25:22 2015 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */


#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

int MAX_UNHAPPINESS = 100000000;


int get_ones(int s) {
	int cnt = 0;
	while (s) {
		cnt += (s & 1);
		s >>= 1;
	}
	return cnt;
}

int get_unhappiness(int s, int R, int C) {
	int ret = 0;
	for (int i = 0; i < R * C; i ++) {
		if (((s >> i) & 1) == 0)
			continue;
		int x = i / C,
			y = i % C;
		static const int DIRS[2][2] = {
			{0, 1}, {1, 0}
		};
		for (int d = 0; d < 2; d ++) {
			int dx = DIRS[d][0],
				dy = DIRS[d][1];
			int nx = x + dx,
				ny = y + dy;
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				int j = nx * C + ny;
				if ((s >> j) & 1)
					ret += 1;
			}
		}
	}
	return ret;
}

int solve(FILE *fin) {
	int R, C, N;
	fscanf(fin, "%d%d%d", &R, &C, &N);

	int ret = R * C * 1000;
	for (int s = 0; s < 1 << (R * C); s ++) {
		int nr_ones = get_ones(s);
		if (nr_ones != N)
			continue;
		ret = std::min(ret, get_unhappiness(s, R, C));
	}
	return ret;

}

int main() {
	int T;
	FILE *fin = stdin;
	fscanf(fin, "%d", &T);
	for (int case_id = 1; case_id <= T; case_id ++) {
		std::cout << "Case #" << case_id << ": " << solve(fin) << std::endl;
	}
	return 0;
}


/*
 * vim: syntax=cpp11.doxygen foldmethod=marker foldmarker=f{{{,f}}}
 */
