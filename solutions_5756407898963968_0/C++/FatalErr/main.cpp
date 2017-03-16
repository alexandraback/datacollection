#include <cstdlib>

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <limits>
#include <exception>

#include <cmath>
#include <cstring>
#include <cassert>
#include <ctime>

#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <list>

#define ALL(container) (container).begin(), (container).end()
#define MP std::make_pair
#define SZ(x) int((x).size())

#define X first
#define Y second

typedef long long i64;
typedef unsigned long long u64;

typedef std::pair<int, int> pii;

template<typename t>
inline t sqr(const t x) {
	return x * x;
}

template<typename A, typename B>
A convert(const B &x) {
	A res;
	std::stringstream ss;
	ss << x;
	ss >> res;
	return res;
}

#define FILE_NAME "test"
std::ifstream fin(FILE_NAME ".in");
std::ofstream fout(FILE_NAME ".out");

int main() {
	assert(fin && fout);
	std::ios_base::sync_with_stdio(false);

	int testsCnt;
	fin >> testsCnt;
	for (int testIdx = 1; testIdx <= testsCnt; ++testIdx) {
		int r;
		int array[4][4];
		std::set<int> a;

		fin >> r;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				fin >> array[i][j];

				if (i + 1 == r)
					a.insert(array[i][j]);
			}
		}

		std::set<int> b;

		fin >> r;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				fin >> array[i][j];

				if (i + 1 == r)
					b.insert(array[i][j]);
			}
		}

		std::set<int> intersection;
		std::set_intersection(ALL(a), ALL(b), std::inserter(intersection, intersection.end()));

		fout << "Case #" << testIdx << ": ";
		if (intersection.size() == 1) {
			fout << *intersection.begin() << '\n';
		}
		else if (intersection.size() == 0) {
			fout << "Volunteer cheated!\n";
		}
		else {
			fout << "Bad magician!\n";
		}
	}

	return 0;
}
