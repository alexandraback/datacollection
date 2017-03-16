#include "stdafx.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <list>
#include <memory>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input("C:/users/sebastien/Downloads/A-small-attempt0.in");
	ofstream output("C:/users/sebastien/Downloads/output.txt");

	int T;
	input >> T;

	for (int test = 1; test <= T; ++test) {
		cout << "test " << test << "\n";
		output << "Case #" << test << ": ";
		int answ1;
		input >> answ1;
		set<int> possible;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				int c;
				input >> c;
				if (i == answ1 - 1) {
					possible.insert(c);
					cout << "\tadding " << c << "\n";
				}
			}
		}
		int answ2;
		input >> answ2;
		set<int> possible2;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				int c;
				input >> c;
				if (i == answ2 - 1) {
					if (possible.find(c) != possible.end()) {
						possible2.insert(c);
					}
				}
			}
		}
		if (possible2.size() == 0) {
			output << "Volunteer cheated!";
		}
		else if (possible2.size() > 1) {
			output << "Bad magician!";
		}
		else {
			output << *possible2.begin();
		}
		output << "\n";
	}

	output.close();

	{
		cout << "DONE\n";
		int _;
		cin >> _;
	}

	return 0;
}
