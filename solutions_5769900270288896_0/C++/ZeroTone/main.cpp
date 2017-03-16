#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <CImg.h>
using namespace std;
using namespace cimg_library;

struct TestCase {
	int r, c, n;
};

std::vector<TestCase> load(const std::string& fname) {
	std::ifstream fp(fname);
	std::vector<TestCase> res;
	int cases;
	fp >> cases;
	for (int i = 0; i < cases; i++) {
		TestCase c;
		fp >> c.r;
		fp >> c.c;
		fp >> c.n;
		res.push_back(c);
	}
	return res;
}


bool getgrid(const CImg<bool>& grid, int x, int y) {
	if (x < 0 || x >= grid.width()) return false;
	if (y < 0 || y >= grid.height()) return false;
	return grid(x, y);
}

int fillRow(CImg<bool>& grid, int y, int limit) {
	int placed = 0;
	for (int i = 0; i < grid.width() && placed < limit; i++) {
		if (!grid(i, y)) {
			++placed;
			grid(i, y) = true;
		}
	}
	return placed;
}

int fillCol(CImg<bool>& grid, int x, int limit) {
	int placed = 0;
	for (int i = 0; i < grid.height() && placed < limit; i++) {
		if (!grid(x, i)) {
			++placed;
			grid(x, i) = true;
		}
	}
	return placed;
}

long long countUnhappiness(const CImg<bool>& grid) {
	long long unhappiness = 0;
	for (int y = 0; y < grid.height(); y++) {
		for (int x = 0; x < grid.width(); x++) {
			if (!grid(x, y))
				continue;
			if (getgrid(grid, x - 1, y))
				++unhappiness;
			if (getgrid(grid, x, y - 1))
				++unhappiness;
		}
	}
	return unhappiness;
}

template <typename Fn>
long long solveFor(const TestCase& cs, Fn comparator) {
	CImg<bool> grid(cs.c, cs.r);
	grid.fill(false);

	// Place chessboard
	int placed = 0;
	for (int y = 0; y < grid.height(); y++) {
		for (int x = 0; x < grid.width(); x++) {
			if (comparator(x % 2, y % 2))
				continue;
			++placed;
			grid(x, y) = true;
			if (placed >= cs.n)
				return 0;
		}
	}

	long long unhappiness = 0;
	int ilimit = min(grid.width(), grid.height());
	for (int i = 0; placed < cs.n && i < ilimit; i++) {
		placed += fillRow(grid, i, cs.n - placed);
		placed += fillRow(grid, grid.height() - i - 1, cs.n - placed);
		placed += fillCol(grid, i, cs.n - placed);
		placed += fillCol(grid, grid.width() - i - 1, cs.n - placed);
	}

	return countUnhappiness(grid);
}

vector<unsigned> allPermutations(int bits, int limit) {
	if (bits == 0)
		return vector<unsigned>(limit);

	assert(bits <= 32);
	unsigned int v = 0;
	for (int i = 0; i < bits; i++) {
		v <<= 1;
		v |= 1;
	}
	unsigned base = v;

	unsigned int limitPow2 = (unsigned int)pow(2, limit);

	vector<unsigned> res;
	unsigned w = v;
	do {
		v = w;
		res.push_back(w);
		unsigned int t = (v | (v - 1)) + 1;
		w = v == 0 ? 0 : t | ((((t & -t) / (v & -v)) >> 1) - 1);
	} while (w < limitPow2);
	return res;
}

long long solveBruteforce(const TestCase& cs) {
	CImg<bool> grid(cs.c, cs.r);
	grid.fill(false);

	long long unhappiness = 10000000;
	auto perm = allPermutations(cs.n, cs.r * cs.c);
	for (unsigned perm : perm) {
		for (int y = 0; y < cs.r; y++) {
			for (int x = 0; x < cs.c; x++) {
				int i = y * cs.c + x;
				bool isset = ((perm >> i) & 1) == 1;
				grid(x, y) = isset;
			}
		}
		unhappiness = min(unhappiness, countUnhappiness(grid));
	}
	return unhappiness;
}

std::string solve(TestCase& cs) {
	long long a = solveFor(cs, [](int a, int b) { return a == b;  });
	long long b = solveFor(cs, [](int a, int b) { return a != b;  });
	long long c = solveBruteforce(cs);
	return to_string(c);
	return to_string(min(a, b));
}

int main(int argc, const char *argv[]) {
	auto cases = load("B-small-attempt1.in");
	std::ofstream fp("B-small-attempt1.out");
	//for (int i = 0; i < 1000; i++)
	//	std::cout << 100000 - i << " ";

	int i = 1;
	for (auto it = cases.begin(); it != cases.end(); ++it, ++i) {
		auto r = solve(*it);
		fp << "Case #" << i << ": " << r << std::endl;
	}

	return 0;
}

