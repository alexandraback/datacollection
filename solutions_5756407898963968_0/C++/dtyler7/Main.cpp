/* Google Code Jam 2014 - Round Q - Problem A - Magic Trick */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void main(int argv, char** argc){

	if (argv < 2){
		cout << "Missing input file!" << endl;
		return;
	}

	ifstream f(argc[1]);
	ofstream o("out.txt");

	// Number of test cases
	string stemp;
	int itemp;

	getline(f, stemp);
	int T = atoi(stemp.c_str());

	// for each test case
	for (int i = 0; i < T; i++){

		int possible[4] = { 0, 0, 0, 0 };

		// card1
		getline(f, stemp);
		int card1 = atoi(stemp.c_str());

		// layout1
		for (int j = 0; j < 4; j++){
			getline(f, stemp);
			if (j+1 != card1) continue;
			istringstream iss;
			iss.str(stemp);
			for (int k = 0; k < 4; ++k)
			{
				iss >> possible[k];
			}
		}

		// card2
		getline(f, stemp);
		int card2 = atoi(stemp.c_str());

		int match;
		int matches = 0;

		// layout2
		for (int j = 0; j < 4; j++){
			getline(f, stemp);
			if (j+1 != card2) continue;
			istringstream iss;
			iss.str(stemp);
			for (int k = 0; k < 4; ++k)
			{
				iss >> itemp;
				for (int l = 0; l < 4; ++l){
					if (possible[l] == itemp){
						match = itemp;
						++matches;
					}
				}
			}
		}

		// output
		o << "Case #" << i + 1 << ": ";
		if (matches == 0) o << "Volunteer cheated!";
		else if (matches == 1) o << match;
		else o << "Bad magician!";
		o << endl;
	}

	cin.get();

}