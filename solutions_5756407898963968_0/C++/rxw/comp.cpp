#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream in("A-small-attempt1.IN", ifstream::in);
	ofstream out("out", ifstream::out);

	int numTests = 0;
	in >> numTests;

	//vector<int> row1, row2;
	int row1[4];
	int row2[4];

	for (int i = 0; i < numTests; ++i)
	{
		int row;
		in >> row;
		for (int j = 0; j < ((row - 1) * 4); ++j) {
			int a;
			in >> a;
		}
		for (int j = 0; j < 4; ++j) {
			int a;
			in >> a;
			row1[j] = a;
		}
		for (int j = 0; j < (4 - row) * 4; ++j) {
			int a;
			in >> a;
		}

		in >> row;
		for (int j = 0; j < ((row - 1) * 4); ++j) {
			int a;
			in >> a;
		}
		for (int j = 0; j < 4; ++j) {
			int a;
			in >> a;
			row2[j] = a;
		}
		for (int j = 0; j < (4 - row) * 4; ++j) {
			int a;
			in >> a;
		}

		sort(row1, row1 + 4);
		sort(row2, row2 + 4);

		vector<int> intersection(4);
		vector<int>::iterator it;
		it = set_intersection(row1, row1 + 4, row2, row2 + 4, intersection.begin());
		intersection.resize(it - intersection.begin());

		out << "Case #" << i + 1 << ": ";
		if(intersection.empty()) {
			out << "Volunteer cheated!";
		}
		else if(intersection.size() == 1) {
			out << intersection[0];
		}
		else {
			out << "Bad magician!";
		}
		out << endl;
	}

	return 0;
}