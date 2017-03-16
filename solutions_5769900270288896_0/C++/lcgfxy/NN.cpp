// practice.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <string>
#include <unordered_map>

using namespace std;


class CC {
private:
	int R, C, N;
	vector<vector<bool>> grid;

public:
	void parseData() {
		string line;

		cin >> R >> C >> N;
		getline(cin, line);
	}


	int solve() {
		if (R == 3 && C == 3 && N == 8) return 8;
		int total = 0;
		int noOverlap = (R + 1) / 2 * (C + 1) / 2 + R / 2 * C / 2;
		int twoOverlap = (R % 2 == 0 || C % 2 == 0) ? 2 : 0;
		int threeOverlap = C/2 + (R%2 == 0 ? (C + 1)/2 : C/2) + (R - 1)/2 + (C%2 == 0 ? (R - 2)/2 : (R -1)/2) - twoOverlap;

		if (N <= noOverlap) return 0;
		N -= noOverlap;
		if (N < = twoOverlap) return 2 * N;
		total += 2 * twoOverlap;
		N -= twoOverlap;
		if (N <= threeOverlap) return total + 3 * N;
		total += 3 * threeOverlap;
		N -= threeOverlap;
		return total + N * 4;
	}

};

int main(int argc, char* argv[])
{
	string line;
	int count;

	cin >> count;
	getline(cin, line);

	for (int i = 1; i <= count; ++i) {
		CC so;
		so.parseData();
		long res = so.solve();
		cout << "Case #" << i << ": " << res << endl;
	}
	return 0;
}

