#include "stdafx.h"

void readSet(istream& is, int& row, set<int>& set) {
	is >> row;
	for (int y = 1; y <= 4; ++y)
	for (int x = 1; x <= 4; ++x) {
		int n;
		is >> n;
		if (y == row)
			set.insert(n);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input("problem.in");
	ofstream output("problem.out");

	size_t n;
	input >> n;

	for (size_t i = 1; i <= n; ++i) {
		int row1, row2;
		set<int> set1, set2, result;

		readSet(input, row1, set1);
		readSet(input, row2, set2);

		set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.begin()));

		output << "Case #" << i << ": ";

		if (result.empty()) {
			output << "Volunteer cheated!";
		} else if (result.size() == 1) {
			output << *result.begin();
		} else {
			output << "Bad magician!";
		}

		output << endl;
	}

	return 0;
}

